#include <stdio.h>
#include <stdlib.h>


int main() {
    char a[2][3] = {1,2,3,4,5,6};
    printf("%i\n",&a[4]);
    printf("%i\n",a+4);
    //printf("%i\n",*(a+1);
    printf("%i\n",*a+2);
    printf("%i\n",*(a[1]+1)+2);
    printf("%i\n",a[1]+1);
    printf("%i\n",*a[1]+2);

    return 0;
}
