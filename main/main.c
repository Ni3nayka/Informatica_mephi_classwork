#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int f(int a) {
    int b;
    b = 2*f(a-1);
    if (a<=0) return 1;
    else return b;
}

int main() {
    int a=27,b=2,x;
    x = f(3);
    printf("%i",x);
    return 0;
}
