#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;

};
typedef struct Node *node;
node insert_rear(node first);
node getnode();
node insert_pos(int pos, node first);
void display_list(node first);
//node delete_pos(int pos,node first);
main()
{
	node first = NULL;
	int item,choice,pos;
	while(1)
	{
	printf("1-Insert Rear\n2-Display\n3-Insert pos\n4-Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
    case 1: first=insert_rear(first);
            break;
    case 2: printf("Display List Inserted\n");
            display_list(first);
            break;
    case 3 : printf("Enter the position and item to be Inserted\n");
			        scanf("%d",&pos);
			        first=insert_pos(pos,first);
		             break;
    case 4:exit(0);

}}}

node getnode()
{
	node t;
	int item;
	t=(node *)malloc(sizeof(struct Node));
	if(t==NULL)
	{
		printf("Not created\n");
		exit(0);
	}
	printf("Enter item to be Inserted: \n");
    scanf("%d",&item);
    t->data = item;
	t->next = NULL;
	return t;
}

void display_list(node first)
{
	node t;
	if(first==NULL)
	{
		printf("Empty List\n");
		return;
	}
	printf("elements are\n");
	t=first;
	while(t!=NULL)
	{
		printf("%d\t",t->data);
		t= t->next;
	}
	printf("\n");
}
node insert_rear(node first)
{
	node new,c;
	new=getnode();
    if(first == NULL)
	  return new;
	c=first;
	while(c->next!=NULL)
	{
		c=c->next;
	}
	c->next = new;
	return first;
}
node insert_pos(int pos, node first)
{

    node t,prev,cur;
    int count;
    t=getnode();
    if(first ==NULL &&pos==1)
	  return t;
    if(first == NULL)
    {

        printf("invalid position\n");
        return first;
    }
if(pos==1)
{

    t->next= first;
    return t;
}
count=1;
prev=NULL;
cur= first;
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
    return first;
}
    return first;
}
