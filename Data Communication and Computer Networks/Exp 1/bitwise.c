#include<stdio.h>
//purpose : to demonstrate bitwise operations  
int main()
{
    /*
    Bitwise operations that we are going to see : 
    & (bitwise AND)
    | (bitwise OR)
    ^ (bitwise XOR)
    << (left shift)
    >> (right shift)
    ~ (bitwise NOT) 
    */

   //variable declarations 

   int a=5;  //a=5 (0101)
   int b=7;  //b=7 (0111)

   //& (bitwise AND)
   printf("AND of %d and %d : %d",a,b,(a & b));  //(0101)

    //| (bitwise OR)
    printf("\nOR of %d and %d : %d",a,b,(a | b)); //(0111)

    //^ (bitwise XOR)
    printf("\nXOR of %d and %d : %d",a,b,(a ^ b)); //(0010)

    //<< (left shift)
    printf("\nLeft shift of %d and %d : %d",a,b,(a << b)); //(1010000000)  

    //>> (right shift)  //gray code conversion #
    printf("\nRight shift of %d and %d : %d",a,b,(a >> b));   //(0000)

    //~ (bitwise NOT)
    printf("\nNOT of %d : %d",a,(~a));    

    return 0;
}