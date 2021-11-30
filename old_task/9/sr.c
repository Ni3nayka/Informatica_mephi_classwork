#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long int convect_to_10(long int t) {
    int znak = t/abs(t);
    long int answer = 0;
    t *= znak;
    for (int i = 0; t>0; i++) {
        answer += (t%10)*pow(5,i);
        t /= 10;
    }
    answer *= znak;
    return answer;
}


long int convect_to_5(long int t) {
    int znak = t/abs(t);
    long int answer = 0;
    t *= znak;
    for (int i = 0; t>0; i++) {
        answer = answer*10+t%5;
        t /= 5;
    }
    t = answer;
    answer = 0;
    while (t>0) {
        answer = answer*10 + t%10;
        t /= 10;
    }
    answer *= znak;
    return answer;
}


int main() {
    long int a = 0, b = 0;
    scanf("%li", &a);
    scanf("%li", &b);
    printf("%li\n",convect_to_10(a));
    printf("%li\n",convect_to_5(b));
    return 0;
}
