#include<stdio.h>       //for standard input and output(printf() and scanf() functions)
#include<stdlib.h>      //for dynamic memory allocation
int main()
{
    //size of the divisor
    int n;
    printf("Enter the size of the divisor : ");
    scanf("%d",&n);
    //divisor array
    int *Divisor = (int*)malloc(n*sizeof(int));
    //size of the original message 
    int k;
    printf("Enter the size of the message : ");
    scanf("%d",&k);
    //Array that holds the message (size : k+n-1)
    int *Message = (int*)malloc((k+n-1)*sizeof(int));

    //getting the divisor from the user 
    printf("Enter the divisor : \n");
    for(int i=0,j=n-1;i<n;i++)
    {
        printf("Enter the %dth element (0/1) : ",j+1);
        scanf("%d",&Divisor[i]);
        j--;
    }

    //getting the message form the user 
    printf("Enter the message : \n");
    for(int i=0,j=k-1;i<k;i++)
    {
        printf("Enter the %dth element (0/1) : ",j+1);
        scanf("%d",&Message[i]);
        j--;
    }

    //appending n-1  0s in the message 
    for(int i=0,j=k;i<n-1;i++)
    {
        Message[j]=0;
        j++;
    }

    



    printf("Divisor : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",Divisor[i]);
    }
    printf("\nMessage : ");
    for (int i = 0; i <(k+n-1); i++)
    {
        printf("%d ",Message[i]);
    }
    
}