#include<stdio.h>
int divide(int a, int b){
    if(b==0){
        return 0;
    }
    return(a/b);
}
int main(){
    int a,b;
    int result;
    result=divide(10,2);
    printf("%d",result);
    result=divide(10,2);
    printf("%d",result);
    printf("\nprogram continuous");
}