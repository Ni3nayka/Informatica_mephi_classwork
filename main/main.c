#include <stdio.h>

float test(int A[6], int n) {
    int sum = 0, count = 0;
    for (int i = 0; i < 6; i++) {
        if (A[i]<=A[n]) {
            count++;
            sum += A[i];
        }
    }
    return (float)sum/count;
}

int main() {
    int A[6] = {0};
    for (int i = 0; i < 6; i++) {
        scanf("%i",&A[i]);
    }
    for (int i = 0; i < 6; i++) {
        printf("%6.2f",test(A,i));
    }
    printf("\n");
}
