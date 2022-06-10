/*создаём таблицу транзакций*/
CREATE TABLE ajamoldin_338693.transactions ON CLUSTER kube_clickhouse_cluster
(
    user_id_out Int64,
    user_id_in Int64,
    important Int64,
    amount Float64,
    datetime DateTime
)
ENGINE = MergeTree()
PARTITION BY toYYYYMM(datetime)
ORDER BY (user_id_out, user_id_in, amount)

/*Создаём распределённую таблицу транзакций*/ 

CREATE TABLE ajamoldin_338693.distributed_transactions ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.transactions
ENGINE = Distributed(
	kube_clickhouse_cluster,
	ajamoldin_338693,
	transactions,
	xxHash64(datetime)
)

/*Заполняем её*/
/*cat shared-data/clickhouse_data/transactions_12M.parquet | clickhouse-client --host=clickhouse-8.clickhouse.clickhouse --user=ajamoldin_338693 --password=P7YJ5PqhpR --query="INSERT INTO ajamoldin_338693.distributed_transactions FORMAT Parquet"
*/

/*Среднее ин/аут за день*/

CREATE MATERIALIZED VIEW ajamoldin_338693.avg_day_debug ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree
ORDER BY (user_id, date) POPULATE AS
SELECT
    user_id_in AS user_id,
    avg_amount_in AS avg_in,
    avg_amount_out AS avg_out,
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        avgState(amount) AS avg_amount_in,
        formatDateTime(datetime, '%d-%m-%G') AS date_in
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_in,
        date_in
) AS t1
INNER JOIN
(
    SELECT
        user_id_out,
        avgState(amount) AS avg_amount_out,
        formatDateTime(datetime, '%d-%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON (t1.user_id_in = t2.user_id_out) AND (t1.date_in = t2.date_out)


/*view*/

SELECT
    user_id,
    avgMerge(avg_in) AS avg_in,
    avgMerge(avg_out) AS avg_out,
    date
FROM ajamoldin_338693.avg_day_debug
GROUP BY (user_id, date)
LIMIT 5

CREATE TABLE ajamoldin_338693.distr_avg_day_debug ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.avg_day_debug
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, avg_day_debug, xxHash64(user_id))

/*Среднее ин/фут за месяц*/
CREATE MATERIALIZED VIEW ajamoldin_338693.avg_month_debug ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree
ORDER BY (user_id, date) POPULATE AS
SELECT
    user_id_in AS user_id,
    avg_amount_in AS avg_in,
    avg_amount_out AS avg_out,
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        avgState(amount) AS avg_amount_in,
        formatDateTime(datetime, '%m-%G') AS date_in
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_in,
        date_in
) AS t1
INNER JOIN
(
    SELECT
        user_id_out,
        avgState(amount) AS avg_amount_out,
        formatDateTime(datetime, '%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON (t1.user_id_in = t2.user_id_out) AND (t1.date_in = t2.date_out)

/*view*/
SELECT
    user_id,
    avgMerge(avg_in) AS avg_in,
    avgMerge(avg_out) AS avg_out,
    date
FROM ajamoldin_338693.avg_month_debug
GROUP BY (user_id, date)
LIMIT 5

CREATE TABLE ajamoldin_338693.distr_avg_month_debug ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.avg_month_debug
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, avg_month_debug)

/*сумма за месяц*/
CREATE MATERIALIZED VIEW ajamoldin_338693.sum_month_debug ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id, date)
POPULATE
AS SELECT
    user_id_in AS user_id,
    sum_amount_in,
    sum_amount_out,
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        sumState(amount) AS sum_amount_in,
        formatDateTime(datetime, '%m-%G') AS date_in
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_in,
        date_in
) AS t1
INNER JOIN
(
    SELECT
        user_id_out,
        sumState(amount) AS sum_amount_out,
        formatDateTime(datetime, '%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON (t1.user_id_in = t2.user_id_out) AND (t1.date_in = t2.date_out)

/*view*/
SELECT
    user_id,
    sumMerge(sum_amount_in) AS sum_in,
    sumMerge(sum_amount_out) AS sum_out,
    date
FROM ajamoldin_338693.sum_month_debug
GROUP BY (user_id, date)
LIMIT 5

CREATE TABLE ajamoldin_338693.distr_sum_month_debug ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.sum_month_debug
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, sum_month_debug)