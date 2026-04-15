#include<stdio.h>
void swaparrays(int *a,int *b,int n){
    for(int i=0;i<n;i++){
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
int main(){
    int n;
    printf("enter size:");
    scanf("%d",&n);

    int arr1[n],arr2[n];
    printf("enter first array:\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr1[i]);
    }

    printf("enter second array:\n");
    for(int i=0;i<n;i++){
    scanf("%d",&arr2[i]);
    }
    
    swaparrays(arr1,arr2,n);
    printf("\nafter swapping:\n");

    printf("\narray 1:\n");
    for(int i = 0; i < n; i++){
    printf("%d",arr1[i]);
    }
    printf("\narray 2:\n");
    for(int i = 0; i < n; i++){
    printf("%d",arr2[i]);
    }
    return 0;
}

