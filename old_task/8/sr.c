#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
int function(double a, double c, double *S, double *P) {
    if (a<0||c<0) return 1;
    if (0==c||c==2*a) return 2;
    if (0>c||c>2*a) return 3;
    *P = (2*a + c)/2.0;
    *S = sqrt((*P)*(*P-a)*(*P-a)*(*P-c));
    *P *= 2.0;
    return 0;
}
*/

int function(double a, double b, double c, double *S, double *P) {
    if (a<0||b<0||c<0) return 1;
    if (a==b+c||b==c+a||c==a+b) return 2;
    if (a>b+c||b>c+a||c>a+b) return 3;
    *P = (a + b + c)/2.0;
    *S = sqrt((*P)*(*P-a)*(*P-b)*(*P-c));
    *P *= 2.0;
    return 0;
}

int main() {
    double a=0.0,b=0.0,c=0.0,S=0.0,P=0.0;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    const int answer = function(a,b,c,&S,&P);
    printf("%i\n",answer);
    if (answer==0) printf("%.6f\n%.6f\n",P,S);
    return 0;
}
