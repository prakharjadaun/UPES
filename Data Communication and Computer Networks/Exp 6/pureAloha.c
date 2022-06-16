#include<stdio.h>   //for standard input and output (printf() and scanf())
#include<stdlib.h>  //for dynamic memory allocation (malloc())
#include<math.h>   //fow pow()
#include<time.h>    //for srand() 

//to display the passed arrays
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}
//to see whether there is noise or not in the recieved frame
int Checknoise(int arr1[],int arr2[], int n)
{
    int flag=1,i=0;
    for(;i<n;i++)
    {
        if(arr1[i]!=arr2[i])
        {
            flag=0;
            break;
        }
    }
    return flag;
}

int main()
{
    //initially k assigned to 0
    int k=0, kMax=15;

    //size of the data frame
    int n;
    //noise 
    int noise;

    //declaring the propagation time, backoff time and final time
    float Tp=0, Tb=0, Finaltime=0,R; 
    //getting the size from the user 
    printf("Enter the size of the data frame : ");
    scanf("%d",&n);
    //creating arrays by dynamically assigning their sizes
    int *dataFrame = (int*)malloc(n*sizeof(int));
    int *recievedFrame = (int*)malloc(n*sizeof(int));

    

    //getting the value of the the original data frame 
    printf("Enter the data frame : \n");
    for(int i=0;i<n;i++)
    {
        printf("Element %dth : ",(n-i));
        scanf("%d",&dataFrame[i]);
    }

    //getting the value of the propagation time
    printf("Enter the Propagation time : ");
    scanf("%f",&Tp);
    

    while(k<kMax)
    {
        printf("\n\n------When k = %d-----",k);
        //getting the value of noise from the user 
        printf("\nEnter the noise (0/1) : ");
        scanf("%d",&noise);

        //displaying the original data frame and the noise 
        printf("\nOriginal data frame :  ");
        display(dataFrame,n);
        printf("\nNoise : %d",noise);

        //adding noise to the original data frame 
        for(int i=0;i<n;i++)
        {
            //first assigning the value of the original data frame to the recieved frame 
            recievedFrame[i]=dataFrame[i];
        }
        //now adding the noise 
        int rem=0;
        if(recievedFrame[n-1]==1 && noise==1)
        {
            recievedFrame[n-1]=0;
            rem=1;
            recievedFrame[n-2]+=rem;
        }
        else
        {
            recievedFrame[n-1]+=noise;
        }

        printf("\nRecieved Data frame : ");
        display(recievedFrame,n);

        //computing the time out time 
        Finaltime = Finaltime + (2*Tp);
        printf("\nTime Taken: %.3f",Finaltime);

        //comparing whether there is a noise in the recieved frame or not
        printf("\nChecking whether there is noise or not in recieved frame or not...!");
        int flag = Checknoise(dataFrame,recievedFrame,n);
        if(flag==1)
        {
            printf("\nFrame recieved has no noise...!\nSUCCESS!");
            break;
        }
        else 
        {
            printf("\nRecieved Frame has noise...!!!\n");
            //incrementing the value of k
            k = k + 1;
            srand(time(0));
            R= rand() % ((int)pow(2,k)-0+1);

            //computing the backoff time 
            Tb = R*Tp;
            printf("Backoff time : %.3f",Tb);

        }
    }
    if(k==15)
    {
        printf("\nAlgorithm Aborted....!");
    }
    return 0;
}