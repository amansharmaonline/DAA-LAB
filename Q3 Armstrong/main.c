#include<stdio.h>
#include<math.h>
int main(void)
{
    int num,digit;
    int sum=0;
    printf("Enter a number to verify: ");
    scanf("%d",&num);
    int len=0;
    int temp;
    temp=num;
    while(temp!=0)
    {
        temp=temp/10;
        len++;
    }
    
    temp=num;
    while(temp!=0)
    {
        digit=temp%10;
        sum+=pow(digit,len);
        temp=temp/10;
    }
    if (sum==num)
    {
        printf("The given number is an armstrong number\n");
    }
    else
    {
        printf("The given number is not an armstrong number\n");
    }
    return 0;
}
