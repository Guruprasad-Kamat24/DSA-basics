#include<stdio.h>
#include<stdlib.h>
struct Node{
int data;
struct Node *next;
struct Node *prev;
};
typedef struct Node *node;
node insert_end(node head);
node insert_beg(node head);
node insert_pos(node head,int pos);
node display(node head);

void main()
{
    node head=NULL;
    int n,pos;

    while(1)
    {
        printf("Enter the choice:1)Insert end 2)Insert beg 3)insert pos 4)Display 5)Exit \n");
    scanf("%d",&n);
        switch(n)
        {
            case 1:head=insert_end(head);
            break;
            case 2:head=insert_beg(head);
            break;
            case 3:printf("Enter the position to insert: \n");
            scanf("%d",&pos);
            insert_pos(head,pos);
            break;
            case 4:display(head);
            break;
            case 5:exit(0);
        }
    }
}
node getnode()
{
    node t;
    int item;
    t=(node*)malloc(sizeof(struct Node));
    printf("Enter the item: ");
    scanf("%d",&item);
    t->prev=NULL;
    t->next=NULL;
    t->data=item;
    return t;
}
node insert_end(node head)
{
    node cur,new;
    new=getnode();
    cur=head;
    if(head == NULL)
	  return new;
    while(cur->next!=NULL)
    {
        cur=cur->next;
    }
    cur->next=new;
    new->prev=cur;
    return head;
}
node insert_beg(node head)
{
    node cur,new1;
    new1=getnode();
    cur=head;
    if(head==NULL)
    {
        return new1;
    }
    new1->next=cur;
    cur->prev=new1;
    head=new1;
    return head;
}
node insert_pos(node head,int pos)
{
    node cur,new,prev1;
    new=getnode();
    int count=1;
    cur=head;
    prev1=NULL;
    if(head==NULL)
    {
        printf("Empty list\n");
        return head;
    }
    while(cur->next!=NULL && count!=pos)
    {
        prev1=cur;
        cur=cur->next;
        count++;
    }
    prev1->next=new;
    new->prev=prev1;
    new->next=cur;
    cur->prev=new;
}
node display(node head)
{
	node t;
	if(head==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=head;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
	printf("\n");
}
