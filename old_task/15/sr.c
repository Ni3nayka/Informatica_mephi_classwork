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

int *mem(int rm) {
    int *massiv;
    massiv=(int*)calloc(rm,sizeof(int));
    return massiv;
}

void input(int *mas,int rm) {
    for(int i=0;i<rm;i++) {
        scanf("%d",mas+i);
    }
}

int *read(int *n) {
    int *array;
    scanf("%d", n);
    array = mem(*n);
    input(array, *n);
    return array;
}

int *read_1(int *n) {
    int test[6] = {3,1,9,2,7,5};
    int *array;
    *n = 6;
    array = mem(*n);

    for(int i=0;i<*n;i++) {
        array[i] = test[i];
    }
    return array;
}

void bubble_sort(int *array, int n, int *counter) {
    int cache = 0;
    for (int i=0; i<n-1; ++i) {
        for (int u=1; u<n; ++u) {
            if (array[u-1]>array[u]) {
                *counter+=1;
                cache = array[u-1];
                array[u-1] = array[u];
                array[u] = cache;
            }
        }
        if (test_sort_for_bubble(array, n)) {
            break;
        }
    }
}

int test_sort_for_bubble(int *a, int n) {
    for (int i=0; i<n-1; ++i) {
        if (*(a+i)>=*(a+i+1)) {
            return 0;
        }
    }
    return 1;
}

void QuickSort_operating(int *A, int first, int last, int N, int *counter) {
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
            *counter+=1;
            cache = A[r];
            A[r] = A[l];
            A[l] = cache;
            l++;
            r--;
        }
    }
    if (first<r) {
        QuickSort_operating(A, first,r,N,counter);
    }
    if (l<last) {
        QuickSort_operating(A, l,last,N,counter);
    }
}

void QuickSort(int *A, int n, int *counter) {
    QuickSort_operating(A, 0, n-1, n, counter);
}

int *copy_array(int *array,int rm) {
    int *massiv;
    massiv=(int*)calloc(rm,sizeof(int));
    for (int i=0; i<rm; ++i) {
        massiv[i] = array[i];
    }
    return massiv;
}

int main() {
    int n = 0,*array_bubble, *array_quicksort, counter_bubble = 0, counter_quicksort = 0;

    array_bubble = read(&n);
    array_quicksort = copy_array(array_bubble, n);

    print(array_quicksort, n);
    printf("\n");

    bubble_sort(array_bubble,n,&counter_bubble);
    QuickSort(array_quicksort,n,&counter_quicksort);

    print(array_quicksort, n);

    printf("\n");
    printf("counter_bubble:    %i\n", counter_bubble);
    printf("counter_quicksort: %i\n", counter_quicksort);

    free(array_bubble);
    free(array_quicksort);

    return 0;
}
