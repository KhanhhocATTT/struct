#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    char ten[100];
    char lop[100];
    double gpa;
}SinhVien;

int main(){
    SinhVien x;
    printf("Ho va ten sinh vien: ");
    gets(x.ten);
    printf("Sinh vien lop: ");
    gets(x.lop);
    printf("GPA cua sinh vien: ");
    scanf("%lf", &x.gpa);
    printf("%s %s %.2lf", x.ten, x.lop, x.gpa);

    return 0;
}