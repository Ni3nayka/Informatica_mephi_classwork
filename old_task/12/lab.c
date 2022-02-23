#include <stdio.h>

int main() {
    char line[100];
    int i = -1, counter = 0, flag = 1;
    do {
        i++;
        line[i] = getchar();
    } while (line[i]!='\n');
    for (i=0;line[i]!='\n';i++) {
        if (isalpha(line[i])) {
            if (flag) {
                if (counter>0) {
                    putchar('\n');
                }
                counter++;
                flag = 1;
            }
            putchar(line[i]);
            flag = 0;
        }
        else {
            flag = 1;
        }
    }
    putchar('\n');
    putchar('\n');
    printf("%i\n",counter);
    return 0;
}
