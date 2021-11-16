#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define len 40
int main() {
    int i, m[7], x;
    for (i=0; i<7; ++i)
        m[i]=i/3+1;
    x = m[m[2]+m[6]];
    printf("%d ", x);//*(m+i)-*(m+i-1));
    return 0;
}
