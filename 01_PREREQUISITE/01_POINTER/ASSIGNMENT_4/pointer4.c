#include<stdio.h>
int main(){
    char a[100],*p;
    int c=0,v=0;
    printf("enter string:\n");
    gets(a);

    p=a;
    while(*p!='\0')
    {
        if(*p=='A'||*p=='E'||*p=='I'||*p=='O'||*p=='U'||*p=='a'||*p=='e'||*p=='i'||*p=='o'||*p=='u')
        v++;
        else
        c++;
        p++;
    }
    printf("vowels=%d\nconsonents=%d",v,c);
    return 0;
}