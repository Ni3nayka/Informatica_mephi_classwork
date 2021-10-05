// add lib
#include <stdio.h>
#include <stdlib.h>

// main
int main()
{
    // declare variable
    int a[3],x,y;
    // read from console
    scanf("%i %i %i", &a[0], &a[1], &a[2]);
    scanf("%i %i", &x, &y);
    // number 1
    // sort
    for (int i = 0; i <3;i++) {
        for (int j=0;j<3-i;j++) {
            if (a[j]>a[j+1]) {
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    if (a[0]==a[1]&&a[1]==a[2]) printf("equal");
    else {
        if (a[1]==a[2]) printf("%i two\n",a[2]);
        else printf("%i\n",a[2]);
    }
    // number 2
    int x1 = sqrt(abs(250*250-y*y));
    //printf("%lf\n",x1);
    /*x = abs(x);
    if (x<250&&x>0) {
        if (y>0&&y<250) {
            if (x>x1) printf("inside\n");
            else printf("outside\n");
        }
        else if (y<0&&y>-250) {
            if (x<x1&&x>y+250) printf("inside\n");
            else printf("outside\n");
        }
        else printf("outside\n");
    }
    else printf("outside\n");*/
    x = abs(x);
    if (x<250&&x>0 && (y>0&&y<250&&x>x1 || y<0&&y>-250&&x<x1&&x>y+250)) printf("inside\n");
    else printf("outside\n");
    // end
    return 0;
}
