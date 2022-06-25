#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define FILE_FLAG 0

#define SIZE 25
#define char_size 25
#define buffer_size 200
//#define subject_size 10
//#define city_size 10

struct one_data {
    char name[char_size],surname[char_size],city[char_size],street[char_size],subject[char_size];
    int home,flat,score;
} array[SIZE];

int test(char a[char_size], char b[char_size]) {
    for (int i = 0; i<char_size; i++) {
        if (a[i]!=b[i]) {
            return 0;
        }
    }
    return 1;
}

void average(int size) {
    int sum=0,n=0,flag=0;
    for (int i = 0; i<size; i++) {
        sum = array[i].score;
        n = 1;
        flag = 0;
        for (int u = 0; u<i; u++) {
            if (test(array[i].subject,array[u].subject)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        for (int u = i+1; u<size; u++) {
            if (test(array[i].subject,array[u].subject)) {
                sum+=array[u].score;
                n++;
            }
        }
        for (int u = 0; u<char_size && array[i].subject[u]!=0; u++) {
            printf("%c",array[i].subject[u]);
        }
        printf(" %.1f\n",(float)sum/(float)n);
    }
}

void winers(int size) {
    int flag = 0;
    for (int i = 0; i<size; i++) {
        flag = 0;
        for (int u = 0; u<i; u++) {
            if (test(array[i].subject,array[u].subject)) {
                flag = 1;
                break;
            }
        }
        if (flag) {
            continue;
        }
        for (int u = 0; u<char_size && array[i].subject[u]!=0; u++) {
            printf("%c",array[i].subject[u]);
        }
        for (int u = 0; u<size; u++) {
            if (test(array[i].subject,array[u].subject)) {
                printf(" ");
                for (int uu = 0; uu<char_size && array[u].surname[uu]!=0; uu++) {
                    printf("%c",array[u].surname[uu]);
                }
            }
        }
        printf("\n");
    }
}

void cities(int size) {
    int flag = 0,max = 0,testing=0;
    for (int i = 0; i<size; i++) {
        testing = 1;
        for (int u = 0; u<i; u++) {
            if (test(array[i].city,array[u].city)) {
                testing++;
            }
        }
        if (testing>max) {
            max = testing;
        }
    }

    if (DEBUG) {
        printf("%d\n",max);
    }

    for (int i = 0; i<size; i++) {
        testing = 1;
        for (int u = i+1; u<size; u++) {
            if (test(array[i].city,array[u].city)) {
                testing++;
            }
        }
        if (testing==max) {
            if (flag) {
                printf(" ");
            }
            flag = 1;
            for (int u = 0; u<char_size && array[i].city[u]!=0; u++) {
                printf("%c",array[i].city[u]);
            }

        }
    }
    printf("\n");
}

int main() {
    int size = 0;
    char buffer[buffer_size];
    int counter = 0;
    int I = 0;
    int flag = 1;

    FILE *file;

    //struct one_data array[SIZE];
    for (int i = 0; i<SIZE; i++) {
        for (int u = 0; u<char_size; u++) {
            array[i].name[u] = 0;
            array[i].surname[u] = 0;
            array[i].city[u] = 0;
            array[i].street[u] = 0;
            array[i].subject[u] = 0;

        }
        array[i].home = 0;
        array[i].flat = 0;
        array[i].score = 0;
    }

    if (FILE_FLAG) {
        file = fopen("input.txt","r");
        fscanf(file, "%d", &size);
        fgets ( buffer, buffer_size, file);
    }
    else {
        scanf("%d",&size);
        gets(buffer);
    }

    if (DEBUG) {
        printf("size: %i\n",size);
    }

    for (int i = 0; i<size; i++) {
        if (FILE_FLAG) {
            fgets ( buffer, buffer_size, file);
        }
        else {
            gets(buffer);
        }
        if (DEBUG) {
            printf("%s",buffer);
        }
        counter = 0;
        flag = 1;
        for (int u = 0; u<buffer_size&&counter<8; u++) {
            if (buffer[u]==' ' || buffer[u]==0 || buffer[u]=='\n') {
                counter++;
                flag = 1;
                I = 0;
            }
            else if (counter==0) {
                array[i].surname[I] = buffer[u];
                I++;
            }
            else if (counter==1) {
                array[i].name[I] = buffer[u];
                I++;
            }
            else if (counter==2) {
                array[i].city[I] = buffer[u];
                I++;
            }
            else if (counter==3) {
                array[i].street[I] = buffer[u];
                I++;
            }
            else if (counter==6) {
                array[i].subject[I] = buffer[u];
                I++;
            }
            else if (counter==4) {
                if (flag) {
                    flag = 0;
                    array[i].home = array[i].home*10+(int)atoi(&buffer[u]);
                }
            }
            else if (counter==5) {
                if (flag) {
                    flag = 0;
                    array[i].flat = array[i].flat*10+(int)atoi(&buffer[u]);
                }
            }
            else if (counter==7) {
                if (flag) {
                    flag = 0;
                    array[i].score = array[i].score*10+(int)atoi(&buffer[u]);
                }
            }
        }
    }

    if (FILE_FLAG) {
        fclose(file);
    }

    if (DEBUG) {
        printf("==================================\n");
        for (int i = 0; i<size; i++) {
            for (int u = 0; u<char_size && array[i].surname[u]!=0; u++) {
                printf("%c",array[i].surname[u]);
            }
            printf(" ");
            for (int u = 0; u<char_size && array[i].name[u]!=0; u++) {
                printf("%c",array[i].name[u]);
            }
            printf(" ");
            for (int u = 0; u<char_size && array[i].city[u]!=0; u++) {
                printf("%c",array[i].city[u]);
            }
            printf(" ");
            for (int u = 0; u<char_size && array[i].street[u]!=0; u++) {
                printf("%c",array[i].street[u]);
            }
            printf(" %i ",array[i].home);
            printf("%i ",array[i].flat);
            for (int u = 0; u<char_size && array[i].subject[u]!=0; u++) {
                printf("%c",array[i].subject[u]);
            }
            printf(" %i\n",array[i].score);
        }

        printf("==================================\n");
    }

    average(size);
    printf("\n");
    winers(size);
    printf("\n");
    cities(size);
    /*for (int i = 0; i<size; i++) {
        if (array[i].cpu>=2000 && max<array[i].hdd-array[i].system_po-array[i].work_po) {
            max = array[i].hdd-array[i].system_po-array[i].work_po;
        }
    }
    for (int i = 0; i<size; i++) {
        if (max==array[i].hdd-array[i].system_po-array[i].work_po) {
            for (int u = 0; u<15&&array[i].name[u]!=' '; u++) {
                printf("%c",array[i].name[u]);
            }
            printf("\n");
        }
    }*/

    return 0;
}
