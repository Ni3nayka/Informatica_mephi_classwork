#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ERROR = 0;
const long int MAX_NUMBER = 2147483647;
const long int MIN_NUMBER = -2147483648;

long int my_abs(long int a) {
    return a>=0?a:-a;
}
long int my_sign(long int a) {
    return a==0?0:(a>0?1:-1);
}
long int my_sign_i(long int a) {
    return a==0?0:(a>0?-1:1);
}
long int escape_test(long int a,long int d) {
    return a==MAX_NUMBER&&d==1||a==MIN_NUMBER&&d==-1?1:0;
}

long int my_plus(long int a, long int b) {
    if (ERROR) return 0;
    if (a<=MAX_NUMBER-b) return a+b;
    ERROR = 1;
    return 0;
}

long int my_minus(long int a, long int b) {
    if (ERROR) return 0;
    if (a>=MIN_NUMBER+b) return a-b;
    ERROR = 2;
    return 0;
}

long int ksfjgsdfkjgdfkjgsjfgn(long int a, long int b) {
    return a==0||b==0?0:(a==1&&b==1||a==-1&&b==-1?1:-1);
}

long int my_multiply(long int a, long int b) {
    if (ERROR) return 0;
    if (b==0) return 1;
    else if (b==1) return a;
    long int znak = ksfjgsdfkjgdfkjgsjfgn(my_sign(a),my_sign(b));
    a = my_abs(a);
    b = my_abs(b);
    long int answer = a;
    for (;b>1&&ERROR==0;b--) answer = my_plus(answer,a);
    if (ERROR) ERROR = 3;
    else answer*=znak;
    return answer;
}

long int my_pow(long int a, long int b) {
    if (ERROR) return 0;
    if (b==0) return 1;
    else if (b==1) return a;
    long int answer = a;
    for (;b>1&&ERROR==0;b--) answer = my_multiply(answer,a);
    if (ERROR) ERROR = 4;
    return answer;
}

long int my_div(long int a, long int b) {
    if (ERROR) return 0;
    long int answer = 0;
    long int znak = ksfjgsdfkjgdfkjgsjfgn(my_sign(a),my_sign(b));
    a = my_abs(a);
    b = my_abs(b);
    for (;a>0;answer++) a = my_minus(a,b);
    if (a<0) answer--;
    if (ERROR) ERROR = 5;
    else answer*=znak;
    return answer;
}

long int my_mod(long int a, long int b) {
    if (ERROR) return 0;
    long int answer = my_minus(a,my_multiply(my_div(a,b),b));
    if (ERROR) ERROR = 6;
    return answer;
}

long int function_1(long int a, long int b) {
    return my_plus(my_minus(my_multiply(my_pow(a,2),b),my_multiply(b,my_minus(b,a))),b);
}

long int function_2(long int a, long int b) {
    return my_div(my_plus(my_pow(a,3),b),b);
}

long int function_3(long int a, long int b) {
    return my_mod(my_plus(a,my_pow(b,3)),a);
}

void print(long int a) {
    if (ERROR) printf("!%i\n",ERROR);
    else printf("%li\n",a);
    ERROR = 0;
}

int main() {
    long int a = 0, b = 0, test = 0;
    scanf("%li", &a);
    scanf("%li", &b);
    print(function_1(a,b));
    print(function_2(a,b));
    print(function_3(a,b));
    return 0;
}
