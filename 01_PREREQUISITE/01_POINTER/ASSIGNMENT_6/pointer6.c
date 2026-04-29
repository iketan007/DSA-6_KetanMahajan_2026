#include<stdio.h>

int main(){
    int a,b,sum;
    int *p1,*p2;
    p1=&a;
    p2=&b;

    printf("enter two numbers\n");
    scanf("%d%d",p1,p2);
    sum=*p1+*p2;
    printf("sum of %d and %d is %d",*p1,*p2,sum);
    return 0;
}