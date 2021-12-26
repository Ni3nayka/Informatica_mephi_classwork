#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int ERROR = 0;
const long int MAX_NUMBER = 2147483647;
const long int MIN_NUMBER = -2147483648;

long my_plus(long int si_a, long int si_b) {
    if (ERROR) return 0;
    if (((si_b > 0) && (si_a > (MAX_NUMBER - si_b))) || ((si_b < 0) && (si_a < (MIN_NUMBER - si_b)))) {
        ERROR = 1;
        return 0;
    }
    else return si_a + si_b;
}

long int my_minus(long int si_a, long int si_b) {
    if (ERROR) return 0;
    if ((si_b > 0 && si_a < MIN_NUMBER + si_b) || (si_b < 0 && si_a > MAX_NUMBER + si_b)) {
        ERROR = 2;
        return 0;
    }
    else return si_a - si_b;
}

long int my_multiply(long int si_a, long int si_b) {
  if (ERROR) return 0;
  if (si_a > 0) {
    if (si_b > 0) {
      if (si_a > (MAX_NUMBER / si_b)) {
        ERROR = 3;
      }
    }
    else {
      if (si_b < (MIN_NUMBER / si_a)) {
        ERROR = 3;
      }
    }
  }
  else {
    if (si_b > 0) {
      if (si_a < (MIN_NUMBER / si_b)) {
        ERROR = 3;
      }
    }
    else {
      if ( (si_a != 0) && (si_b < (MAX_NUMBER / si_a))) {
        ERROR = 3;
      }
    }
  }

  if (ERROR) return 0;
  else return si_a * si_b;
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
    if (b==0) {
        ERROR = 5;
        return 0;
    }
    return a/b;
}

long int my_mod(long int a, long int b) {
    if (ERROR) return 0;
    if (b==0) {
        ERROR = 6;
        return 0;
    }
    return a-(a/b)*b;
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
    long int a = 0, b = 0;
    scanf("%li", &a);
    scanf("%li", &b);
    print(function_1(a,b));
    print(function_2(a,b));
    print(function_3(a,b));
    return 0;
}
