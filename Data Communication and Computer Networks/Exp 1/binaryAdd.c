#include<stdio.h>
#include<stdlib.h>   //malloc function for dynamic memory allocation
//purpose : to demonstrate the binary addition on two binary numbers 

int main()
{
    int n;      //to store the size of the arrays 
    printf("Enter the value of n : ");
    scanf("%d",&n);
    //#size of integer arrays 
    //declaring two arrays for storing the binary strings
    int *b1 = (int*)malloc(n*sizeof(int));
    int *b2 = (int*)malloc(n*sizeof(int));
    int *b3 = (int*)malloc(n*sizeof(int));

    //getting the both binary strings from the user
    //binary string 1 
    printf("Enter the binary string 1 : \n");
    for(int i=0;i<n;i++)
    scanf("%d",&b1[i]);
    //binary string 2
    printf("Enter the binary string 2 : \n");
    for(int i=0;i<n;i++)
    scanf("%d",&b2[i]);

    //printing the binary strings 
    //binary string 1 
    printf("\nBinary string 1 : ");
    for(int i=0;i<n;i++)
    printf("%d",b1[i]);


    printf("\nBinary string 2 : ");
    for(int i=0;i<n;i++)
    printf("%d",b2[i]);
  
// binary string 1 : 11001 
// Binary string 2 : 00110
// Binary string 3 : 11111
    int rem=0;  //for storing the remainder
    for(int i=n-1;i>=0;i--)
    {
        if(b1[i]+b2[i]+rem==2)
        {
            b3[i]=0;
            rem=1;
        }
        else if(b1[i]+b2[i]+rem==1)
        {
            b3[i]=1;
            rem=0;
        }
        else 
        {
            b3[i]=0;
            rem=0;
        }
    }

    //binary string 3 (having binary addition of binary string 1 and string 2)
    printf("\nBinary string 3 : ");
    for(int i=0;i<n;i++)
    printf("%d",b3[i]);

    return 0;
}