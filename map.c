#include <stdio.h>

void map(int *arr, int (*multiply) (int, int));
int multiply(int x, int y);
void print_result(int arr[], int max);

int main()
{
    int max = 6;
    int arr[] = { 1, 2, 3 ,4, 5, 6, 7 };
    int *ptr = arr;
    map(ptr, multiply);
    print_result(arr, max);
    return 0;
}

void map(int *arr, int (*mutiply)(int, int))
{
    // Set default value to multiple of 2
    while(*arr != '\0') {
        *arr++ = (*multiply)((*arr), 2);
    }
}

void print_result(int arr[], int max)
{
    int i = 0;
    printf("\n results:");
    while(i < max) {
        printf("%d ", arr[i++]);
    }
    printf("\n");
    printf("\n");
}

int multiply(int x, int y)
{
    return x * y;
}
