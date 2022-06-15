#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

#define SIZE 12

struct one_data {
    char name[15];
    int cpu,hdd,system_po,work_po;
};


int main() {
    int size = 0;
    char buffer[40];
    int counter = 0;

    struct one_data array[SIZE];
    for (int i = 0; i<SIZE; i++) {
        for (int u = 0; u<15; u++) {
            array[i].name[u] = ' ';
        }
        array[i].cpu = 0;
        array[i].hdd = 0;
        array[i].system_po = 0;
        array[i].work_po = 0;
    }

    scanf("%d",&size);
    if (DEBUG) {
        printf("size: %i\n",size);
    }

    gets(buffer);
    int flag = 1;
    for (int i = 0; i<size; i++) {
        gets(buffer);
        counter = 0;
        flag = 1;
        for (int u = 0; u<40&&counter<5; u++) {
            if (buffer[u]==' ' || buffer[u]==0) {
                counter++;
                flag = 1;
            }
            else if (counter==0) {
                array[i].name[u] = buffer[u];
            }
            else if (counter==1) {
                if (flag) {
                    flag = 0;
                    array[i].cpu = array[i].cpu*10+(int)atoi(&buffer[u]);
                }
            }
            else if (counter==2) {
                if (flag) {
                    flag = 0;
                    array[i].hdd = array[i].hdd*10+(int)atoi(&buffer[u]);
                }
            }
            else if (counter==3) {
                if (flag) {
                    flag = 0;
                    array[i].system_po = array[i].system_po*10+(int)atoi(&buffer[u]);
                }
            }
            else if (counter==4) {
                if (flag) {
                    flag = 0;
                    array[i].work_po = array[i].work_po*10+(int)atoi(&buffer[u]);
                }
            }
        }
    }

    if (DEBUG) {
        printf("================\n");
    }

    for (int i = 0; i<size; i++) {
        for (int u = 0; u<15; u++) {
            printf("%c",array[i].name[u]);
        }
        printf("%5i",array[i].cpu);
        printf("%5i",array[i].hdd);
        printf("%5i",array[i].system_po);
        printf("%5i",array[i].work_po);
        printf("\n");
    }
    printf("\n");

    printf("\n");

    return 0;
}
