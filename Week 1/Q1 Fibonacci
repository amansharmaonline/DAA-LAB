/*The Fibonacci series is a famous mathematical sequence that starts with 0 and 1. Each subsequent number in the series is the sum of the previous two numbers. The sequence looks like this:*/
#include <stdio.h>

int main(void)
{
    int N;
    printf("Enter the number of terms needed in the Fibonacci series: ");
    scanf("%d", &N);

    int first = 0, second = 1, next;

    if (N <= 0) {
        printf("Please enter a positive integer.\n");
        return 1;
    }

    printf("Fibonacci Series: ");

    if (N == 1) {
        printf("%d\n", first);
    }
    else {
        printf("%d %d", first, second);
        for (int i = 2; i < N; i++) {
            next = first + second;
            printf(" %d", next);
            first = second;
            second = next;
        }
        printf("\n");
    }

    return 0;
}

