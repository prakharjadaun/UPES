#include<stdio.h>       //for standard input and output(printf() and scanf() functions)
#include<stdlib.h>      //for dynamic memory allocation
#include<math.h>

int BinToDec(int arr[],int size)
{
    int dec=0,i=0,temp;
    for(int j=size-1;j>=0;j--)
    {
        temp = arr[j];
        dec = dec + (temp*pow(2,i));
        i++;
    }
    return dec;
}
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

    //before peroforming the division of Message and divisor, let's convert them into decimal 
    int mess = BinToDec(Message,(k+n-1));
    int div = BinToDec(Divisor,n);
    //performing the division and getting the remainder
    int remainder = (mess%div);
    //sroting int remainder in the binary form
    int *Rem = (int*)malloc((n-1)*sizeof(int));
    int temp;
    for(int i=n-2;i>=0;i--)
    {
        Rem[i] = remainder%2;
        remainder = remainder/2;
    }

    //replacing the binary remainder with the appended n-1 0s
    for(int i=0,j=k;i<n-1;i++)
    {
        Message[j] = Rem[i];
        j++; 
    }

    //final message sent to the reciever 
    printf("\nMessage recieved by the reciever : ");
    for (int i = 0; i < (k+n-1); i++)
    {
        printf("%d ",Message[i]);
    }
    
}

