#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    char name[10];
    char date[100];
    struct node *right;
    struct node *left;

} DIC;
DIC *root=NULL;
DIC* create_node(char *name,char *date)
{
    DIC *newnode =(DIC*)malloc(sizeof(DIC));
    strcpy(newnode->name,name);
    strcpy(newnode->date,date);
    newnode->right=NULL;
    newnode->left=NULL;
    return newnode;
}
void insert(char *name,char *date)
{
    DIC *parent=NULL,*curr=NULL,*node=NULL;
    if(root==NULL)
    {
        root=create_node(name,date);
        return ;
    }
    else
    {
        curr=root;
        while(curr!=NULL)
        {
            parent=curr;
            if(strcmp(curr->name,name)>0)
            {
                curr=curr->left;
            }

            else if(strcmp(curr->name,name)<0)
            {
                curr=curr->right;
            }

            else
            {
                printf("\n Already existing .");
                return ;
            }
        }

        node=create_node(name,date);
        if(strcmp(parent->name,name)>0)
        {
            parent->left=node;
        }

        else if(strcmp(parent->name,name)<0)
        {
            parent->right=node;
        }

        return;
    }
}
void inorderTraversal(DIC *myNode)
{
    if(myNode==NULL)
    {
        return ;
    }
    else
    {
        inorderTraversal(myNode->left);
        printf("Task : %s", myNode->name);
        printf("\t Date : %s", myNode->date);
        printf("\n");
        inorderTraversal(myNode->right);
    }
}
void find_elements(char *name)
{
    int flag=0,res=0;
    DIC *temp=root;
    while(temp!=NULL)
    {
        res=strcmp(temp->name,name);
        if(res==0)
        {
            printf("Date is %s",temp->date);
            flag=1;
            break;
        }
        else if(res>0)
        {
            temp=temp->left;
        }
        else
        {
            temp=temp->right;
        }
    }
    if(flag==0)
    {
        printf("Not found \n");
    }
}
void mini_dictionery()
{
    char name[10],date[100];
    int ch;
    int i=0;
    int flag=0;
    while (1)
    {
        printf("\n1. Insert task and date: \n");
        printf("2. Search for task \n3. display\n");
        printf("4. Exit\nEnter your choice:");
        scanf(" %d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter the task:");
            scanf("%s",name);
            printf("Enter the date:");
            scanf(" %s",date);
            insert(name,date);
            break;
        case 2:
            printf("Enter the task to find:");
            scanf(" %s",name);
            find_elements(name);
            break;
        case 3:
            inorderTraversal(root);
            break;
        default:
            printf("You have entered wrong option\n");
            break;
        }
    }
}
int main()
{
    mini_dictionery();
    return 0;
}
