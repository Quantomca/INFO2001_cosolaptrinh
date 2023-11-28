#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

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

void sortByNames(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(arr[i].name, arr[j].name) > 0) {
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void sortByGrades(struct Student arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i].grade > arr[j].grade) {
                struct Student temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void searchByName(struct Student arr[], int n, const char *searchName) {
    printf("\nKet qua tim kiem theo ten '%s':\n", searchName);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (strcmp(arr[i].name, searchName) == 0) {
            displayStudent(arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ten '%s'.\n", searchName);
    }
}

void searchById(struct Student arr[], int n, int searchId) {
    printf("\nKet qua tim kiem theo ID '%d':\n", searchId);
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i].id == searchId) {
            displayStudent(arr[i]);
            found = 1;
        }
    }
    if (!found) {
        printf("Khong tim thay sinh vien co ID '%d'.\n", searchId);
    }
}

int main() {
    struct Student students[MAX_STUDENTS];
    int numStudents = 0;

    printf("Nhap thong tin sinh vien. Nhap '0' trong ma so de ket thuc.\n");

    while (1) {
        if (numStudents >= MAX_STUDENTS) {
            printf("Da vuot qua so luong toi da cho phep.\n");
            break;
        }

        printf("\nNhap thong tin cho sinh vien %d:\n", numStudents + 1);
        
        printf("Ten: ");
        fgets(students[numStudents].name, sizeof(students[numStudents].name), stdin);

        printf("Ma so (nhap 0 de ket thuc): ");
        scanf("%d", &students[numStudents].id);

        if (students[numStudents].id == 0) {
            break;
        }

        printf("Tuoi: ");
        scanf("%d", &students[numStudents].age);
        
        printf("Diem: ");
        scanf("%f", &students[numStudents].grade);

        getchar();
        
        numStudents++;
    }

    sortByNames(students, numStudents);
    printf("\nSap xep theo ten:\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudent(students[i]);
    }

    sortByGrades(students, numStudents);
    printf("\nSap xep theo diem:\n");
    for (int i = 0; i < numStudents; i++) {
        displayStudent(students[i]);
    }

    char searchName[50];
    int searchId;

    printf("\nNhap ten muon tim kiem: ");
    fgets(searchName, sizeof(searchName), stdin);
    searchName[strcspn(searchName, "\n")] = '\0'; 

    printf("Nhap ID muon tim kiem: ");
    scanf("%d", &searchId);

    searchByName(students, numStudents, searchName);
    searchById(students, numStudents, searchId);

    return 0;
}

