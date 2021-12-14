#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int function(double a, double b, double c, double *S, double *P) {
    if (a<0||b<0||c<0) return 1;
    if (a>b+c||b>c+a||c>a+b) return 3;
    *P = (a + b + c)/2.0;
    if (a==b+c||b==c+a||c==a+b) *S=0;
    else *S = sqrt((*P)*(*P-a)*(*P-b)*(*P-c));
    *P *= 2.0;
    if (a==b+c||b==c+a||c==a+b) return 2;
    return 0;
}

int main() {
    double a=0.0,b=0.0,c=0.0,S=0.0,P=0.0;
    scanf("%lf",&a);
    scanf("%lf",&b);
    scanf("%lf",&c);
    const int answer = function(a,b,c,&S,&P);
    printf("%i\n",answer);
    if (answer==0||answer==2) printf("%.6f\n%.6f\n",P,S);
    return 0;
}
