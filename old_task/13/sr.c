#include <stdio.h>
#include <stdlib.h>

void print_array(int *A, int n) {
    for (int i=0; i<n; ++i) {
        printf("%3i",i+1);
    }
    printf("\n");
    for (int i=0; i<n; ++i) {
        printf("%3i",*(A+i));
    }
    printf("\n");
}

void write_array_to_file(int *A, int N) {
    FILE *file;
    file = fopen("output.txt","w");
    fprintf(file, "%i\n", N);
    for (int i = 0; i<N; i++) {
         fprintf(file, "%i ", A[i]);
    }
    fprintf(file, "\n");
    fclose(file);
}

int read_array_from_file(int *N) {
    int *A;
    FILE *file;
    file = fopen("input.txt","r");
    fscanf(file, "%i", N);
    A = (int *) malloc(*N * sizeof (int));
    for (int i = 0; i<*N; i++) {
         fscanf(file, "%i", &A[i]);
    }
    fclose(file);
    return A;
}

void del_region_from_array(int *A, int *N, int a, int b) {
    int *B;
    b++;
    for (int i = a; i<*N-b+a; i++) {
        A[i] = A[i+b-a];
    }
    *N = *N-b+a;
    B = (int *) realloc(A, *N * sizeof (int));
    if (B == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        A = B;
    }
}

void add_region_in_array(int *A, int *N, int a, int *b, int n_b) {
    int *B;
    a++;
    *N = *N+n_b;
    B = (int *) realloc(A, *N * sizeof (int));
    if (B == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        A = B;
    }
    for (int i = *N-1; i>a; i--) {
        A[i] = A[i-n_b];
    }
    for (int i = 0; i<n_b; i++) {
        A[i+a] = b[i];
    }
}


int generate_array(int N) {
    srand(time(NULL));
    int *A;
    A = (int *) malloc(N * sizeof (int));
    for (int i=0; i<N; ++i) {
        A[i] = rand()%10;
    }
    return A;
}

int main() {
int i=0,n=10,k=4,i1=3;
    int *array, *array_2;

    scanf("%d", &n);
    array = (double *) malloc(n * sizeof (double));
    for (i=0; i<n; ++i) {
        scanf("%d", &array[i]);
    }
    scanf("%d", &k);
    scanf("%d", &i1);

    if (array == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }

    print_array(array,n);
    printf("\n");

    for (i=k-1; i<n-1; ++i) {
        array[i] = array[i+1];
    }
    n--;
    array_2 = (int *) realloc(array, n * sizeof (int));
    if (array_2 == NULL) {
        printf("ERROR: memory");
        exit(EXIT_FAILURE);
    }
    else {
        array = array_2;
    }
    i1--;
    k = array[i1];
    array[i1] = array[0];
    array[0] = k;

    print_array(array,n);
    // WRITE FILE
    //write_array_to_file(array,n);
    free(array);

    // READ FILE
    /*array = read_array_from_file(&n);
    print_array(array,n);
    free(array);*/

    // DELETE IN ARRAY
    /*del_region_from_array(array, &n, 2,4);
    print_array(array, n);*/

    // ADD IN ARRAY
    /*int *add_array, size_add_array = 3;
    add_array = (int *) malloc(size_add_array * sizeof (int));
    add_array[0] = 3;
    add_array[1] = 45;
    add_array[2] = 89;
    print_array(add_array, size_add_array);
    print_array(array, n);
    add_region_in_array(array, &n, 2,add_array,size_add_array);
    print_array(array, n);
    free(array);
    free(array_2);*/

    return 0;
}
