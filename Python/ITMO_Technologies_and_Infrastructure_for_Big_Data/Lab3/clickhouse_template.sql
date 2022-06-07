#создаём таблицу транзакций
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

#Создаём распределённую таблицу транзакций 

CREATE TABLE ajamoldin_338693.distributed_transactions ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.transactions
ENGINE = Distributed(
	kube_clickhouse_cluster,
	ajamoldin_338693,
	transactions,
	xxHash64(datetime)
)


exit


cat shared-data/clickhouse_data/transactions_12M.parquet | clickhouse-client --host=clickhouse-8.clickhouse.clickhouse --user=ajamoldin_338693 --password=P7YJ5PqhpR --query="INSERT INTO ajamoldin_338693.distributed_transactions FORMAT Parquet"
--------------------------------------------------------------------------------------------------
# По дням
#создаем представление среднего количества входящих транзакций
CREATE MATERIALIZED VIEW ajamoldin_338693.in_avg_amount ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_in, date)
POPULATE
AS SELECT
user_id_in,
avg(amount) AS avg_amount_in,
formatDateTime(datetime, '%d-%m-%G') AS 
FROM ajamoldin_338693.
GROUP BY user_id_in, date


#создаем распределённую таблицу среднего количества входящих транзакций
#по сути это количество входящих транзакций для каждого юзера за опр. дату
CREATE TABLE ajamoldin_338693.distr_in_avg_amount ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.in_avg_amount
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, in_avg_amount)

###создаем представление среднего количества исходящих транзакций
CREATE MATERIALIZED VIEW ajamoldin_338693.out_avg_amount ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_out, date)
POPULATE
AS SELECT
    user_id_out,
    avg(amount) AS avg_amount_out,
    formatDateTime(datetime, '%d-%m-%G') AS date
FROM ajamoldin_338693.transactions
GROUP BY
    user_id_out,
    date

SELECT user_id_in as user_id, avg_amount_in, avg_amount_out, date_in, date_out FROM (SELECT
user_id_in,
avg(amount) AS avg_amount_in,
formatDateTime(datetime, '%d-%m-%G') AS date_in
FROM ajamoldin_338693.transactions
GROUP BY user_id_in, date_in) t1 INNER JOIN (SELECT
    user_id_out,
    avg(amount) AS avg_amount_out,
    formatDateTime(datetime, '%d-%m-%G') AS date_out
FROM ajamoldin_338693.transactions
GROUP BY
    user_id_out,
    date_out) t2 ON t1.user_id_in=t2.user_id_out

#создаем распределённую таблицу среднего количества исходящих транзакций
#по сути это количество исходящих транзакций для каждого юзера за опр. дату
CREATE TABLE ajamoldin_338693.distr_out_avg_amount ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.out_avg_amount
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, out_avg_amount)
--------------------------------------------------------------------------------------------------
## по месяцам
#создаем представление среднего количества входящих транзакций
CREATE MATERIALIZED VIEW ajamoldin_338693.in_avg_amount_m ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_in, date)
POPULATE
AS SELECT
user_id_in,
avg(amount) AS avg_amount,
formatDateTime(datetime, '%m-%G') AS date
FROM ajamoldin_338693.transactions
GROUP BY user_id_in, date LIMIT 5


#создаем распределённую таблицу среднего количества входящих транзакций
#по сути это количество входящих транзакций для каждого юзера за опр. дату
CREATE TABLE ajamoldin_338693.distr_in_avg_amount_m ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.in_avg_amount_m
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, in_avg_amount_m)

-------------------------------------------------------------------------------------

##
CREATE MATERIALIZED VIEW ajamoldin_338693.out_avg_amount_m ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_out, date)
POPULATE
AS SELECT
    user_id_out,
    avg(amount) AS avg_amount,
    formatDateTime(datetime, '%m') AS date
FROM ajamoldin_338693.transactions
GROUP BY user_id_out, date

CREATE TABLE ajamoldin_338693.distr_out_avg_amount_m ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.out_avg_amount_m
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, out_avg_amount_m)

------------------------------------------------------------
#sums for incoming and outcoming transactions by months for each user
CREATE MATERIALIZED VIEW ajamoldin_338693.in_sum_amount_m ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_in, date)
POPULATE
AS SELECT
    user_id_in,
    sum(amount) AS sum_amount,
    formatDateTime(datetime, '%m') AS date
FROM ajamoldin_338693.transactions
GROUP BY user_id_in, date

CREATE TABLE ajamoldin_338693.distr_in_sum_amount_m ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.in_sum_amount_m
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, in_sum_amount_m)

##
CREATE MATERIALIZED VIEW ajamoldin_338693.out_sum_amount_m ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id_out, date)
POPULATE
AS SELECT
    user_id_out,
    sum(amount) AS sum_amount,
    formatDateTime(datetime, '%m') AS date
FROM ajamoldin_338693.transactions
GROUP BY user_id_out, date

CREATE TABLE ajamoldin_338693.distr_out_sum_amount_m ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.out_sum_amount_m
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, out_sum_amount_m)

------------------------------------------------------------------------------------------------------------
NEW!NEW!NEW!

//Block by day
--------------
CREATE MATERIALIZED VIEW ajamoldin_338693.avg_day ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id, date)
POPULATE
AS SELECT
    user_id_in AS user_id,
    avg(avg_amount_in),
    avg(avg_amount_out),
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        avg(amount) AS avg_amount_in,
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
        avg(amount) AS avg_amount_out,
        formatDateTime(datetime, '%d-%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON t1.user_id_in = t2.user_id_out
GROUP BY date, user_id

CREATE TABLE ajamoldin_338693.distr_avg_day ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.avg_day
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, avg_day, xxHash64(user_id))

#Block by months
-----------------
CREATE MATERIALIZED VIEW ajamoldin_338693.avg_month ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id, date)
POPULATE
AS SELECT
    user_id_in AS user_id,
    avg(avg_amount_in),
    avg(avg_amount_out),
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        avg(amount) AS avg_amount_in,
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
        avg(amount) AS avg_amount_out,
        formatDateTime(datetime, '%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON t1.user_id_in = t2.user_id_out
GROUP BY date, user_id

CREATE TABLE ajamoldin_338693.distr_avg_month ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.avg_month
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, avg_month, xxHash64(user_id))

//sums
--------
CREATE MATERIALIZED VIEW ajamoldin_338693.sum_month ON CLUSTER kube_clickhouse_cluster
ENGINE = AggregatingMergeTree()
ORDER BY (user_id, date)
POPULATE
AS SELECT
    user_id_in AS user_id,
    sum(sum_amount_in),
    sum(sum_amount_out),
    date_in AS date
FROM
(
    SELECT
        user_id_in,
        sum(amount) AS sum_amount_in,
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
        sum(amount) AS sum_amount_out,
        formatDateTime(datetime, '%m-%G') AS date_out
    FROM ajamoldin_338693.transactions
    GROUP BY
        user_id_out,
        date_out
) AS t2 ON t1.user_id_in = t2.user_id_out
GROUP BY date, user_id

CREATE TABLE ajamoldin_338693.distr_sum_month ON CLUSTER kube_clickhouse_cluster AS ajamoldin_338693.sum_month
ENGINE = Distributed(kube_clickhouse_cluster, ajamoldin_338693, sum_month, xxHash64(user_id))