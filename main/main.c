#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int convect_to_10(long int t) {
    if (t==0) return 0;
    int znak = t>0?1:-1;
    long int answer = 0;
    t *= znak;
    for (int i = 0; t>0; i++) {
        answer += (t%10)*pow(5,i);
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
    for (int i = 0; t>0; i++) {
        answer += t%5*pow(10,i);
        printf("%li %li %li\n",t%5,(long int)pow(10,i),t%5*((long int)pow(10,i)));
        t /= 5;
    }
    /*t = answer;
    answer = 0;
    while (t>0) {
        answer = answer*10 + t%10;
        t /= 10;
    }*/
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
