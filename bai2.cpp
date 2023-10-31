#include <stdio.h>

int main() {
    float diem;
    printf("Nhap diem so: ");
    scanf("%f", &diem);

    if (diem >= 9 && diem <= 10) {
        printf("Hoc sinh xuat sac");
    } else if (diem >= 8 && diem < 9) {
        printf("Hoc sinh gioi");
    } else if (diem >= 6.5 && diem < 8) {
        printf("Hoc sinh kha");
    } else if (diem >= 5 && diem < 6.5) {
        printf("Hoc sinh trung binh");
    } else if (diem < 5 && diem >= 0) {
        printf("Hoc sinh yeu");
    } else {
        printf("Diem khong hop le");
    }

    return 0;
}
