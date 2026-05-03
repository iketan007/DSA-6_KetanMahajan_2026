#include<stdio.h>
#include<stdlib.h>

struct student{
    char name[10];
    int rollno;
    int standard;
    char division;
    struct student *next;   
};
int main(){
    struct student *head=NULL,*temp,*new;
    int n, i;

    printf("enter number of students:");
    scanf("%d",&n);

    for(i=0;i<n;i++){
        new=(struct student*)malloc(sizeof(struct student));

        printf("\nEnter details of student %d\n", i + 1);
       
        printf("name:");
        scanf(" %[^\n]",new->name);

        printf("rollno:");
        scanf("%d",&new->rollno);

        printf("standard:");
        scanf("%d",&new->standard);

        printf("division:");
        scanf(" %c",&new->division);
        new->next=NULL;


        if(head==NULL){
            head=new;
        }else{
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=new;
        }
    }
    printf("\nstudent linked list\n");
    temp=head;
    while(temp!=NULL){
        printf("\nname :%s",temp->name);
        printf("\nrollno :%d",temp->rollno);
        printf("\nstandard :%d",temp->standard);
        printf("\ndivision :%c\n",temp->division);
        temp=temp->next;
    }
     return 0;

}