#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h>
#include <time.h>
//our task is to multiply two 3x3 matrixes

void Conclusion(int a[20][20])
{
    int i, j;
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            printf("%4d", a[i][j]); //sets the width of the output field
        }
        printf("\n");
    }
}

int main()
{
    srand(time(0));//sets the current time as the base, it is needed for different triggering of the random number generator
    int starttime = clock();
    int i, j, a[20][20], b[20][20], c[20][20], k;
    omp_set_num_threads(2);
    #pragma omp parallel for private(j)
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            a[i][j] = rand() % 10;
            b[i][j] = rand() % 10;

        }
    }
    printf("First array(matrix) \n");
    Conclusion(a);

    printf("Second array(matrix) \n");
    Conclusion(b);


    omp_set_num_threads(2);
#pragma omp parallel for private(j)
    for (i = 0; i < 20; i++)
    {
        for (j = 0; j < 20; j++)
        {
            c[i][j] = 0;

            for (k = 0; k < 20; k++)
            {
                c[i][j] = c[i][j] + a[i][k] * b[k][j];

            }
        }
    }
    int endtime = clock();//counts the time in beats
    printf("Multiplication of arrays(matrixes) \n");
    Conclusion(c);
    float t = (float)(endtime-starttime) / CLOCKS_PER_SEC;
    printf("Running time of the program: "); //we divided beats/beats per second to translate timing into seconds
    printf("%f", t);
}