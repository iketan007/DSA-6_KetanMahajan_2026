#include<stdio.h>
int main()
{
    char str[100];
    char *p;
    printf("enter string:");
    fgets(str, sizeof(str), stdin);
    p=str;
    printf("String is:\n");
    for(; *p !='\0';p++)
    {
        printf("%c", *p);
    }
    return 0;
}
