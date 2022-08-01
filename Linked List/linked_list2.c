#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
};
typedef struct Node *node;
node insert_rear(head);
node display(head);
node getnode();
node insert_pos(pos,head);
//node delete(head);
void main()
{
    node head=NULL;
    int n,pos;
    while(1)
    {
    printf("Enter the choice: \n");
    printf("1:insert rear\n 2:Display\n 3:Insert at Pos\n 4:Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:head=insert_rear(head);
        break;
        case 2:printf("Display the list: \n");
               display(head);
               break;
        case 3:printf("Enter the position to insert: \n");
               scanf("%d",&pos);
               insert_pos(pos,head);
               break;
        case 4:exit(0);
    }
    }
}
node getnode()
{
    int item;
    node t;
    t=(node*)malloc(sizeof(struct Node));
    if(t==NULL)
    {
        printf("List not created\n");
    }
    printf("Enter the data to insert: \n");
    scanf("%d",&item);
    t->data=item;
    t->next=NULL;
    return t;
}
node insert_rear(node head)
{
    node new,temp;
    new=getnode();
    if(head==NULL)
    {
        return new;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new;
    return head;
}
node display(node head)
{
    node t;
    if(head==NULL)
    {
        printf("Empty list\n");
        return;
    }
    printf("The elements are: \n");
    t=head;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        t=t->next;
    }
    printf("\n");
}
node insert_pos(int pos, node head)
{
    node t,cur,prev;
    int count;
    t=getnode();
    if(t==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    if(pos==1)
    {
        t->next=head;
        return head;
    }
    cur=head;
    prev=NULL;
    count=1;
    while(cur!=NULL && count!=pos)
    {
        prev=cur;
        cur=cur->next;
        count++;
    }
    if(count==pos)
    {
        prev->next=t;
        t->next=cur;
        return head;
    }
    return head;


}

