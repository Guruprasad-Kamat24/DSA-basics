#include<stdio.h>
#include<stdlib.h>
struct Node
{
	int data;
	struct Node *next;

};
typedef struct Node *node;
node insert_rear(node head);
node getnode();
node display_list(node head);
main()
{
	node head[10];
	head[10]=NULL;
	int item,choice,n,k,i,l,j;
	printf("Enter the no of list: \n");
	scanf("%d",&n);
	while(1)
	{
	printf("1-Insert Rear\n2-Display\n3-Left shift \n4-Exit\n");
	scanf("%d",&choice);
	switch(choice)
	{
    case 1:
        for(i=0;i<n;i++)
        {
            printf("Enter the no of list elements: \n");
            scanf("%d",&l);
            for(j=0;j<l;j++)
            {
              head[i]=insert_rear(head[i]);
            }

        }
       break;
    case 2:
        for(i=0;i<n;i++)
        {
         printf("Display List Inserted\n");
            display_list(head[i]);
        }

            break;
    case 4:exit(0);
    }



}}

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

node display_list(node head)
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
node insert_rear(node head)
{
	node new1,c;
	new1=getnode();
    if(head == NULL)
	  return new1;
	c=head;
	while(c->next!=NULL)
	{
		c=c->next;
	}
	c->next = new1;
	return head;
}
