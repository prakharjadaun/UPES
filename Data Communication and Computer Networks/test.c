#include<stdio.h>  //for standard input and output 
#include<stdlib.h>   //for dynamic memory allocation
#include<time.h>
#include<math.h>   //for pow() function

//function decalaration
int checkEqual(int arr1[], int arr2[], int size);

int main()
{
    int k=0;
    int n=5;   //size of the frame
    int *frame = (int*)malloc(n*sizeof(int));

    printf("Enter the data frane : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&frame[i]);
    }

    int kmax = 15;  //maximum attempt 
    float tb, tp, R;
    float finaltime=0;   //total time
    int noise=1;

    printf("Enter the propagation time : ");
    scanf("%f",&tp);

    //resultant frame 
    int *result = (int *)malloc(n*sizeof(int));

    while(k<kmax)
    {
        //sending the frame 
        for(int i=0;i<n;i++)
        {
            result[i]=frame[i];
        }
        int rem=0;
        //adding the noise in resultant/recieved frame
        if(result[n-1]==1 && noise==1)
        {
            result[n-1]=0;
            rem=1;
            result[n-2]+=rem;
        }
        else 
        {
            result[n-1]+=noise;
        }

        //computing the final time
        finaltime+=(2*tp) + tb;

        if(checkEqual(frame,result,n)==1)
        {
            printf("frame sent successfully");
        } 
        else 
        {
            k=k+1;
            R = rand() % (int)(pow(2,k-1)-0+1);
            tb = R*tb;
        }
    }
}

//for compairing the original frame and recieved frame
int checkEqual(int arr1[], int arr2[], int size)
{
    int flag=1;
    for(int i=0;i<size;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}