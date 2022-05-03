#include <stdio.h>
#include <stdlib.h>

#define DEBUG 0

//============================ String ========================================

struct String {
    char *data;
    int size;
};

struct String mem_1(n) {

}

//============================ Vec ========================================

struct Vec {
    int *data;
    int size;
};

//============================ main ========================================

struct one_data {
    struct String name;
    struct Vec data;
};

int *read(int *n) {
    /*int *array;
    if (DEBUG) {
        *n = rand()%3 + 3;
        array = mem((*n)*(*n));
        for (int i=0; i<(*n)*(*n); ++i) {
            array[i] = rand()%10;
        }
    }
    else {
        scanf("%d", n);
        array = mem((*n)*(*n));
        input(array, (*n)*(*n));
    }
    return array;*/
}

int main() {
    char m[3][2] = {1,2,3,4,5,6};

    printf("%i\n",*m[1]);
    printf("%i\n",*m+2);
//    printf("%i\n",);

    return 0;
}
