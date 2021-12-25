#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V_pyramid(h,a) (1.0/3.0*(double)S_hexagon(a)*(double)h)
#define S_hexagon(a) ((double)3*sqrt((double)3)/(double)2*(double)a*(double)a)
#define abs(a) (a>1.0?(double)a-1.0:1.0-a)
#define pifagor(a,b) sqrt((double)(a*a+b*b))
#define S_all(h,a) S_gerona(pifagor(h,a),h,a)*6+S_hexagon(a)

double S_gerona(double a, double b, double c) {
    double p = (a+b+c)/2.0;
    return sqrt((p)*(p-a)*(p-b)*(p-c));
}

int main() {
    int H=0,A=0;
    double D=100.0,f=0.0;
    for (int h=1;h<=50;h++)
        for (int a=2;a<=50;a++) {
            f = V_pyramid(h,a)/S_all(h,a);
            if (D>abs(f)) {
                D = abs(f);
                H = h;
                A = a;
            }
        }
    printf("%i\n%i\n",H,A);
    return 0;
}
