#include <stdio.h>
#include <stdlib.h>

// Comparator function for qsort
int comparator(const void *a, const void *b) {
    int first = *((int *)a);
    int second = *((int *)b);
    return (first > second) - (first < second);  // Compare integers
}

// Demonstration of sorting an array using qsort and the comparator
void demonstrate_sort() {
    int nums[] = {3, 10, 2, 8, 1, 6, 0, 4, 14};
    size_t size = sizeof(nums) / sizeof(nums[0]);

    qsort(nums, size, sizeof(int), comparator);

    printf("Sorted array elements:\n");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");
}

// Functions for Task 2
int add(int x, int y) { return x + y; }
int subtract(int x, int y) { return x - y; }
int multiply(int x, int y) { return x * y; }
int divide(int x, int y) { return y != 0 ? x / y : 0; }

int main() {
    // Task 1: Sorting demo
    printf("Task 1: Sorting an array using qsort and a custom comparator function:\n");
    demonstrate_sort();

    // Task 2: Function pointer demo
    int num1 = 6, num2 = 3;
    int (*ops[4])(int, int) = { add, subtract, multiply, divide };

    printf("\nTask 2: Perform operations using function pointers:\n");
    printf("Operands -> num1: %d, num2: %d\n", num1, num2);
    printf("Choose an operation to perform:\n");
    printf("0 - Add\n1 - Subtract\n2 - Multiply\n3 - Divide\n4 - Exit\n");

    char option;
    scanf(" %c", &option);

    if (option >= '0' && option <= '3') {
        int result = ops[option - '0'](num1, num2);
        printf("Result of operation: %d\n", result);
    } else if (option == '4') {
        printf("Exiting the program.\n");
    } else {
        printf("Error: Invalid choice.\n");
    }

    return 0;
}
