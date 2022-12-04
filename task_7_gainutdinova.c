#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
//our task is to multiply two 3000x3000 matrixes

int main()
{
    double start = omp_get_wtime();
    srand(time(NULL));

    int i, j, ** a, ** b, ** c, k;


    a = (int**)malloc(sizeof(int*) * 3000);
    for (int i = 0; i < 3000; i++)
    {
        a[i] = (int*)malloc(sizeof(int) * 3000);
    }

    b = (int**)malloc(sizeof(int*) * 3000);
    for (int i = 0; i < 3000; i++)
    {
        b[i] = (int*)malloc(sizeof(int) * 3000);
    }

    c = (int**)malloc(sizeof(int*) * 3000);
    for (int i = 0; i < 3000; i++)
    {
        c[i] = (int*)malloc(sizeof(int) * 3000);
    }


    for (i = 0; i < 3000; i++) //filling matrixes with random numbers
    {
        for (j = 0; j < 3000; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;

        }
    }

#pragma omp parallel for private(j, k)
    for (i = 0; i < 3000; i++)
    {
        for (j = 0; j < 3000; j++)
        {
            c[i][j] = 0;

            for (k = 0; k < 3000; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

            }
        }
    }

    double end = omp_get_wtime();
    double time_taken = end - start;
    printf("Running time of the program: %f \n", time_taken);
}