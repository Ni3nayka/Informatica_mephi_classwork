#include <stdio.h>

#define M1_N 5
#define M2_N 6
#define M3_N 8

void zero(int m[], int n) {
    for (int i=0;i<n;i++) {
        m[i] = 0;
    }
}

void input(int m[], int n) {
    for (int i=0;i<n;i++) {
        scanf("%i",&m[i]);
    }
}

void randoming(int m[], int n, int a, int b) {
    for (int i=0;i<n;i++) {
        m[i] = rand()%(b-a)+a;
    }
}

void print(int m[], int n) {
    for (int i=0;i<n-1;i++) {
        printf("%i ",m[i]);
    }
    printf("%i\n",m[n-1]);
}

int summary(int a[], int n) {
    int summ = 0;
    for (int i=0;i<n;i++) {
        summ += a[i];
    }
    return summ;
}

float average(int *mas, int *end) {
    int summ = 0;
    int i = 0;
    while (mas<end) {
        summ += *mas;
        mas++;
        i+=1;
    }
    return summ/(float)i;
}

bool test_number(int a[], int n) {

}

int main() {
    //int M1[M1_N]={0},M2[M2_N]={0},M3[M3_N]={0},a=0,b=0;
    int M1[M1_N]={14,12,13,10,12};
    int M2[M2_N]={10,14,12,10,12,15};
    int M3[M3_N]={13,12,11,15,11,14,11,13};
    int a=4,b=8;

    //input(M1,M1_N);
    //input(M2,M2_N);
    //input(M3,M3_N);
    //scanf("%i %i",&a,&b);

    printf("%i %i %i\n",summary(M1,M1_N),summary(M2,M2_N),summary(M3,M3_N));
    printf("%.1f\n",average(M3+a-1,M3+b-1));

    return 0;
}
