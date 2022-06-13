#include<stdio.h>  //for standard input and output 
int main()
{
    //required variables
    int r;  
    float c;
    float N;
    float S;
    //getting the input from the user
    printf("Enter the Data rate : ");
    scanf("%f",&N);
    printf("Enter the case factor : ");
    scanf("%f",&c);
    printf("Enter r : ");
    scanf("%d",&r);
    //calculating the signal rate (unit bauds)
    S = c*N*((float)(1/r));
    printf("Signal rate : %.3f bauds\n",S);
    return 0;
}

