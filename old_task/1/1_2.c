// add lib
#include <stdio.h>
#include <stdlib.h>

// main
int main()
{
    // declare variable
    int num_1, answer_1=0, n, a, d, s;
    // read from console
    scanf("%i", &num_1);
    scanf("%i %i %i", &n, &a, &d);
    // sum number
    while (num_1) { answer_1+=num_1%10; num_1/=10; }
    // calculate progression
    s = a;
    for(int i = 0; i<n-2; i++) { a+=d; s+=a; }
    // write on console min answer
    printf("%i\n\n%i\n%5i%5i%5i\n%5i%5i%5i\n", answer_1, s+a+d, n-1,n,n+1, a,a+d,a+2*d);
    // end
    return 0;
}
