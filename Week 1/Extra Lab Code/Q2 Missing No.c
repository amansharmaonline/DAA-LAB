#include <stdio.h>

int main() {
    int n;
    printf("Enter value of n: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d numbers (from 0 to %d, with one missing):\n", n, n);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    int expected_sum = n * (n + 1) / 2;  // sum of 0..n
    int missing = expected_sum - sum;

    printf("The missing number is: %d\n", missing);
    return 0;
}
