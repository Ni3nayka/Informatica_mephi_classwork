#include <stdio.h>
#include <stdlib.h>
#include <math.h>
double function(double x) {
    return x-log(x)-2;
}

double abs1(double x) {
    return x>0?x:-x;
}

int main() {
    double a=1.0,b=5.0,c=0.0;
    while (abs1(function((a+b)/2))>0.00000001) {
        c = (a+b)/2;
        if (function(c)<0) a = c;
        else b = c;
    }
    printf("%1.8f\n",(a+b)/2);
    return 0;
}
