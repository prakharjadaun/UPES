#include<stdio.h>   //for standard input and output (printf() and scanf())
#include<stdlib.h>  //for dynamic memory allocation (malloc())
#include<time.h>    //for srand()
//whether both the arrays are equal or not(whther there is noise or not)
int CompareEqual(int arr1[],int arr2[], int n)
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
    if(flag==1)
    {
        printf("\nThere is no noise in the recieved data frame!\n");
    }
    else 
    {
        printf("\nThere is noise in the recieved data frame!\n");
    }
}
//to display the passed arrays
void display(int arr[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

int main()
{
    //size of the original data frame
    int n;
    //getting the size from the user 
    printf("Enter the size of the data frame : ");
    scanf("%d",&n);
    //creating arrays by dynamically assigning their sizes
    int *dataFrame = (int*)malloc(n*sizeof(int));
    int *noise = (int*)malloc(n*sizeof(int));
    int *result = (int*)malloc(n*sizeof(int));
    //getting the value of the the original data frame 
    printf("Enter the data frame : \n");
    for(int i=0;i<n;i++)
    {
        printf("Element %dth : ",(n-i));
        scanf("%d",&dataFrame[i]);
    }


    //initially 0 
    printf("Initially, assigning 0 to the noise array....\n");
    for(int i=0;i<n;i++)
    {
        noise[i]=0;
    }

    //displaying the original data frame and the noise 
    printf("Original data frame :  ");
    display(dataFrame,n);
    printf("\nNoise : ");
    display(noise,n);

    printf("\nAdding original data frame and noise....!");
    //adding the initial data frame and the noise 
    int rem=0;  //for storing the remainder
    for(int i=n-1;i>=0;i--)
    {
        if(dataFrame[i]+noise[i]+rem==2)
        {
            result[i]=0;
            rem=1;
        }
        else if(dataFrame[i]+noise[i]+rem==1)
        {
            result[i]=1;
            rem=0;
        }
        else 
        {
            result[i]=0;
            rem=0;
        }
    }

    printf("\nRecieved Data frame (resultant) : ");
    display(result,n);
    //now compairing the original and the resultant frame 
    CompareEqual(dataFrame,result,n);

    printf("\nNow changing the noise array...");
    //randomly assigning 1 to any index in the noise array 
    srand(time(0));
    int  temp = (rand() % ((n-1) - 0 + 1));
    printf("\nBit where 1 is been added to the noise array : %d",(n-temp));
    noise[temp]=1;

    printf("\nUpdated noise array : ");
    display(noise,n);

    //adding it to the initial data frame 
    rem=0;
    for(int i=n-1;i>=0;i--)
    {
        if(dataFrame[i]+noise[i]+rem==2)
        {
            result[i]=0;
            rem=1;
        }
        else if(dataFrame[i]+noise[i]+rem==1)
        {
            result[i]=1;
            rem=0;
        }
        else 
        {
            result[i]=0;
            rem=0;
        }
    }

    printf("\nRecieved Data frame (resultant) : ");
    display(result,n);
    //now compairing the original and the resultant frame 
    CompareEqual(dataFrame,result,n);

    return 0;

}

