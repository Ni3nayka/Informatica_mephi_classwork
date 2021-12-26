#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ERROR = 0;
const long int MAX_NUMBER = 2147483647;
const long int MIN_NUMBER = -2147483648;

long int my_plus(long int si_a, long int si_b) {
    if (ERROR) return 0;
    if (((si_b > 0) && (si_a > (MAX_NUMBER - si_b))) || ((si_b < 0) && (si_a < (MIN_NUMBER - si_b)))) {
        ERROR = 1;
        return 0;
    }
    else return si_a + si_b;
}

long int F(long int n_last_1, long int n_last_2, int i) {
    long int t = my_plus(n_last_1,n_last_2);
    // comment - the requirement of the second task
    //printf("%i) %i %i %i\n",i,n_last_1,n_last_2,t);
    if (ERROR) return 0;
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
        if (ERROR) printf("!\n");
        else printf("%i\n",n);
    }
    return 0;
}
