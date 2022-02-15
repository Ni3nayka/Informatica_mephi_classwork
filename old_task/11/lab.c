#include <stdio.h>

void print(int a[], int n) {
    for (int i=1;i<=n;i++) {
        printf("%5i",i);
    }
    printf("\n");
    for (int i=0;i<n;i++) {
        printf("%5i",a[i]);
    }
    printf("\n");
}

void completion(int m[], int n, int a, int b) {
    for (int i=0;i<n;i++) {
        m[i] = a*(i-b);
    }
}

int main() {
    int M1[14]={0};
    int M2[10]={0};

    int a1=0,b1=0,a2=0,b2=0;
    scanf("%i %i",&a1,&b1);
    scanf("%i %i",&a2,&b2);

    completion(M1,14,a1,b1);
    completion(M2,10,a2,b2);

    print(M1,14);
    printf("\n");
    print(M2,10);

    return 0;
}
