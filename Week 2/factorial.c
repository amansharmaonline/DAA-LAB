#include <stdio.h>

int factorial(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * factorial(n - 1);
    }
}

int main(void)
{
    int n, fact;
    printf("Enter the number whose factorial we have to calculate: ");
    scanf("%d", &n);
    fact = factorial(n);
    printf("Factorial of %d is %d\n", n, fact);
    return 0;
}
