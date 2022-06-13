#include<stdio.h>     //for standard input and output (printf() and scanf())
#include<math.h>      //for log2() function
int main()
{
    //variables required 
    float dataRate;    //for data rate (unit - bits per sec (bps))
    double L;          //for number of levels
    int B;             //for bandwidth (Hz)
    //getting the values form the user 
    printf("Enter the number of levels : ");
    scanf("%lf",&L);
    printf("Enter the Bandwidth : ");
    scanf("%d",&B);
    //calculating the data rate 
    dataRate = 2*B*(log2(L));
    //printing the calculated value of the data rate
    printf("Data rate : %.3f bps\n",dataRate);
    return 0;
}