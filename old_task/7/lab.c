#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double array[41] = {0}, min=10.0, average=0.0, count_average = 0.0;
    for (double i=-10; i<=10; i+=0.5) {
        double new_data = 7*sin(0.4*i);
        array[(int)(i*2+20)] = new_data;
        if (new_data>0.0) {
            average+=new_data;
            count_average+=1.0;
        }
        if ((int)(abs(new_data)*2)%2==0 && min>new_data) min = new_data;
    }
    printf("%1.6f\n%1.6f\n",min,average/count_average);
}
