#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

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
        *n = rand()%5 + 5;
        array = mem(*n);
        for (int i=0; i<*n; ++i) {
            array[i] = rand()%10;
        }
    }
    else {
        scanf("%d", n);
        array = mem(*n);
        input(array, *n);
    }
    return array;
}

int *read_1(int *n) {
    int test[8] = {19,15,12,10,8,4,4,3};
    int *array;
    *n = 8;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        array[i] = test[i];
    }
    return array;
}

int *read_2(int *n) {
    int test[7] = {1,4,7,8,15,15,16};
    int *array;
    *n = 7;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        array[i] = test[i];
    }
    return array;
}

int *operating(int *array_1,int n_1,int *array_2,int n_2,int *n) {
    int *array, n_11 = 0;
    *n = n_1 + n_2;
    n_2--;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        if (array_1[n_11]>=array_2[n_2] && n_11<n_1) {
            array[i] = array_1[n_11];
            n_11++;
        }
        else {
            array[i] = array_2[n_2];
            n_2--;
        }
    }
    return array;
}

int main() {
    int n = 0, n_1 = 0, n_2 = 0, *array_1, *array_2, *array;
    srand(time(NULL));

    array_1 = read(&n_1);
    array_2 = read(&n_2);
    array = operating(array_1,n_1,array_2,n_2,&n);

    print(array_1, n_1);
    print(array_2, n_2);
    print(array, n);

    free(array_1);
    free(array_2);
    free(array);

    return 0;
}
