#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

//Khai bao struct
typedef struct{
    char hoten[100];
    char masv[100];
    char lop[100];
    double gpa;
}SinhVien;

//1. Ham nhap thong tin sinh vien
void Nhap(SinhVien *sv){
    getchar();
    printf("Nhap ho va ten sinh vien: ");
    fgets(sv->hoten, sizeof(sv->hoten), stdin);
    printf("Nhap ma sinh vien: ");
    fgets(sv->masv, sizeof(sv->masv), stdin);
    printf("Nhap lop sinh vien: ");
    fgets(sv->lop, sizeof(sv->lop), stdin);
    printf("Nhap diem GPA cua sinh vien: ");
    scanf("%lf", &sv->gpa);
}

//2. Ham in danh sach sinh vien
void Xuat(SinhVien sv){
    printf("%s %s %s %.2lf\n\n", sv.hoten, sv.masv, sv.lop, sv.gpa);
}

//3. Ham in nhung sinh vien co diem gpa cao nhat
void MaxGPA(SinhVien a[], int n){
    double max = 0;
    for(int i = 0; i < n; i++){
        max = fmax(max, a[i].gpa);
    }
    printf("Danh sach sinh vien co diem GPA cao nhat: \n");
    for(int i = 0; i < n; i++){
        if(a[i].gpa == max){
            Xuat(a[i]);
        }
    }
}

//4.Ham tim kiem sinh vien theo ma sinh vien
void Search(SinhVien a[], int n, char name[]){
    int find = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(name, a[i].masv) == 0){
            printf("Sinh vien can tim la: ");
            Xuat(a[i]);
            find = 1; // tim thay sinh vien
        }
    }
    if(!find){
        printf("Khong tim thay sinh vien!\n");
    }
}

//5.Ham xoa sinh vien theo ma sinh vien
void DeleteSV(SinhVien a[], int *n, char name[]){
    for(int i = 0; i < *n; i++){
        if(strcmp(a[i].masv, name) == 0){
            for(int j = i; j < *n - 1; j++){
                a[j] =  a[j + 1];
            }
            (*n)--;
        }
    }
}

int main(){
    SinhVien a[100];
    int n;
    
    printf("--------------Danh Sach Quan Ly Sinh Vien--------------\n");
    printf("1. Nhap danh sach sinh vien.\n");
    printf("2. In danh sach sinh vien.\n");
    printf("3. In danh sach nhung sinh vien co diem GPA cao nhat.\n");
    printf("4. Tim kiem sinh vien theo ma sinh vien.\n");
    printf("5. Xoa sinh vien theo ma sinh vien.\n");
    printf("0. Ket thuc MENU.\n");
    printf("-------------------------------------------------------\n");


    while(1){
        printf("Moi nhap lua chon: ");
        int choice;
        scanf("%d", &choice);
        char name[100];

        switch(choice){
            case 1:
                printf("Nhap so luong sinh vien: ");
                scanf("%d", &n);
                for(int i = 0; i < n; i++){
                    Nhap(&a[i]);
                }
                break;
            case 2:
                printf("Danh sach sinh vien: \n");
                for(int i = 0; i < n; i++){
                    Xuat(a[i]);
                }
                break;
            case 3:
                MaxGPA(a, n);
                break;
            case 4:
                getchar();
                printf("Nhap ma sinh vien can tim kiem: ");
                fgets(name, 100, stdin);
                Search(a, n, name);
                break;
            case 5:
                getchar();
                printf("Nhap ma sinh vien cua sinh vien can xoa: ");
                fgets(name, 100, stdin);
                DeleteSV(a, &n, name);
                break;
            case 0:
                printf("Ket thuc MENU!");
                exit(0);
                break;
        }
    }

    return 0;
}