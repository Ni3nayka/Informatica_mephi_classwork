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

int test_sort(int *a, int n) {
    for (int i=0; i<n-1; ++i) {
        if (*(a+i)>=*(a+i+1)) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n = 3,*array, cache = 0, flag = 1;
    array = read(&n);

    print(array, n);

    for (int i=0; i<n-1; ++i) {
        flag = 0;
        for (int u=1; u<n; ++u) {
            if (array[u-1]>array[u]) {
                flag = 1;
                cache = array[u-1];
                array[u-1] = array[u];
                array[u] = cache;
            }
        }
        printf("\n");
        print(array, n);
        if (test_sort(array, n)) {
            break;
        }
    }

    free(array);

    return 0;
}
