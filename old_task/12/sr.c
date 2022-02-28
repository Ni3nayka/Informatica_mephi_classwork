#include <stdio.h>
#include <stdlib.h>

int number(char a) {
    if (a=='1') return 1;
    if (a=='2') return 2;
    if (a=='3') return 3;
    if (a=='4') return 4;
    if (a=='5') return 5;
    if (a=='6') return 6;
    if (a=='7') return 7;
    if (a=='8') return 8;
    if (a=='9') return 9;
    return 0;
}

int main() {
    int sum[30] = {0};
    int flag = 0;
    int cache = 0;
    char input = 0;
    int min = 999999;
    for (int i=0;i<30;i++) {
        sum[i] = 1000000;
    }
    //FILE *file;
    /*file = fopen("test.txt","w");
    srand(time(NULL));
    for (int i = rand()%30;i>=0;i--) {
        for (int u = rand()%20;u>0;u--) {
            fprintf(file, "%i ", rand()%999999);
        }
        fprintf(file, "%i\n", rand()%999999);
    }
    fprintf(file, "\n\n");
    fclose(file);*/

    //file = fopen("test.txt","r");
    for (int i=0;flag!=2;i++) {
        sum[i] = 0;
        while (flag!=3) {
            //input = getc(file);
            input = getchar();
            if (input=='\n') {
                flag++;
                if (flag!=2) {
                    sum[i] += cache;
                    cache = 0;
                }
                break;
            }
            else {
                flag = 0;
                if (input==' ') {
                    sum[i] += cache;
                    cache = 0;
                }
                else {
                    cache = cache*10+number(input);
                }
            }
        }
        if (flag==2) {
            sum[i] = 1000000;
        }
    }
    input = getchar();
    //fclose(file);

    for (int i=0;i<30;i++) {
        if (sum[i]<min) {
            min = sum[i];
        }
    }
    flag = 0;
    for (int i=0;i<30;i++) {
        if (sum[i]==min) {
            if (flag>0) {
                printf(" ");
            }
            else {
                flag++;
            }
            printf("%i",i+1);
        }
    }
    printf("\n");
    //fclose(file);
    return 0;
}
