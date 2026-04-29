#include<stdio.h>
struct student{
    char name[10];
    int rollno;
    int standard;
    char division;
};

int main(){
    struct student s;
    printf("enter name:");
    scanf("%[^\n]",s.name);

    printf("enter rollno:");
    scanf("%d",&s.rollno);

    printf("enter standard:");
    scanf("%d",&s.standard);

    printf("enter division:");
    scanf(" %c",&s.division);
    
    printf("\n=============student details============\n");
    printf("name :%s\n",s.name);
    printf("rollno :%d\n",s.rollno);
    printf("standard :%d\n",s.standard);
    printf("division :%c\n",s.division);
    
    return 0;

}