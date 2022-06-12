// assign 
// access 
// point to array 
// operations 

#include<stdio.h>
#include<stdlib.h>
int main()
{
    //integer array of size 10 
    int arr[10];

    //iterating through the array and getting the input 
    printf("Enter the array elements : \n");
    for(int i=0;i<10;i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    int *p ; //a pointer to an integer 
    p = arr;

    //adding 1 to each element through pointers 
    for(int i=0;i<10;i++)
    {
        *(p+i) = *(p+i)+1;
    } 

    //printing the array 
    printf("Updated array elements : ");
    for(int i=0;i<10;i++)
    {
        printf("%d ",*(p+i));
    }

    return 0;
}