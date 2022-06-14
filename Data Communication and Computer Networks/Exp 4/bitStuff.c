#include<stdio.h>     //for standard input and output (printf() and scanf())
#include<stdlib.h>    //for using malloc() (for dynamic memory allocation)

int main()
{
    //size of the array
    int n;   
    //getting the size of the array from user 
    printf("Enter the numbers of characters in bit stream : ");
    scanf("%d",&n);

    //maximum size the bit stream array can have 
    int m = n + (n/5);  

    //dynamically allocating memory of array 
    int *arr = (int*)malloc(m*sizeof(int));

    //getting the bit stream from user 
    printf("Enter the bit stream : \n");
    for(int i=0;i<n;i++)
    {
        printf("Enter the bit %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    //bits before stuffing
    printf("\nBit stream before bit stuffing : \n");
    printf("Bit stream : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    //bitstuffing the bit stream
    for(int i=0;i<n;i++)
    {
        if(i+4<n)
        {
            if((arr[i]+arr[i+1]+arr[i+2]+arr[i+3]+arr[i+4])==5)
            {
                //increasing the size of the array
                n = n + 1;  
                int j = n - 1;  
                //shifting the elements to the right
                while(j>i+5)
                {
                    arr[j]=arr[j-1];
                    j--;
                }
                //inserting 0 
                arr[j]=0;
                //incrementing value of i
                i = i + 5;
            }
        }
    }
    //printing bit stream after bit stuffing 
    printf("\n\nBit stream after bit stuffing : \n");
    printf("Bit stream : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }

    //de stuffing the bit stream
    for(int i=0;i<n;i++)
    {
        if(i+4<n)
        {
            if((arr[i]+arr[i+1]+arr[i+2]+arr[i+3]+arr[i+4])==5)
            {
                //decreasing the array size 
                n = n - 1;
                int j = i + 5;
                //shifting elements to the left 
                while(j<n)
                {
                    arr[j] = arr[j+1];
                    j = j + 1;
                }
                //incrementing i 
                i = i + 4;
            }
        }
    }
    
    //printing the bit stream after de stuffing
    printf("\n\nBit stream after de-stuffing : \n");
    printf("Bit stream : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}