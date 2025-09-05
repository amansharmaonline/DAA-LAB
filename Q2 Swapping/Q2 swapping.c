#include <stdio.h>

void swap_with_pointers(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int main(void) {
    int a, b, choice;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    printf("Choose swap method:\n");
    printf("1. Swap using normal variables (third variable, no pointers)\n");
    printf("2. Swap using pointers \n");
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    printf("Before swapping: a = %d, b = %d\n", a, b);

    if (choice == 1) {
        int temp;
        temp = a;
        a = b;
        b = temp;
        printf("Swapped using normal variables.\n");
    } else if (choice == 2) {
        swap_with_pointers(&a, &b);
        printf("Swapped using pointers.\n");
    } else {
        printf("Invalid choice. No swap performed.\n");
        return 1;
    }

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}
