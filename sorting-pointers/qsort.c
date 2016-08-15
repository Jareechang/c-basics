#include <stdio.h>

void q_sort(char arr[], int low, int hi);
int partition(char arr[], int low, int hi);
void swap(char arr[], int m, int n);
void pretty_p(char arr[], int lim);

int main()
{
    int arr_size = 7;
    int i;
    char arr[] = { 1, 2, 5, 3, 2, 9, 1 };

    printf("before: ");
    pretty_p(arr, arr_size);

    q_sort(arr, 0, arr_size);

    printf("after: ");
    pretty_p(arr, arr_size);
    return 0;
}
void pretty_p(char arr[], int lim)
{
    int i = 0;
    printf("[ ");
    while(++i < lim)
        printf("%d ", arr[i]);
        printf("]\n");
}

void q_sort(char arr[], int low, int hi)
{
    int mid, i;
    if(low < hi) {
        mid = partition(arr, low, (hi - 1));
        q_sort(arr, low, (mid - 1)); /* q_sort left side  */
        q_sort(arr, (mid + 1), hi); /* q_sort right side*/
    }
}

/* partition: partition the array so the pivot becomes the mid where
 * elements to the left is smaller and elements to the right are larger  */
int partition(char arr[], int low, int hi)
{
    int mid, j,i;
    int p = hi; /* denotes and assigns pivot index */
    mid = low;

    for(j = low; j < (hi - 1); j++) {
        if(arr[j] <= arr[p]) {
            swap(arr, j, mid);
            mid++;
        }
    }
    swap(arr, mid, hi); /* make prev pivot with middle element */
    return mid;
}

/* swap: swap element arr[m] with arr[n] */
void swap(char arr[], int m, int n)
{
    int temp = arr[m];
    arr[m] = arr[n];
    arr[n] = temp;
}
