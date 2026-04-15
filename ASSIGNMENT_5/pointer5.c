#include<stdio.h>
int main(){
    int *a;
    float *b;
    char *c;
    double *d;

    printf("address =%p, size= %lu bytes\n" , &a ,sizeof(*a));
    printf("address =%p,size= %lu bytes\n" , &b, sizeof(*b));
    printf("address =%p,size= %lu bytes\n", &c ,sizeof(*c));
    printf("address =%p, size= %lu bytes\n", &d , sizeof(*d));

    return 0;
}
