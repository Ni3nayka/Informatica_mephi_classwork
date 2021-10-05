// add lib
#include <stdio.h>
#include <stdlib.h>

// function for count dividers and printing data for number 1
int test(int n) {
    printf("%i  ",n);
    int count = 0;
    for (int i=2;i<=n/2;i++) {
        if (n%i==0) {
            if (count>0) printf(",");
            if (count%4==0&&count>0) printf("\n     ");
            printf("%3i",i);
            count++;
        }
    }
    if (count) for (int i=(count-1)%4;i<3;i++) printf("    ");
    else printf("               ");
    printf("%6i\n",count);
    return count;
}

// main
int main()
{
    // declare variable
    int max_n = 0, min_count = 1000;
    // work loop
    for (int i=320;i<=350;i++) {
        // analyzing count divider
        int analyzing = test(i);
        if (analyzing>0&&analyzing<=min_count) {
            min_count = analyzing;
            max_n = i;
        }
    }
    // print answer for number 2
    printf("\n%i\n",max_n);
    // end
    return 0;
}
