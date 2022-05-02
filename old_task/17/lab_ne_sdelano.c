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

int *read(int *y, int *x) {
    int *array;
    if (DEBUG) {
        *x = rand()%4 + 3;
        *y = rand()%4 + 3;
        array = mem((*x)*(*y));
        for (int i=0; i<(*x)*(*y); ++i) {
            array[i] = rand()%10;
        }
    }
    else {
        scanf("%d %d", y, x);
        array = mem((*x)*(*y));
        input(array, (*x)*(*y));
    }
    return array;
}

int *ugly_number(int *a, int y, int x) {
    int xx = 0, cache = 0;
    for (int i = 0; i<y; i+=2) {
        xx = x-1;
        for (int u=0; u<x/2; ++u) {
            cache = a[u+i*y];
            a[u+i*y] = a[xx+i*y];
            a[xx+i*y] = cache;
            xx--;
        }
    }
    return a;
}

int main() {
    int max = 0, f = 0, x = 0, y = 0, *array;
    srand(time(NULL));

    array = read(&y, &x);

    array = ugly_number(array, y,x);
    print_mas(array, y,x);
    printf("\n");
    for(int i=0;i<x*y;i++) {
        if (array[i]>max) {
            max = array[i];
        }
    }
    for (int i = 0; i<y; i++) {
        for (int u=0; u<x; ++u) {
            if (array[i*x+u]==max) {
                if (f) {
                    printf(" ");
                }
                printf("%i",i+1);
                f = 1;
                break;
            }
        }
    }
    printf("\n");
    free(array);

    return 0;
}
