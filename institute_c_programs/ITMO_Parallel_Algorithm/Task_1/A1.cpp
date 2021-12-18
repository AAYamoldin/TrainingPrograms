#include <iostream>
#include <omp.h>
#include <cstdlib>
#include <stdio.h>
using namespace std;

int main(int argc, char* argv[]) {

    int size = atoi(argv[1]); // определили размер вектора
    double* arr = new double[size]; // выделили память под вектор

    for (int i = 0; i < size; i++)
    {
        arr[i] = rand();
    }

    int maxVal = arr[size-1];

    for (int thread = 1; thread <= 12; thread++)
    {
        double time = omp_get_wtime();
        #pragma omp parallel num_threads(thread) //задаем параллельную область
        {
            #pragma omp parallel for reduction(max: maxVal)// собираем в главном потоке результат нахождения maxVal и находим максимальное
            for (int i = 0; i < size; i++)
            {
                if (arr[i] > maxVal)
                {
                    maxVal = arr[i];
                }
            }
            //printf("Num threads: %d\n", omp_get_num_threads());
        }
        //Печать результатов
        printf("Num threads: %d\n", thread);
        printf("Max value: %d\n", maxVal);
        printf("Time execution: %f\n", (omp_get_wtime() - time));
    }
    delete arr;
    return 0;

}
