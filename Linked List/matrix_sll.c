#include<stdio.h>
#include<stdlib.h>
struct Node
{
    int data[10][10];
    int r;
    int c;
    struct Node *next;
};
typedef struct Node *node;
node getnode();
node insert_end(head,m,n);
node display(head,m,n);
node read();
node insert_pos(head,pos);
void main()
{
    node head=NULL;
    int a,m,n,pos;
    while(1){
    printf("Enter the choice: \n");
    printf("1.Insert end\t 2.Display\t 3.insert_pos\t 4.Delete beginning\t 5.Exit\n");
    scanf("%d",&a);

    switch(a)
    {
        case 1:
        head=insert_end(head);
        break;
        case 2:display(head,m,n);
        break;
        case 3:printf("Enter the pos: \n");
        scanf("%d",&pos);
        insert_pos(head,pos);
        break;
        case 4:delete_beg(head);
        break;
        case 5:exit(0);


    }
    }
}
node getnode()
{
    node newn;
    newn=(node)malloc(sizeof(struct Node));

    if(newn==NULL)
    {
        printf("\nLIST NOT CREATED\n");
        return;
    }
    newn->next=NULL;
        return newn;
}
node read()
{
    node temp;
    temp=getnode();
    int i,j,a[10][10];
    printf("Enter row & col: \n");
    scanf("%d%d",&temp->r,&temp->c);
    for(i=0;i<temp->c;i++)
    {
        for(j=0;j<temp->r;j++)
        {
            scanf("%d",&temp->data[i][j]);
        }
        printf("\n");
    }
    return temp;

}
node insert_end(node head)
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
node display(node head,int m,int n)
{
    node temp;
    temp=head;
    int i,j;
    while(temp!=NULL)
    {
        for(i=0;i<temp->c;i++)
        {
            for(j=0;j<temp->r;j++)
            {
                printf("%d\t",temp->data[i][j]);
            }
            printf("\n");
        }
        temp=temp->next;
        printf("\n");
    }
    printf("\n");
}
node insert_pos(node head,int pos)
{
   node cur,prev,temp;
   int count;
   temp=read();
   cur=head;
   prev=NULL;
   count=1;
   while(cur->next!=NULL && count!=pos)
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
{
    node q;
    if(head==NULL)
    {
        printf("The list is empty!!");
        return head;
    }
    else
    {
        q=head;
        head=head->next;
        q->next=NULL;
        free(q);
        return head;
    }
}

