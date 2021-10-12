#include <stdio.h>
#include <stdlib.h>
int main() {
    int a[3],x,y,x1,temp;
    scanf("%i %i %i", &a[0], &a[1], &a[2]);
    scanf("%i %i", &x, &y);
    for (int i=0; i<3; i++) {
        for (int j=0; j<3-i; j++) {
            if (a[j]>a[j+1]) {
                temp=a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
    if (a[0]==a[1]&&a[1]==a[2]) printf("equal\n");
    else {
        if (a[1]==a[2]) printf("%i two\n",a[2]);
        else printf("%i\n",a[2]);
    }
    x1 = sqrt(abs(250*250-y*y));
    x = abs(x);
    if (x<250&&x>0 && (y>0&&y<250&&x>x1 || y<0&&y>-250&&x<x1&&x>y+250)) printf("inside\n");
    else printf("outside\n");
    return 0;
}
