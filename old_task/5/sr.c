#include <stdio.h>
#include <stdlib.h>

double summand(unsigned long int n) {
    return ((double)1)/(n*(n+1)) ;
}

void add(int n, double *S) {
    for (int N=1; N<=n; N++) {
        *S += summand(N);
        //printf("%i %0.16f\n",N,summand(N));
    }
}

int main() {
    double sum = 0.0;
    int n = 0;
    scanf("%i", &n);
    add(n,&sum);
    printf("%.8f\n%.8f\n%.8f\n",1.0,sum,1.0-sum);
    return 0;
}
