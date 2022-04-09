#include <stdio.h>

int main() {
    char line[100];
    int i = -1, counter = 0, flag = 1, counter_n = 0, max = 0, end_max;
    do {
        i++;
        line[i] = getchar();
    } while (line[i]!='\n');
    for (i=0;line[i]!='\n';i++) {
        if (isalpha(line[i])) {
            if (flag) {
                if (counter>0) {
                    putchar('\n');
                    if (counter_n>max) {
                        max = counter_n;
                        end_max = i;
                    }
                    counter_n = 0;
                }
                counter++;
                flag = 1;
            }
            counter_n++;
            putchar(line[i]);
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    putchar('\n');
    putchar('\n');
    for (int i = end_max-max-1; i<end_max-1; i++) {
        putchar(line[i]);
    }
    putchar('\n');
    return 0;
}
