#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
    srand(time(0));
    int  r = (rand() % (1 - 0 + 1));
    printf("\n%d",r);
}
