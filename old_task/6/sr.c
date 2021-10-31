#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double function(double x) {
    return sin(x)-2.0/5.0;
}

double abs1(double x) {
    return x>0?x:-x;
}

double add(double xs, double x, double n) {
    return (-1)*xs*x*x/((double)(n*(n-1)));
}

int main() {
    double a=2.0,b=4.0,c=0.0,x0=0.0;
    while (abs1(function((a+b)/2))>0.0000001) {
        c = (a+b)/2.0;
        if (function(c)>0) a = c;
        else b = c;
    }
    x0 = (a+b)/2;
    printf("%1.7f\n",x0);
    double sum = 0.0,xn=0.0;
    xn=x0; sum=x0;
    for (int i=3;i<200;i+=2) {
        xn = add(xn,x0,i);
        sum += xn;
    }
    printf("%1.6f\n",sum);
    return 0;
}
