#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
    scanf("%i %i %i %i %i %i",&A[0],&A[1],&A[2],&A[3],&A[4],&A[5]);
    //A[0]=2;A[1]=4;A[2]=3;A[3]=1;A[4]=3;A[5]=2;
    for (int i = 0; i < 6; i++) {
        printf("%6.2f",test(A,i));
    }
    printf("\n");
}
