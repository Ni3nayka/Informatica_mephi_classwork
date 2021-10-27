// add lib
#include <stdio.h>
#include <stdlib.h>

// main
int main()
{
    // declare variable
    int k,m,sum=0;
    // read from console
    scanf("%i", &m);
    // find k
    for (k=1;sum<m;k++) sum+=k*k;
    printf("%i\n\n",k-1);
    // printing table
    sum = 0;
    for (int i=1;i<100;i++) sum+=i*i;
    for (int i=100;i<=120;i++) printf("%i  %i\n",i,sum+=i*i);
    // end
    return 0;
}
