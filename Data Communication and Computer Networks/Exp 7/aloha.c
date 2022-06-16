#include <stdio.h>  //for standard input and output (printf() and scanf())
#include <stdlib.h> //for dynamic memory allocation (malloc())
#include <math.h>   //fow pow()
#include <time.h>   //for srand()

// to display the passed arrays
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
// to see whether there is noise or not in the recieved frame
int Checknoise(int arr1[], int arr2[], int n)
{
    int flag = 1, i = 0;
    for (; i < n; i++)
    {
        if (arr1[i] != arr2[i])
        {
            flag = 0;
            break;
        }
    }
    return flag;
}
// check if the dataframe all values as 1
int CheckOne(int arr[], int n)
{
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != 1)
        {
            flag = 0;
            break;
        }
    }
    return flag;
}

int main()
{
    // initially k assigned to 0 and kmax to 1000
    int k = 0, kMax = 10;

    // size of the data frame
    int n;
    // noise
    int noise = 1;
    int m = 0;

    // declaring the propagation time, backoff time and total time
    double Tp = 0, Tb = 0, totaltime = 0, R, tSlot = 0.0000015;

    // getting the size from the user
    printf("Enter the size of the data frame : ");
    scanf("%d", &n);
    // creating arrays by dynamically assigning their sizes
    int *dataFrame = (int *)malloc((n + 1) * sizeof(int));
    int *recievedFrame = (int *)malloc((n + 1) * sizeof(int));
    // getting the value of the the original data frame
    printf("Enter the data frame : \n");
    for (int i = 0; i < n; i++)
    {
        printf("Element %dth : ", (n - i));
        scanf("%d", &dataFrame[i]);
    }

    // getting the value of the propagation time
    printf("Enter the Propagation time : ");
    scanf("%lf", &Tp);

    // displaying the original data frame and the noise
    printf("\nOriginal data frame :  ");
    display(dataFrame, n);
    printf("\nNoise : %d", noise);
    while (m < 1000)
    {
        while (k < kMax)
        {
            // recieving the frame
            for (int i = 0; i < n; i++)
            {
                recievedFrame[i] = dataFrame[i];
            }
            if (CheckOne(dataFrame, n) == 1)
            {
                n = n + 1;
                for (int i = 1; i < n; i++)
                {
                    recievedFrame[i] = 0;
                }
                recievedFrame[0] = 1;
            }
            else
            {
                int rem = 0, i = n - 1;
                while (i >= 0)
                {
                    if (recievedFrame[i] == 1 && noise == 1)
                    {
                        recievedFrame[i] = 0;
                        rem = 1;
                    }
                    else
                    {
                        recievedFrame[i] += rem;
                    }
                    i--;
                }
            }

            printf("\nRecieved Data frame : ");
            display(recievedFrame, n);

            // computing the time out time
            // totaltime = totaltime + (2 * Tp) + Tb;
            // printf("\nTotal time taken: %.4f",totaltime);

            // comparing whether there is a noise in the recieved frame or not
            printf("\nChecking whether there is noise or not in recieved frame or not...!");
            int flag = Checknoise(dataFrame, recievedFrame, n);
            if (flag == 1)
            {
                printf("\nFrame recieved has no noise...!\nSUCCESS!");
                break;
            }
            else
            {
                printf("\nRecieved Frame has noise...!!!\n");
                // incrementing the value of k
                k = k + 1;
                R = pow(2, k) - 1;
                srand(time(0));
                // computing the backoff time
                Tb = (rand() % ((int)R - 0 + 1)) * tSlot;

                printf("Backoff time : %.3f", Tb);
            }
        }
        printf("\n\n---Total time taken : %.3f seconds---", totaltime);
        totaltime = totaltime + (2 * Tp) + Tb;
        m++;
    }
    if (m == 1000)
    {
        printf("\nAlgorithm Aborted....!");
    }
    return 0;
}