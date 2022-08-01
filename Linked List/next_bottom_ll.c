#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
struct Node *bot;
};
typedef struct Node *node;
node insert_rear(head);
node display(head);
node getnode();
node display1(node head);
node insert_bot(head);
node flatten(head);
node sort(head);
void main()
{
    node head=NULL;
    int n;
    while(1)
    {
    printf("Enter the choice: \n");
    printf("1:insert rear\n 2:Display\n 3:Insert at bottom\n 4:Flatten\n 5.Sort\n 6.Exit \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:head=insert_rear(head);
        break;
        case 2:printf("Display the list: \n");
               display(head);
               break;
        case 3:
               head=insert_bot(head);
               break;
        case 4:flatten(head);
        break;
        case 5:sort(head);
        break;
        case 6:exit(0);
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
    t->bot=NULL;
    return t;
}
node display(node head)
{
    node t,cur;
    if(head==NULL)
    {
        printf("Empty list\n");
    }
    else{
    printf("The elements are: \n");
    t=head;
    while(t!=NULL)
    {
        printf("%d\t",t->data);
        cur=t;
        cur=cur->bot;
        while(cur!=NULL)
        {
            printf("%d\t",cur->data);
            cur=cur->bot;
        }
        printf("\n");
        t=t->next;
    }
    }
}
node insert_rear(node head)
{
    node new1,temp;
    new1=getnode();
    if(head==NULL)
    {
        return new1;
    }
    temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=new1;
    new1->next=NULL;
    return head;
}
node insert_bot(node head)
{
  node temp,new1;
  temp=head;
  new1=getnode();
   while(temp->next!=NULL)
        temp=temp->next;
        while(temp->bot!=NULL)
            temp=temp->bot;
    temp->bot=new1;
    return head;
}
node flatten(node head)
{
    node temp,b,cur;
    temp=head;
   while(temp->next!=NULL&&temp!=NULL)
    {
        b=temp->next;
        cur=temp;
        while(cur->bot!=NULL && cur!=NULL)
        {
            cur=cur->bot;
        }
        cur->bot=b;
        node prev=temp;
        temp=temp->next;
        prev->next=NULL;
    }
    return head;
}
node sort(node head)
{
    node temp2=head,prev;
    int c;
    prev=NULL;
    while(temp2->bot!=NULL && temp2!=NULL)
    {
        prev=temp2;
        node temp=temp2;
        temp2=temp2->bot;
        while(temp->bot!=NULL && temp!=NULL)
        {
          temp=temp->bot;
          if(prev->data>temp->data)
        {
            c=temp->data;
            temp->data=prev->data;
            prev->data=c;
        }
        }

    }
    node cur=head;
    while(cur!=NULL)
        {
            printf("%d\t",cur->data);
            cur=cur->bot;
        }
        printf("\n");

    return head;
}
