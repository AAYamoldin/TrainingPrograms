#include <stdio.h>
#include <mpi.h>
#include <chrono>
#include <iostream>


int main(int argc,char *argv[]){
    int size;

    if (argc == 2)
    {
        size = atoi(argv[1]);
    }
    else
    {
        size = 1000000;
    }
    
    int number[size];


    MPI_Init(&argc, &argv); 
    int world_rank; 
    int world_size;
    MPI_Comm_rank(MPI_COMM_WORLD,&world_rank);
    MPI_Comm_size(MPI_COMM_WORLD,&world_size);
    int gath_sum[world_size];
    double start_time = MPI_Wtime();
    int number1[size / world_size];   
    //возможно здесь следует создать number если он не будет шериться      
    if (world_rank == 0)
    {   
        for (int i = 0; i < size; i++)
        {
            number[i] = 1;
        }
    }

    //All processes
    MPI_Scatter(number, size / world_size, MPI_INT, &number1, size / world_size, MPI_INT, 0, MPI_COMM_WORLD);
    // printf("I'm process %d , I received the array : ",world_rank);
       
    int sub_sum = 0;
    for(int i=0 ; i<size / world_size ; i++){
        // printf("%d ",number1[i]);
        sub_sum = sub_sum + number1[i];
    }
    // printf(" My subsum is %d\n", sub_sum);
    //printf("\n");    
    
    std::cout << "REDUCE ALGORITHM" << std::endl;
    int sum = 0;
    MPI_Reduce(&sub_sum, &sum, 1, MPI_INT, MPI_SUM,0,MPI_COMM_WORLD);
        
    if(world_rank == 0)
    {
        printf("The sum of array is: %d\n",sum);
        printf("Execution time %f s.\n", MPI_Wtime() - start_time);
    }

    std::cout << "CASCADE" << std::endl;
    start_time = MPI_Wtime();
    sum = 0;
    MPI_Gather(&sub_sum, 1, MPI_INT, &gath_sum, 1, MPI_INT, 0, MPI_COMM_WORLD);
    
    if (world_rank == 0)
    {  
        for (int i = 0; i < world_size; i++)
        { 
            sum += gath_sum[i];
        } 
        printf("The sum of array is: %d\n", sum); 
        double execution_time = MPI_Wtime() - start_time; 
        printf("Execution time for cascade is: %f\n", execution_time);
    } 
 

    MPI_Finalize();
    return 0;
 }

 