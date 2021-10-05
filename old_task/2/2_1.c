// add lib
#include <stdio.h>
#include <stdlib.h>

// main
int main()
{
    // declare variable
    int x;
    // read from console
    scanf("%i", &x);
    if (x>=-25&&x<=17||x>=60) { // include
        if (x%2) printf("odd");
        else printf("even");
    }
    else printf("excluded"); // not include
    printf("\n");
    // end
    return 0;
}
