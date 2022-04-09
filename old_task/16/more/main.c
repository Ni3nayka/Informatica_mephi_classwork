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
    printf("\n");
}

int main() {
    int size_1 = 0, size_2 = 0, *array_1, *array_2, test = 0, counter = 0;

    scanf("%i", &size_1);
    array_1 = (int *) malloc(size_1 * sizeof (int));
    for (int i=0; i<size_1; ++i) {
        scanf("%i", &array_1[i]);
    }

    scanf("%i", &size_2);
    array_2 = (int *) malloc(size_2 * sizeof (int));
    for (int i=0; i<size_2; ++i) {
        scanf("%i", &array_2[i]);
    }

    print(array_1, size_1);
    print(array_2, size_2);

    for (int i = 1; i<=size_1+size_2; i++) {
        printf("%3i",i);
    }
    printf("\n");
    while (1) {
        for (int i = 0; i<size_1;i++) {
            if (array_1[i]==test) {
                printf("%3i",test);
                counter++;
            }
        }
        for (int i = 0; i<size_2;i++) {
            if (array_2[i]==test) {
                printf("%3i",test);
                counter++;
            }
        }
        test++;
        if (counter==size_1+size_2) {
            break;
        }
    }
    printf("\n");
    printf("\n");

    return 0;
}
