#include <stdio.h>  
#include <stdlib.h>
#include <math.h>   
#include <time.h>   
int n=4;
int dataFrame[] = {1,1,1,0};
int recievedFrame[4];
void display(int arr[])
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}
float csma(float IFS)
{
    int idle = 1;

    int k = 0, kMax = 15;
    double Tp = 0.0012, Tb = 0, totaltime = 0, R, tSlot = 0.000009;
    while (k < kMax)
    {
        if(idle==0)
        {
            continue;
        }

        if(idle==0)
        {
            continue;
        }

        R = pow(2, k) - 1;
        srand(time(0));
        Tb = (rand() % ((int)R - 0 + 1)) * tSlot;

        for(int i=0;i<n;i++)
        {
            recievedFrame[i]=dataFrame[i];
        } 
        totaltime = totaltime + (2 * Tp) + Tb + IFS;

        int ack = 0;
        if (ack == 1)
        {
            printf("\nFrame recieved has recieved successfully!");
            break;
        }
        else
        {
            k = k + 1;
        }
    }
    return totaltime;
}
int main()
{    
    int n=4;
    float DIFS = 0.000034,SIFS=0.000016;
    float difsT=0,sifsT=0;
    float totalTime=0;
    difsT=csma(DIFS);
    sifsT=csma(SIFS);
    totalTime=difsT+sifsT;
    printf("\n\n----------Final time : %f------------------",totalTime);
    return 0;
}