#include <stdio.h>
#include <stdlib.h>
struct Student {
    char name[50];
    int roll_no;
    char standard[10];
    char division;
};
int main() {
    struct Student *s;
    s = (struct Student*)malloc(sizeof(struct Student));

    if (s == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }
    printf("Enter Student Name: ");
    scanf(" %[^\n]", s->name);

    printf("Enter Roll No: ");
    scanf("%d", &s->roll_no);

    printf("Enter Standard: ");
    scanf("%s", s->standard);

    printf("Enter Division: ");
    scanf(" %c", &s->division);
    
    printf("\n--- Student Details ---\n");
    printf("Name     : %s\n", s->name);
    printf("Roll No  : %d\n", s->roll_no);
    printf("Standard : %s\n", s->standard);
    printf("Division : %c\n", s->division);
    free(s);
    return 0;
}