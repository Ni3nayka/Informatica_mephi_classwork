#include <stdio.h>
#include <stdlib.h>

void add(unsigned long int n, double *sum) {
    *sum+=sqrt( (5+3*n) / ((double)(4+n)) );
}

int main() {
    double sum = 34640983.186792,S=34640984.919544;//0.0;
    //for (unsigned long int N=1; N<20000000; N++) add(N,&sum);
    //printf("%f\n",sum);
    for (unsigned long int N=20000000; N<=200000000; N+=20000000) {
        add(N,&sum);
        printf("%9i%18.4f%18.4f%10.4f\n",N,sum,S,sum-S);

    }
    return 0;
}
