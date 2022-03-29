#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    for (int i=0; i<n; ++i) {
        printf("%3i",i+1);
    }
    printf("\n");
    for (int i=0; i<n; ++i) {
        printf("%3i",*(a+i));
    }
    printf("\n");
}

void QuickSort(int *A, int first, int last, int N) {
    int cache = 0;
    int l=first, r=last;
    int pivot=A[(l+r)/2];
    while (l<=r) {
        while (A[l]<pivot) {
            l++;
        }
        while (A[r]>pivot) {
            r--;
        }
        if (l<=r) {
            cache = A[r];
            A[r] = A[l];
            A[l] = cache;
            l++;
            r--;
        }
    }
    printf("\n");
    print(A, N);
    if (first<r) {
        QuickSort(A, first,r,N);
    }
    if (l<last) {
        QuickSort(A, l,last,N);
    }
}


int main() {
    int n = 7, cache = 0, l = 0, r = 6, pivot = 0;//, *array;
    int array[7] = {5,9,3,7,4,1,2};
    pivot=array[(l+r)/2];

    /*scanf("%d", &n);
    array = (double *) malloc(n * sizeof (double));
    for (int i=0; i<n; ++i) {
        scanf("%d", &array[i]);
    }*/

    print(array, n);

    QuickSort(&array, 0, n-1, n);

    return 0;
}
