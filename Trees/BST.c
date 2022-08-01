#include<stdio.h>
#include<stdlib.h>
int count=0;
int c=0;
int cou=0;
int least=0;
struct tree
{
    int data;
    struct tree *right;
    struct tree *left;
};
typedef struct tree TREE;
TREE *insert_into_bst(TREE *root,int data)
{
    TREE *newnode;
    newnode=(TREE*)malloc(sizeof(TREE));
    if(newnode==NULL)
    {
        printf("Memory allocation failed");
        return root;
    }
    newnode->data=data;
    newnode->left=NULL;
    newnode->right=NULL;
    if(root==NULL)
    {
        printf("\n Root created");
        root=newnode;
        return root;
    }
    TREE *cur,*parent;
    cur=root;
    while(cur!=NULL)
    {
        parent=cur;
        if(newnode->data<cur->data)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    if(newnode->data<parent->data)
    {
        parent->left=newnode;
    }
    else
    {
        parent->right=newnode;
    }
    return root;

}
/*void preorder(TREE *root)
{
    if(root!=NULL)
    {
        printf("%d\t",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}*/
void inorder(TREE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
void count_edges(TREE *root)
{
    if(root!=NULL)
    {
        count_edges(root->left);
        count_edges(root->right);
        count++;
    }
}
int  countoutdegree(TREE *root)
{

    if(root->left!=NULL && root->right==NULL)
    {
        c=c+1;
    }
    else if(root->right!=NULL && root->left==NULL)
    {
        c=c+1;
    }
    else if(root->left!=NULL && root->right!=NULL)
    {
        c=c+2;
    }
    else
    {
        c=0;
    }
    printf("\n The number of out degree=%d",c);
}
void rootadd(TREE *root)
{
    printf("%d",root);
}
TREE *inorder_successor(TREE *root,int data)
{
    TREE *cur;
    cur=root;
    while(cur!=NULL && cur->data!=data)
    {
        if(data<cur->data)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    inorder(cur);
    return root;
}
void count_leaf(TREE *root)
{
    if(root!=NULL)
    {
        count_leaf(root->left);
        count_leaf(root->right);
        cou++;
    }
}
int least_node(TREE *root)
{

    if (root==NULL)
      return INT_MAX;

    int res = root->data;
    int lres = least_node(root->left);
    int rres = least_node(root->right);
    if (lres < res)
      res = lres;
    if (rres < res)
      res = rres;
    return res;
}
int max_value(TREE *root)
{
    if (root==NULL)
       return INT_MIN;

    int res = root->data;
    int lres = least_node(root->left);
    int rres = least_node(root->right);
    if (lres > res)
       res = lres;
    if (rres > res)
       res = rres;
    return res;
}
void no_comparision(TREE *root,int data)
{
    TREE *cur=root;
    int i;
    for(i=0;cur!=NULL && cur->data!=data;i++)
    {
        if(data<cur->data)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    printf("%d",i);
}
/*void traversal(TREE *root,int data)
{
    TREE *cur;
    int c;
    cur=root;
    while(cur!=NULL)
    {
        if(cur->data<data)
        {
            c=cur->data;
           root=(TREE*)delete_from_bst(cur,c);
        }
        else
        {
            cur=cur->right;
        }
    }
}*/
/*void postorder(TREE *root)
{
    if(root!=NULL)
    {
        postorder(root->left);

        postorder(root->right);
        void inorder(TREE *root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d\t",root->data);
        inorder(root->right);
    }
}
    }
}
*/
TREE *delete_from_bst(TREE *root,int data)
{
    if(root==NULL)
    {
        printf("\n Empty tree");
        return root;
    }
    TREE *cur,*p,*parent,*succ;
    cur=root;
    parent=NULL;
    while(cur!=NULL && cur->data!=data)
    {
        parent=cur;
        if(data<cur->data)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    if(cur==NULL)
    {
        printf("\n Item not found");
        return root;
    }
    if(cur->left==NULL)
    {
        p=cur->right;
    }
    else if(cur->right=NULL)
    {
        p=cur->left;
    }
    else
    {
        succ=cur->right;
        while(succ->left!=NULL)
        {
            succ=succ->left;
        }
        succ->left=cur->left;
        p=cur->right;
    }
    if(parent==NULL)
    {
        free(cur);
        return p;
    }
    if(cur==parent->left)
    {
        parent->left=p;
    }
    else
    {
        parent->right=p;
    }
    free(cur);
    return root;

}
int main()
{
    TREE *root=NULL;
    int ch,data,res;
    while(1)
    {
        printf("\n Enter the choice1-insert\n2-count edges\n3-delete\n4-count degree\n 5-inorder\n 6-root address \n 7-inorder successor\n8-no of leaf nodes\n9-least value\n 10-max value\n 11-exit");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:printf("Enter the data");
                   scanf("%d",&data);
                   root=insert_into_bst(root,data);
                    break;
            case 2:count_edges(root);
                   printf("\n The number of edges %d",(count-1));
                    break;
            case 3:printf("Enter the data to be deleted");
                   scanf("%d",&data);
                   root=delete_from_bst(root,data);
                    break;
            case 4:countoutdegree(root);
                    printf("The number of in degree of root node is 0");
                    break;
             case 5:inorder(root);
                    break;
            case 6:rootadd(root);
                    break;
            /*case 7:printf("\nEnter the user whose less than value to be deleted");
                   scanf("%d",&data);
                   traversal(root,data);*/
            case 7:printf("\n Enter the key whose inorder successor to be calculate");
                   scanf("%d",&data);
                   root=inorder_successor(root,data);
                   break;
            case 8:count_leaf(root);
                   printf("\n The number of leaf nodes is %d",(cou-1)/2);
                   printf("The number of root node 1");
                   break;
            case 9:res=least_node(root);
                   printf("The least node is %d",res);
                    break;
            case 10:res=max_value(root);
                    printf("The max node is %d",res);
                    break;
            case 11:printf("Enter the data");
                    scanf("%d",&data);
                no_comparision(root,data);
                    break;

            case 12:exit(0);
                    break;
        }

    }
    return 0;
}
