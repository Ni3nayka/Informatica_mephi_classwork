#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0
#define FILE_FLAG 0

#define SIZE 7
#define char_size 25
#define alphabet_size 26

#define abs(a) a>0?a:-a

void print(char **a) {
    if (DEBUG) {
        printf("======================================\n");
    }
    for (int i=0; i<SIZE; i++) {
        for (int u = 0; u<char_size; u++) {
            if (a[i][u]=='\n' || a[i][u]=='\0') {
                break;
            }
            putchar(a[i][u]);
        }
        printf("\n");
    }
    if (DEBUG) {
        printf("======================================\n");
    }
}

char **mem(int a, int b) {
    char **massiv;
    massiv=(char**)calloc(a,sizeof(char*));
    for (int i = 0; i<a; i++) {
        massiv[i] = (char*)malloc(b*sizeof(char));
        for (int u = 0; u<b; u++) {
          massiv[i][u] = 0;
        }
    }
    return massiv;
}

char **input() {
    char **array;
    FILE *file;
    char buffer[char_size];

    array = mem(SIZE,char_size);

    if (FILE_FLAG) {
        file = fopen("input.txt","r");
    }

    for (char i = 0; i<SIZE; i++) {
        if (FILE_FLAG) {
            fgets ( buffer, char_size, file);
        }
        else {
            gets(buffer);
        }

        if (DEBUG) {
            printf("%s",buffer);
            for (int u = 0; u<char_size && buffer[u]!='\n' && buffer[u]!='\0'; u++) {
                putchar(buffer[u]);
            }
        }
        for (int u = 0; u<char_size; u++) {
            array[i][u] = buffer[u];
        }

        if (DEBUG) {
            printf("!!\n");
        }
    }

    if (FILE_FLAG) {
        fclose(file);
    }

    return array;
}

void print_alphabet(char **array_start) {
    char **array,*cache;
    int test = 0;
    array = (char**)calloc(SIZE,sizeof(char*));
    for (char i = 0; i<SIZE; i++) {
        array[i] = array_start[i];
    }

    for (char i = 0; i<SIZE; i++) {
        for (int u = i+1; u<SIZE; u++) {
            if (array[i][0]>array[u][0]) {
                cache = array[i];
                array[i] = array[u];
                array[u] = cache;
            }
        }
    }

    print(array);
    printf("\n");

    for (char i = 0; i<SIZE; i++) {
        if (abs(SIZE-i-1-i)<abs(SIZE-test-1-test)) {
            test = i;
        }
    }
    printf("A-%c %i\n%c-Z %i\n",array[test][0],test+1,array[test+1][0],SIZE-test-1);

    free(array);
}

void clear(char **array) {
    for (int i = 0; i<SIZE; i++) {
        free(array[i]);
    }
    free(array);
}


int main() {
    char **array;

    array = input();
    print_alphabet(array);

    clear(array);
    return 0;

}

