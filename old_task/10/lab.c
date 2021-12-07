#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int F(unsigned long int n, unsigned long int m) {
    if (n%2==0) return n/2;
    if (n==1) return m;
    return F((n+1)/2,m+1);
}

int main() {
    unsigned long int n=0,m=0;
    scanf("%i",&n);
    scanf("%i",&m);
    printf("%i\n", F(n,m));
    return 0;
}
