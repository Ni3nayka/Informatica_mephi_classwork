// add lib
#include <stdio.h>
#include <stdlib.h>

// create a function
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))

// main
int main()
{
    // declare variable
    int a_in = 0, b_in = 0, a_out = 0, b_out = 0;
    // read from console
    scanf("%i\n%i",&a_in,&b_in);
    // sum number
    while (a_in) { a_out+=a_in%10; a_in/=10; }
    while (b_in) { b_out+=b_in%10; b_in/=10; }
    // write on console min answer
    printf("%i\n",min(a_out,b_out));
    // end
    return 0;
}
