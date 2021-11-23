#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define S(h,a) (double)(a*3*h)
#define S_o(a) ((double)3*sqrt((double)3)/(double)2*(double)a*(double)a)
#define V(h,a) ((double)1/(double)3*(double)S_o(a)*(double)h)
#define abs(a) (a>1.0?(double)a-1.0:1.0-a)

int main() {
    int H=0,A=0;
    double D=100.0,f=0.0;
    for (int h=1;h<=50;h++)
        for (int a=1;a<=50;a++) {
            f = V(h,a)/S(h,a);
            if (D>abs(f)) {
                D = abs(f);
                H = h;
                A = a;
            }
        }
    printf("%i\n%i\n",H,A);
    return 0;
}
