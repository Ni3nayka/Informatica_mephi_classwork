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

int main() {
    int n = 0, cache = 0, *array;

    scanf("%d", &n);
    array = (double *) malloc(n * sizeof (double));
    for (int i=0; i<n; ++i) {
        scanf("%d", &array[i]);
    }

    print(array, n);

    for (int i=0; i<n-1; ++i) {
        for (int u=1; u<n; ++u) {
            if (array[u-1]>array[u]) {
                cache = array[u-1];
                array[u-1] = array[u];
                array[u] = cache;
            }
        }
        printf("\n");
        print(array, n);
    }

    return 0;
}
