#include <stdio.h>
#include <math.h>

int main() {
    int a;
    printf("Nhap gia tri a:");
    scanf("%d", &a);
    if (a%2==0){
        printf("a la so chan\n");
    } else {
        printf("a la so le\n");
    }
    
    return 0;
}
