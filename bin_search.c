#include <stdio.h>
#include <math.h>

int bin_search(int t, char arr[], int n);

int main()
{

    int i;
    char arr[] = { 1,2,3,4,5,6 };

    printf("search index: %d \n", bin_search(10, arr, 6));
    return 0;
}

int bin_search(int t, char arr[], int n)
{
    int low, high, mid; 
    low = 0;
    high = n - 1;
    mid = 0;

    while((low <= high) && (arr[mid] != t)) {
        mid = floor((low+high)/2);
        if(t < arr[mid]) {
            high = mid - 1;
        } 
        else {
            low = mid + 1;
        }
    }
    return ((arr[mid] == t) ? mid : -1);
}
