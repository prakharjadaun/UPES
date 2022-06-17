#include <stdio.h>  //for standard input and output (printf() and scanf())
#include <stdlib.h> //for dynamic memory allocation (malloc())
#include <math.h>   //fow pow()
#include <time.h>   //for srand()
int n=4;
int dataFrame[] = {1,1,1,0};
int recievedFrame[4];
// to display the passed arrays
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
    // initially k assigned to 0 and kmax to 15
    int k = 0, kMax = 15;
    // declaring the propagation time, backoff time and total time
    double Tp = 0.0012, Tb = 0, totaltime = 0, R, tSlot = 0.000009;
    // displaying the original data frame and the noise
    while (k < kMax)
    {
        if(idle==0)
        {
            continue;
        }
        //wait for time
//check if the station is idle or not 
        if(idle==0)
        {
            continue;
        }

        R = pow(2, k) - 1;
        srand(time(0));
        // computing the backoff time
        Tb = (rand() % ((int)R - 0 + 1)) * tSlot;

        //sending the frame 
        for(int i=0;i<n;i++)
        {
            recievedFrame[i]=dataFrame[i];
        } 
        // computing the time out time
        totaltime = totaltime + (2 * Tp) + Tb + IFS;

        //getting the acknowledgement
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
    //size of the data frame
    int n=4;
    float DIFS = 0.000034,SIFS=0.000016;
    float difsT=0,sifsT=0;
    float totalTime=0;
    difsT=csma(DIFS);
    printf("\nTime taken for DIFS : %f",difsT);
    sifsT=csma(SIFS);
    printf("\nTime taken for SIFS : %f",sifsT);
    totalTime=difsT+sifsT;
    printf("\n\n----------Final time : %f------------------",totalTime);
    return 0;
}
