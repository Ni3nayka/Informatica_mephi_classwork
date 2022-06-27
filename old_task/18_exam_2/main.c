#include <stdio.h>

#define DEBUG 0
#define FILE_FLAG 0

#define SIZE 100
#define char_size 25

struct one_data {
    char name[char_size];
    int money;
} array[SIZE];

int read() {
    int size = 0, flag = 0;
    char buffer[char_size];
    FILE *file;
    for (int i = 0; i<SIZE; i++) {
        for (int u = 0; u<char_size; u++) {
            array[i].name[u] = 0;

        }
        array[i].money = 0;
    }

    if (FILE_FLAG) {
        file = fopen("input.txt","r");
        fscanf(file, "%d", &size);
        fgets ( buffer, char_size, file);
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
            fgets ( buffer, char_size, file);
        }
        else {
            gets(buffer);
        }
        if (DEBUG) {
            printf("%s",buffer);
        }
        flag = 0;
        for (int u = 0; u<char_size&&flag<2; u++) {
            if (buffer[u]==' ' || buffer[u]==0 || buffer[u]=='\n') {
                flag++;
            }
            else if (flag==0) {
                array[i].name[u] = buffer[u];
            }
            else if (flag==1) {
                array[i].money = array[i].money*10+(int)atoi(&buffer[u]);
                break;
            }
        }

    }
    if (DEBUG) {
        printf("\n==============\n");
    }
    return size;

}

void write_and_operating(int size) {

    char cache = 0;
    int money_cache = 0;

    for (int i = 0; i<size; i++) {
        for (int u = i+1; u<size; u++) {
            if (array[i].name[0]>array[u].name[0]) {
                money_cache = array[i].money;
                array[i].money = array[u].money;
                array[u].money = money_cache;
                for (int uu = 0; uu<char_size; uu++) {
                    cache = array[i].name[uu];
                    array[i].name[uu] = array[u].name[uu];
                    array[u].name[uu] = cache;
                }
            }
        }
    }

    for (int i = 0; i<size; i++) {
        if (array[i].money>50000) {
            for (int u = 0; u<char_size&&array[i].name[u]!=0; u++) {
                printf("%c",array[i].name[u]);
            }
            printf(" %d\n",array[i].money);
        }
    }
}

int main() {
    int size = read();
    write_and_operating(size);
    return 0;
}
