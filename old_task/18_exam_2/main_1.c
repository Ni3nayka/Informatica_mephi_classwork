#include <stdio.h>

int main() {
    int n,k;
    scanf("%d",&n);
    scanf("%d",&k);

    int **mas;
    mas = (int**)calloc(n,sizeof(int*));
    for (int i = 0; i<n; i++) {
        mas[i] = (int*)calloc(n,sizeof(int));
    }

    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            scanf("%d",&mas[y][x]);
        }
    }


    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            printf("%6d",mas[y][x]);
        }
        printf("\n");
    }
    printf("\n");

    int max = 0;
    int max_y = 0;
    int test = 0;
    for (int y = 0; y<n; y++) {
        test = 0;
        for (int x = 0; x<n; x++) {
            test+=mas[y][x];
        }
        if (test>max) {
            max = test;
            max_y = y;
        }
    }
    k--;
    for (int x = 0; x<n; x++) {
        test = mas[k][x];
        mas[k][x] = mas[max_y][x];
        mas[max_y][x] = test;
    }


    for (int y = 0; y<n; y++) {
        for (int x = 0; x<n; x++) {
            printf("%6d",mas[y][x]);
        }
        printf("\n");
    }
    return 0;
}
