#include<stdio.h>

struct student{

int roll;
char name[10];
float marks;
};
int main(){
    struct student s;
    struct student *p=&s;
    printf("enter roll,name and marks:");
    scanf("%d %s %f", &p->roll, p->name, &p->marks);

    printf("\nstudent details:\n");
    printf("roll:%d\n",p->roll);
    printf("name:%s\n",p->name);
    printf("marks:%f\n",p->marks);

    return 0;
}

