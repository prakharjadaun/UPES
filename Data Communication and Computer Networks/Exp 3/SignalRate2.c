#include<stdio.h>  //for standard input and output 
#include<stdlib.h>
#include<time.h>
#define C 0.5      //case factor defined as constant 
int main()
{
    FILE *ptr; 
    ptr = fopen("sample.txt","w");
    //required variables
    int r;     //number of signal elements 
    float N;   //data rate in bps 
    float S;   //signal rate 
    float temp;  //temporary variable 
    //getting the input from the user
    printf("Enter the Data rate : ");
    scanf("%f",&N);
    srand(time(0));  //based on seed value #
    for(int i=0;i<10;i++)
    {
        r = (rand() % (8 - 1 + 1)) + 1;
        temp = (float)1/r;
        //calculating the signal rate (unit bauds)
        S = C*N*temp;
        printf("\nr = %d",r);
        printf("\nSignal rate : %.3f bauds\n",S);
        fprintf(ptr,"%f\n",S);
    }
    fclose(ptr);
    return 0;
}