#include <stdio.h>
#include <stdlib.h>

double summand(double n) {
    return ((double)1)/(n*(n+1)) ;
}

void add(double n, double *S) {
    for (double N=1.0; N<=n; N+=1.0) {
        *S += summand(N);
    }
}

int main() {
    double sum = 0.0;
    int n = 0;
    scanf("%i", &n);
    add((double)n,&sum);
    printf("%.8f\n%.8f\n%.8f\n",1.0,sum,1.0-sum);
    return 0;
}
