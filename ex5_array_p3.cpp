#include <stdio.h>

int main() {
    int Students;
    printf("Nhap so luong sinh vien trong lop: ");
    scanf("%d", &Students);

    float scores[Students];
    float totalScore = 0;

    for (int i = 0; i < Students; i++) {
        printf("Nhap diem cua sinh vien thu %d:\n", i + 1);
        printf("Diem so: ");
        scanf("%f", &scores[i]);

        totalScore += scores[i];
    }

    float average = totalScore / Students;
    printf("\nDiem trung binh cua lop la: %.2f\n", average);

    return 0;
}

