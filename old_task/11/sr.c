#include <stdio.h>

#define M1_N 5
#define M2_N 6
#define M3_N 8
#define num_N 6

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
    return summ/(float)(i+1);
}

void test_number(int a[], int n, int *list) {
    for (int i=0;i<n;i++) {
        *(list+a[i]-10) = 1;
    }
}

int main() {
    int M1[M1_N]={0},M2[M2_N]={0},M3[M3_N]={0},a=0,b=0;
    int test_1[num_N]={0},test_2[num_N]={0},test_3[num_N]={0},flag=0;

    input(M1,M1_N);
    input(M2,M2_N);
    input(M3,M3_N);
    scanf("%i %i",&a,&b);

    printf("%i %i %i\n",summary(M1,M1_N),summary(M2,M2_N),summary(M3,M3_N));
    printf("%.1f\n",average(M3+a-1,M3+b));

    test_number(M1,M1_N,test_1);
    test_number(M2,M2_N,test_2);
    test_number(M3,M3_N,test_3);

    for (int i=0;i<num_N;i++) {
        if (test_1[i]&test_2[i]&test_3[i]==1) {
            if (flag==1) {
                printf(" ");
            }
            printf("%i",i+10);
            flag = 1;
        }
    }
    printf("\n");

    return 0;
}

