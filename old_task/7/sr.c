#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define len 40
int main() {
    int array[len] = {0}, m=0, a=5, count=0;
    /*int range_min=0, range_max=0;
    scanf("%i", &range_min);
    scanf("%i", &range_max);
    for (int i=0; i<len; i++) array[i] = rand()%(range_max-range_min+1)+range_min;
    for (int i=0; i<len; i++) printf("%i %i\n", i+1, array[i]);*/
    for (int i=0; i<len; i++) scanf("%i", &array[i]);
    scanf("%i", &a);
    for (int i=0; i<len; i++)
        if (array[i]>a) {
            m += array[i];
            count++;
        }
    printf("%.4f\n",(double)m/(double)count);
    m/=count;
    count = 0;
    for (int i=0; i<len; i++)
        if (array[i]>m) count++;
    printf("%i\n",count);
    /*int *p; p = array;
    for (int i=0; i<len; i++) scanf("%i", &(*(p+i)));
    scanf("%i", &a);
    for (int i=0; i<len; i++)
        if (*(p+i)>a) {
            m += *(p+i);
            count++;
        }
    printf("%.4f\n",(double)m/(double)count);
    m/=count;
    count = 0;
    for (int i=0; i<len; i++)
        if (*(p+i)>m) count++;
    printf("%i\n",count);*/
    return 0;
}
