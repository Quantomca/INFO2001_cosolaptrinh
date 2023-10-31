#include <stdio.h>
#include <math.h>

int main (){
	int a;
	int b;
    for (a = 2; a < 10; a++) {
        printf("bang cuu chuong cua %d\n", a);
        for (b = 1; b < 11; b++) {
            printf("%d x %d = %d\n", a, b, a * b);
        }
        printf("\n");
    }

    return 0;
}
