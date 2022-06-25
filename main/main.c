#include <stdio.h>
#include <stdlib.h>

#define DEBUG 1
#define FILE_FLAG 1

#define SIZE 7
#define char_size 25

void print(int *a, int n) {
    int flag = 0;
    for (int i=0; i<n; i++) {
        if (*(a+i)==0) {
            if (flag==0) {
                printf("!\n");
                flag = 1;
            }
        }
        else {
            printf("%c",*(a+i));
        }
    }
    printf("\n");
}

int *mem(int rm) {
    int *massiv;
    massiv=(int*)calloc(rm,sizeof(char));
    return massiv;
}

int input(int size) {
    int *mas;
    mas = mem(size*char_size);

    FILE *file;
    char buffer[char_size];

    if (FILE_FLAG) {
        file = fopen("input.txt","r");
        //fscanf(file, "%d", &size);
        //fgets ( buffer, char_size, file);
    }
    //else {
        //scanf("%d",&size);
        //gets(buffer);
    //}

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
        for (int u = 0; u<char_size; u++) {
            mas[i*char_size+u] = buffer[u];
        }
    }

    if (FILE_FLAG) {
        fclose(file);
    }

    //for(int i=0;i<rm;i++) {
    //    scanf("%d",mas+i);
    //}
    return mas;
}

int *read(int *n) {
    int *array;
    if (DEBUG) {
        *n = rand()%5 + 5;
        array = mem(*n);
        for (int i=0; i<*n; ++i) {
            array[i] = rand()%10;
        }
    }
    else {
        scanf("%d", n);
        array = mem(*n);
        //input(array, *n);
    }
    return array;
}

int *read_1(int *n) {
    int test[8] = {19,15,12,10,8,4,4,3};
    int *array;
    *n = 8;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        array[i] = test[i];
    }
    return array;
}

int *read_2(int *n) {
    int test[7] = {1,4,7,8,15,15,16};
    int *array;
    *n = 7;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        array[i] = test[i];
    }
    return array;
}

int *operating(int *array_1,int n_1,int *array_2,int n_2,int *n) {
    int *array, n_11 = 0;
    *n = n_1 + n_2;
    n_2--;
    array = mem(*n);
    for(int i=0;i<*n;i++) {
        if (array_1[n_11]>=array_2[n_2] && n_11<n_1) {
            array[i] = array_1[n_11];
            n_11++;
        }
        else {
            array[i] = array_2[n_2];
            n_2--;
        }
    }
    return array;
}

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
    int *array;
    array = input(SIZE);
    print(array,SIZE*char_size);
    /*int size = 0;
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
