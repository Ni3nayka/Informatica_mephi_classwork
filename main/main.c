#include <stdio.h>

int main() {
    const int N = 10;
    int A[10] = {0};
    int count = 0;
    for (int i = 0; i<10; i++) {
        scanf("%i",&A[i]);
    }
    for (int i = 0; i<10; i++) {
        count = 0;
        for (int u = 0; u<10; u++) {
            if (A[u]==A[i]) {
                count++;
            }
        }
        if (count==1) {
            printf("%4i",A[i]);
        }
        else {
            printf("   0");
        }
    }
    printf("\n");
    return 0;
}
