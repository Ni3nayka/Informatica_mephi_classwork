#include <stdio.h>
#include <stdlib.h>

int main() {
    int i=0,n=10,k=4,i1=3;
    int *array, *array_2;

    scanf("%d", &n);
    array = (double *) malloc(n * sizeof (double));
    for (i=0; i<n; ++i) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);
    scanf("%d", &i1);

    if (array == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }

    for (i=0; i<n; ++i) {
        printf("%3i",i+1);
    }
    printf("\n");
    for (i=0; i<n; ++i) {
        printf("%3i",array[i]);
    }
    printf("\n");
    printf("\n");

    for (i=k-1; i<n-1; ++i) {
        array[i] = array[i+1];
    }
    n--;
    array_2 = (int *) realloc(array, n * sizeof (int));
    if (array_2 == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        array = array_2;
    }
    i1--;
    k = array[i1];
    array[i1] = array[0];
    array[0] = k;

    for (i=0; i<n; ++i) {
        printf("%3i",i+1);
    }
    printf("\n");
    for (i=0; i<n; ++i) {
        printf("%3i",array[i]);
    }
    printf("\n");
    free(array);
    return 0;
}
