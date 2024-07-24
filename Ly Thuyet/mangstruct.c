#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char ten[100];
    char Masv[100];
    char lop[100];
    double gpa;
}SinhVien;

int main(){
    int n;
    printf("Nhap so luong sinh vien: ");
    scanf("%d", &n);
    SinhVien a[1000];
    for(int i = 0; i < n; i++){
        getchar();
        printf("Nhap ho va ten sinh vien %d: ", i + 1);
        gets(a[i].ten);
        printf("Nhap ma sinh vien: ");
        gets(a[i].Masv);
        printf("Nhap lop: ");
        gets(a[i].lop);
        printf("Nhap GPA cua sinh vien: ");
        scanf("%lf", &a[i].gpa);
    }
    printf("Danh sach sinh vien: \n");
    for(int i = 0; i < n; i++){
        printf("%s %s %s %.2lf\n", a[i].ten, a[i].Masv, a[i].lop, a[i].gpa); 
    }

    return 0;
}