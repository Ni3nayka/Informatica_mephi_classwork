#include <stdio.h>
#include <stdlib.h>

void print(int *a, int n) {
    for (int i=0; i<n; ++i) {
        printf("%3i",i+1);
    }
    printf("\n");
    for (int i=0; i<n; ++i) {
        printf("%3i",*(a+i));
    }
    printf("\n");
    printf("\n");
}

void output_to_file(int *A, int N) {
    FILE *file;
    file = fopen("output.txt","w");
    fprintf(file, "%i\n", N);
    for (int i = 0; i<N; i++) {
         fprintf(file, "%i ", A[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}

int input_to_file() {
    int *A, N;
    FILE *file;
    file = fopen("input.txt","r");
    fscanf(file, "%i", &N);
    A = (int *) malloc(N * sizeof (int));
    for (int i = 0; i<N; i++) {
         fscanf(file, "%i", &A[i]);
    }
    fclose(file);
    print(A,N);
    return A;
}

int generate_array(int N) {
    srand(time(NULL));
    int *array;
    array = (int *) malloc(N * sizeof (int));
    for (int i=0; i<N; ++i) {
        array[i] = rand()%10;
    }
    return array;
}

int operating(int *A, int N, int n) {
    int *save, I = 0;
    save = (int *) malloc(2*n  * sizeof (int));
    if (save == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        for (int i = 2*n-1; i>=n; i--) {
            save[I] = A[i];
            I++;
        }
        for (int i = 0; i<=n; i++) {
            save[I] = A[i];
            I++;
        }
        return save;
    }
}

void array_del_size(int *A, int *N, int a, int b) {
    int *save;
    b++;
    for (int i = a; i<*N-b+a; i++) {
        A[i] = A[i+b-a];
    }
    *N = *N-b+a;
    save = (int *) realloc(A, *N * sizeof (int));
    if (save == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        A = save;
    }
}

void array_add_size(int *A, int *N, int a, int *b, int n_b) {
    int *save;
    a++;
    *N = *N+n_b;
    save = (int *) realloc(A, *N * sizeof (int));
    if (save == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        A = save;
    }
    for (int i = *N-1; i>a; i--) {
        A[i] = A[i-n_b];
    }
    for (int i = 0; i<n_b; i++) {
        A[i+a] = b[i];
    }
}

int main() {
    int N = 9, n = 2, *array, *answer;

    array = generate_array(N);
    print(array, N);
    //input_to_file();
    //output_to_file(array, N);
    answer = operating(array, N, n);
    print(answer, 2*n);

    array_del_size(array, &N, 2,4);
    print(array, N);

    int *add_array, size_add_array = 3;
    add_array = generate_array(size_add_array);
    print(add_array, size_add_array);
    array_add_size(array, &N, 2,add_array,size_add_array);
    print(array, N);

    return 0;
}
