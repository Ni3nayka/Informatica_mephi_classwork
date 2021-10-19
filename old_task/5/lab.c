#include <stdio.h>
#include <stdlib.h>

double summand(unsigned long int n) {
    return sqrt( (5+3*n) / ((double)(4+n)) );
}

void add_2(double n, double *S, double *fcor, double *cor, double *Scor) {
    for (unsigned long int N=n-20000000+1; N<=n; N++) {
        *fcor = summand(N) - *cor;
        *Scor = *S + *fcor;
        *cor = (*Scor - *S) - *fcor;
        *S = *Scor;
    }
}

void add_1(double n, double *S) {
    for (unsigned long int N=n-20000000+1; N<=n; N++) {
        *S += summand(N);
    }
}

int main() {
    double sum = 0.0;
    double S = 0.0, fcor = 0.0, cor = 0.0, Scor = 0.0;
    for (unsigned long int N=20000000; N<=200000000; N+=20000000) {
        add_1(N, &sum);
        add_2(N, &S, &fcor, &cor, &Scor);
        printf("%9i%18.4f%18.4f%10.4f\n",N,sum,S,sum-S);
    }
    return 0;
}
