// add lib
#include <stdio.h>
#include <stdlib.h>

// main
int main()
{
    // declare variable
    long int last_sum=0,sum;
    int k, n=-1, error=0;
    // read from console
    scanf("%i", &k);
    // operating
    while (!error) {
        n++;
        sum = 0;
        for (int u=1;u<=k&&(!error);u++) {
            // �������� � �������
            long int k_n = u; // k � ������� n
            if (!n) k_n = 1; // 0-���� �������
            else {
                for (int i=1;i<n&&(!error);i++) {
                    long int k_n_s = k_n; // ��� ��������� �������
                    //k_n*=u;
                    for (int w=1;w<u&&(!error);w++) { // k_n*=u;
                        k_n+=k_n_s;
                        if (k_n<0) error = 1;
                    }
                    //if (k_n<0) error = 1;
                }
            }
            //printf("%i+",k_n);
            // ���������
            if (!error) {
                sum+=k_n;
                if (sum<0) error = 2;
            }
        }
        //printf("\n");
        if (!error)last_sum = sum;
    }
    //printf("========================\n");
    // output
    printf("%i\n",last_sum);
    printf("%i\n",n?n-1:n); // ���� ������� �������, �� �������� ������� "������������"
    if (error==1) printf("*\n");
    else printf("+\n");
    // end
    return 0;
}
