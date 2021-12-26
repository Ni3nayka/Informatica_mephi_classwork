#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define V_pyramid(h,a) (1.0/3.0*(double)S_hexagon(a)*(double)h)
#define S_hexagon(a) (1.5*sqrt(3.0)*(double)a*(double)a)
#define abs(a) ((double)a>1.0?(double)a-1.0:1.0-(double)a)
#define pifagor(a,b) sqrt((double)((double)a*(double)a+(double)b*(double)b))
#define S_all(h,a) S_gerona((double)pifagor(h,a),(double)pifagor(h,a),(double)a)*6.0+(double)S_hexagon(a)

double S_gerona(double a, double b, double c) {
    double p = (a+b+c)/2.0;
    return sqrt((p)*(p-a)*(p-b)*(p-c));
}

int main() {
    double H=0.0,A=0.0,D=100.0,f=0.0,because_C_very_disgusting_language=0.0;
    for (double h=1;h<=50;h++)
        for (double a=2;a<=50;a++) {
            because_C_very_disgusting_language = S_all(h,a);
            f = (double)V_pyramid(h,a)/because_C_very_disgusting_language;
            if (D>abs(f)) {
                D = abs(f);
                H = h;
                A = a;
            }
        }
    printf("%.0f\n%.0f\n",H,A);
    return 0;
}
