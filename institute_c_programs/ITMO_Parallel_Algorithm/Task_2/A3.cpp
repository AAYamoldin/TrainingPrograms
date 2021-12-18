#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <omp.h>

using namespace std;


double** double_array(int n)
{
	double** matrix = new double*[n]; //выделяем память под двумерный массив
	for (int i = 0; i < n; i++)
		matrix[i] = new double[n]; //выделяем память под одномерные массивы, содержащиеся в двумерном массиве
	return matrix;
}

void free_array(double** matrix, int n) // высвобождаем память
{
	for (int i = 0; i < n; i++)
		delete[] matrix[i];
	delete[] matrix;
}

void rand_init_matrix(double** matrix, int n) //заполняем матрицу случайными числами
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = rand();
}

void zero_init_matrix(double** matrix, int n)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			matrix[i][j] = 0.0;
}

bool is_arrays_equal(double** first, double** second, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
        {
            if(first[i][j] != second[i][j])
                return false;

        }

    return true;
}

void print_matrix(double** matrix, int n)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }
}

int main(int argc, char** argv)
{
	const int N = atoi(argv[1]);
	double** A, **B, **C, **C_test;

    // выделение памяти
	A = double_array(N);
	B = double_array(N);
	C = double_array(N);
	C_test = double_array(N);

	rand_init_matrix(A, N);
	rand_init_matrix(B, N);
	zero_init_matrix(C, N);
	zero_init_matrix(C_test, N);
	double t;

    // Перемножаем матрицы в разном порядке
    cout << "ijk multiplication" << endl;

	t = omp_get_wtime();//для подсчета эффективности перемножаем однопотоково
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			for (int k = 0; k < N; k++)
				C_test[i][j] += A[i][k] * B[k][j];
	double t_ijk = omp_get_wtime() - t;

    for(int n_threads = 1; n_threads <= 12; n_threads++)
    {
        zero_init_matrix(C, N);
        int i, j, k;
        t = omp_get_wtime();
        #pragma omp parallel for num_threads(n_threads) private(i, j, k) //Запускаем параллельную секцию
        // private - директива частных данных. Эти данные могут изменяться только потоком
            for (i = 0; i < N; i++)
                for (j = 0; j < N; j++)
                    for (k = 0; k < N; k++)
                        C[i][j] += A[i][k] * B[k][j];
        double t_ijk_parallel = omp_get_wtime() - t;

        if(!is_arrays_equal(C, C_test, N))
            cout << "not equal, ";
        cout << "Threads" << n_threads << " Time " << t_ijk_parallel << " seconds, efficiency: " << t_ijk / t_ijk_parallel << endl;
    }

    cout << "jki multiplication" << endl;

	zero_init_matrix(C, N);
	t = omp_get_wtime();
	for (int j = 0; j < N; j++)
		for (int k = 0; k < N; k++)
			for (int i = 0; i < N; i++)
				C[i][j] += A[i][k] * B[k][j];
	double t_jki = omp_get_wtime() - t;//для подсчета эффективности перемножаем однопотоково

    for(int n_threads = 1; n_threads <= 12; n_threads++)
    {
        int i, j, k;
        zero_init_matrix(C, N);
        t = omp_get_wtime();
        #pragma omp parallel for num_threads(n_threads) private(i, j, k)
            for (j = 0; j < N; j++)
                for (k = 0; k < N; k++)
                    for (i = 0; i < N; i++)
                        C[i][j] += A[i][k] * B[k][j];
        double t_jki_parallel = omp_get_wtime() - t;

        if(!is_arrays_equal(C, C_test, N))
            cout << "not equal, ";
        cout << "Threads " << n_threads << "Time " << t_jki_parallel << " seconds, efficiency: " << t_jki / t_jki_parallel << endl;
    }

    cout << "ikj multiplication" << endl;

	zero_init_matrix(C, N);
	t = omp_get_wtime();
	for (int i = 0; i < N; i++)
		for (int k = 0; k < N; k++)
			for (int j = 0; j < N; j++)
				C[i][j] += A[i][k] * B[k][j];
	double t_ikj = omp_get_wtime() - t;//для подсчета эффективности перемножаем однопотоково

    for(int n_threads = 1; n_threads <= 12; n_threads++)
    {
        int i, j, k;
        zero_init_matrix(C, N);
        t = omp_get_wtime();
        #pragma omp parallel for num_threads(n_threads) private(i, j, k)
            for (i = 0; i < N; i++)
                for (k = 0; k < N; k++)
                    for (j = 0; j < N; j++)
                        C[i][j] += A[i][k] * B[k][j];
        double t_ikj_parallel = omp_get_wtime() - t;

        if(!is_arrays_equal(C, C_test, N))
            cout << "not equal, ";
        cout << "Threads " << n_threads << " Time " << t_ikj_parallel << " seconds, efficiency: " << t_ikj / t_ikj_parallel << endl;
    }
// освобождение памяти
	free_array(A, N);
	free_array(B, N);
	free_array(C, N);
    free_array(C_test, N);
	return 0;
}