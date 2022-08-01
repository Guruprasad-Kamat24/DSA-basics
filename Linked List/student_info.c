#include<stdio.h>
#include<stdlib.h>
struct student{
int id;
char name[10];
struct student *next;
};
typedef struct student *node;
node getnode();
node insert(head);
node display(head);
node insert_pos(head,pos);
int delete_beg(head);
node find(node head);
void main()
{
    node head=NULL;
    int n,pos;
    while(1)
    {
    printf("Enter the choice: \n");
    printf("1:Insert student info\t 2:Display students info\t 3:Insert info at a position\t 4:Delete\t 5:Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:head=insert(head);
               break;
        case 2:printf("The list info is: \n");
            display(head);
            break;
        case 3:printf("Enter the position to insert the info: \n");
        scanf("%d",&pos);
        insert_pos(pos,head);
        break;
        case 4:delete_beg(head);
        break;
        case 5:find(head);
        case 6:exit(0);
    }
    }
}
node getnode()
{
    node t;
    t=(node*)malloc(sizeof(struct student));
    if(t==NULL)
    {
        printf("Empty list\n");
        return;
    }
    t->next=NULL;
    return t;
}
node read()
{
    node temp;
    temp= getnode();
    printf("Enter the id and name of student: \n");
    scanf("%d %s",&temp->id, temp->name);
    return temp;
}
node insert(node head)
{
    node temp,new;
    new=read();
    temp=head;
    if(head==NULL)
    {
        return new;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return head;
}
node display(node head)
{
    node temp;
    temp=head;
    while(temp!=NULL)
    {
        printf("Student id: %d\t Student name: %s\n",temp->id,temp->name);
        temp=temp->next;
    }
    printf("\n");

}
node insert_pos(int pos,node head)
{
    node temp,cur,prev;
    temp=read();
    int count=1;
    cur=head;
    prev=NULL;
    while(cur!=NULL & count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=temp;
        temp->next=cur;
        return head;
    }
    return head;
}
int delete_beg(node head)
{   int q;
    if(head==NULL)
    {
        printf("The list is empty!!");
        return head;
    }
    else
    {
        q=head;
        head=head->next;
        free(q);
        return head;
    }

}
node find(node head)
{
    char s[10];
    node cur;
    cur=head;
    printf("Enter the date to find todays tasks: \n");
    scanf("%s",s);
    if(strcmp(s,cur->date))
    {
        printf("Task : %s\t Date: %s",cur->name,cur->date);
        cur=cur->next;
    }
    else{
        printf("NOT FOUND\n");
    }
}
