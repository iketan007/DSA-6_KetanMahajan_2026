#include<stdio.h>
#include<assert.h>
int divide(int a,int b){
    assert(b!=0);  //condition must be true
    return(a/b);
}
int main(){
    int a,b;
    int result;
    result=divide(10,2);
    printf("%d\n",result);
    result=divide(10,2);
    printf("%d\n",result);
    printf("\nprogram continuous");
}
//in this code error detected automatically and program stops 
//bug :we can catch bug immediately.
