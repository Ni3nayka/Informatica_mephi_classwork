#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int pow1(long int a, long int b) {
    if (b==0) return 1;
    else if (b==1) return a;
    long int answer = a;
    for (;b>1;b--) answer *= a;
    return answer;
}

long int convect_to_10(long int t) {
    if (t==0) return 0;
    int znak = t>0?1:-1;
    long int answer = 0;
    t *= znak;
    for (long int i = 0; t>0; i++) {
        answer += (t%10)*pow1(5,i);
        t /= 10;
    }
    answer *= znak;
    return answer;
}

long int convect_to_5(long int t, int *test) {
    if (t==0) return 0;
    int znak = t>0?1:-1;
    long int answer = 0;
    t *= znak;
    if (t>4687499) { *test = 0; return 0; }
    for (long int i = 0; t>0; i++) {
        answer += t%5*pow1(10,i);
        //printf("%li %li %li\n",t%5,pow1(10,i),t%5*pow1(10,i));
        t /= 5;
    }
    answer *= znak;
    return answer;
}


int main() {
    long int a = 0, b = 0;
    int test = 1;
    scanf("%li", &a);
    scanf("%li", &b);
    printf("%li\n",convect_to_10(a));
    b = convect_to_5(b,&test);
    if (test) printf("%li\n",b);
    else printf("%!\n");
    return 0;
}
