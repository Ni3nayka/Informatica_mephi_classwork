#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int F(long int n_last_1, long int n_last_2, int i) {
    long int t = n_last_1+n_last_2;
    // comment - the requirement of the second task
    //printf("%i) %i %i %i\n",i,n_last_1,n_last_2,t);
    if (t<n_last_2) return 0;
    else if (i==0) return t;
    else return F(n_last_2,t,i-1);

}

int main() {
    long int n=0;
    scanf("%i",&n);
    if (n==1) printf("1\n");
    else if (n==2) printf("3\n");
    else {
        n = F(1,3,n-3);
        if (n==0) printf("!\n");
        else printf("%i\n",n);
    }
    return 0;
}
