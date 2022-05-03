#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

void print_mas(int **a, int y, int x) {
    for (int i = 0; i<y; i++) {
        for (int u=0; u<x; ++u) {
            printf("%3i",*(a+u+i*x));
        }
        printf("\n");
    }
}

void print_mas_1(int **a, int y, int x) {
    for (int i = 0; i<y; i++) {
        for (int u=0; u<x; ++u) {
            printf("%6i",*(a+u+i*x));
        }
        printf("\n");
    }
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
    if (DEBUG) {
        *n = rand()%3 + 3;
        array = mem((*n)*(*n));
        for (int i=0; i<(*n)*(*n); ++i) {
            array[i] = rand()%10;
        }
    }
    else {
        scanf("%d", n);
        array = mem((*n)*(*n));
        input(array, (*n)*(*n));
    }
    return array;
}

int *multiply(int *a, int *b, int n) {
    int *c;
    c = mem(n*n);
    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            for (int i = 0; i<n; i++) {
                c[y*n+x] += a[y*n+i]*b[i*n+x];
            }
        }
    }
    return c;
}

int *sum(int *a, int *b, int n) {
    int *c;
    c = mem(n*n);
    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            c[y*n+x] += a[y*n+x]*b[y*n+x];
        }
    }
    return c;
}

int *transonting(int *a, int n) {
    int cache = 0;
    for (int y = 0; y<n; y++) {
        for (int x = y+1; x<n; x++) {
            cache = a[x*n+y];
            a[x*n+y] = a[y*n+x];
            a[y*n+x] = cache;
        }
    }
    return a;
}

int main() {
    int n = 0, *array, *answer;
    srand(time(NULL));

    array = read(&n);

    print_mas(array, n,n);
    printf("\n");
    answer = multiply(array,array,n);
    answer = transonting(answer,n);
    answer = multiply(array,answer,n);
    print_mas_1(answer, n,n);
    free(array);
    free(answer);

    return 0;
}

