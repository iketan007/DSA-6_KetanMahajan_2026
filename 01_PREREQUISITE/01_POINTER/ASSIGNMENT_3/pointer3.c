#include<stdio.h>
int main(){
    int a[100],n;
    int *p;
    printf("enter the number of elements:");
    scanf("%d",&n);

    printf("enter elements:\n");
    for(int i=0 ; i<n ; i++){
        scanf("%d",&a[i]);
    }
    p=a;
    printf("\nelement with addresses:\n");
    for(int i=0; i<n ; i++){
         printf("Value = %d\tAddress = %p\n", *(p + i), (p + i));
    }
    return 0;
}