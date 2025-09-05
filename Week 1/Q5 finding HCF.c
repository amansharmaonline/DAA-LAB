#include <stdio.h>

int findHCF(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(void) {
    int num1, num2;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);

    int hcf = findHCF(num1, num2);
    printf("HCF of %d and %d is %d\n", num1, num2, hcf);

    return 0;
}
