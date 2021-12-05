#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int maxs;
    printf("Введіть кількість стовпців або рядків матриці: ");
    scanf("%i", &maxs);

    int max = maxs*2;

    double A[maxs][max];

    char prompt = '\0';

    while (prompt != '1' && prompt != '2')
    {
        printf("Як ви бажаєте використати дану програму?\n1 - з метою обчислення відомої нам матриці\n2 - з метою обчислення матриці із випадковими значеннями\n");
        scanf("%c", &prompt);
        scanf("%c", &prompt);
        if (prompt == '1')
        {
            for (int i = 0; i < maxs; i++)
            {
                for (int n = 0; n < maxs; n++)
                {
                    printf("Значення %i стовпця %i рядка: ", n+1, i+1);
                    scanf("%lf", &A[i][n]);
                }
            }
            break;
        }
        if (prompt == '2')
        {
            for (int i = 0; i < maxs; i++)
            {
                for (int n = 0; n < maxs; n++)
                {
                    A[i][n] = rand() % 1000;
                }
            }
            break;
        }
    }



    for (int i = 0; i < maxs; i++)
    {
        for(int n = maxs; n < max; n++)
        {
            if(n == i+maxs)
                A[i][n] = 1;
            else
                A[i][n] = 0;
        }
    }

    bool desc = true;
    bool procces = true;
    int row = 0;
    float stm = 0.0;
    float mts = 0.0;

    while(procces == true)
    {
        if (desc == true)
        {
            for (int n = row + 1; n < maxs; n++)
            {
                stm = A[n][row] / A [row][row];

                for (int i = 0; i < max; i++)
                {
                    A[n][i] -= A[row][i] * stm;
                }
            }
        }
        else
        {
            for (int n = row - 1; n > -1; n--)
            {
                stm = A[n][row] / A [row][row];

                for (int i = 0; i < max; i++)
                {
                    A[n][i] -= A[row][i] * stm;
                }
            }
        }

        mts = 1 / A[row][row];

        for (int i = 0; i < max; i++)
        {
            A[row][i] *= mts;
        }

        if (desc == false)
            row -= 1;

        if (desc == true)
            row += 1;

        if (row == maxs - 1)
        {
            desc = false;
        }

        if (row == -1)
            procces = false;
    }

    for (int i = 0; i < maxs; i++)
    {
        printf("|");
        for (int n = maxs; n < max; n++)
        {
            printf("%f", A[i][n]);
            if(n + 1 != max)
                printf(" ");
        }
        printf("|\n");
    }
}