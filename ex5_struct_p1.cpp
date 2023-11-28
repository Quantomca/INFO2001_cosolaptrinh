#include <stdio.h>
#include <string.h>

struct Student {
    char name[50];
    int id;
    int age;
    float grade;
};

void displayStudent(struct Student s) {
    printf("\nThong tin sinh vien:\n");
    printf("Ten: %s\n", s.name);
    printf("Ma so: %d\n", s.id);
    printf("Tuoi: %d\n", s.age);
    printf("Diem: %.2f\n", s.grade);
}

int main() {
    struct Student s;
    int choice;

    printf("Nhap thong tin sinh vien:\n");
    printf("Nhap ten: ");
    fgets(s.name, sizeof(s.name), stdin);
    printf("Nhap ma so: ");
    scanf("%d", &s.id);
    printf("Nhap tuoi: ");
    scanf("%d", &s.age);
    printf("Nhap diem: ");
    scanf("%f", &s.grade);

    displayStudent(s);

    while (1) {
        printf("\nLua chon thao tac:\n");
        printf("1. Cap nhat thong tin sinh vien\n");
        printf("2. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nNhap thong tin moi cho sinh vien:\n");
                printf("Nhap ten: ");
                getchar();
                fgets(s.name, sizeof(s.name), stdin);
                printf("Nhap ma so: ");
                scanf("%d", &s.id);
                printf("Nhap tuoi: ");
                scanf("%d", &s.age);
                printf("Nhap diem: ");
                scanf("%f", &s.grade);
                displayStudent(s);
                break;
            case 2:
                printf("Ket thuc chuong trinh.\n");
                return 0;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
        }
    }

    return 0;
}

