#include<stdio.h>
#include<stdlib.h>
struct tree{
int value;
struct tree *rc,*lc;
};
typedef struct tree *node;
node insert(node,int);
void print(node);
node new_node(int);
node search(node root);
void count_edge(node root);
void count_nodes(node root);
void countoutdegree(node root);
int maxDepth(node root);
node delete(node,int);
int sum=0;
int count=0;
int count1=0;
int c=0;
int main()
{
node root=NULL;
int n,x,res,key;
while(1)
{
    printf("Enter the choice:1)Insert 2)Print 3)Search 4)Count edges 5)Count nodes 6)Count degree 7)Count leaf 8)Least value 9)Max value 10)Delete 11)Exit\n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:printf("Enter the value: \n");
        scanf("%d",&x);
            root=insert(root,x);
        break;
        case 2:print(root);
        printf("Sum of all nodes=%d\n",sum);
        break;
        case 3:search(root);
        break;
        case 4:count_edge(root);
        printf("Edges=%d\n",(count-1));
        break;
        case 5:count_nodes(root);
        printf("Nodes=%d\n",count1);
        break;
        case 6:count_degree(root);
        break;
        case 7:count_leaf(root);
        printf("leaf=%d\n",count_leaf(root));
        break;
        case 8:res=least(root);
        printf("least value=%d\n",res);
        break;
        case 9:res=max(root);
        printf("Max value=%d\n",res);
        break;
        case 10:printf("Enter the node to delete: \n");
        scanf("%d",&key);
        delete(root,key);
        break;
        case 11:exit(0);
        break;
        case 12:maxDepth(root);
        printf("Height of tree is %d", maxDepth(root));
        break;
    }
}
return 0;
}
node new_node(int val)
{
    node temp=(node*)malloc(sizeof(struct tree));
    temp->value=val;
    temp->rc=NULL;
    temp->lc=NULL;
    return temp;
}
node insert(node root,int value)
{
    node cur;
    if(root==NULL)
    {
        return new_node(value);
    }
    if(value<root->value)
    {
        root->lc=insert(root->lc,value);
    }
    else if(value>root->value)
    {
        root->rc=insert(root->rc,value);
    }
    return root;
}
void print(node root)
{

    if(root!=NULL)
    {
        print(root->lc);
        printf("%d\t",root->value);
        sum=sum+root->value;
        print(root->rc);
    }

}
node search(node root)
{
    int n;
    printf("Enter the key to search: \n");
    scanf("%d",&n);
    node cur=root;
    while(cur!=NULL)
    {
        if(n>cur->value)
        {
            cur=cur->rc;
            if(cur->value==n)
            {
                printf("Found\n");
                return 0;
            }
        }
        else if(n<cur->value)
        {
            cur=cur->lc;
            if(cur->value==n)
            {
                printf("Found\n");
                return 0;
            }
        }
    }
}

void count_edge(node root)
{
    if(root!=NULL)
    {
        count_edge(root->lc);
        count_edge(root->rc);
        count++;
    }
}

void count_nodes(node root)
{
    if(root!=NULL)
    {
        count_nodes(root->lc);
        count_nodes(root->rc);
        count1++;
    }
}

void count_degree(node root)
{
    if(root->lc!=NULL && root->rc==NULL)
    {
        c=c+1;
    }
    else if(root->lc==NULL && root->rc!=NULL)
    {
        c=c+1;
    }
    else if(root->lc!=NULL && root->rc!=NULL)
    {
        c=c+2;
    }
    else{
        c=0;
    }
    printf("Degree=%d\n",c);
}

int count_leaf(node root)
{
    if(root==NULL)
    {
        return 0;
    }
    if(root->lc==NULL && root->rc==NULL)
    {
        return 1;
    }
    else
        return count_leaf(root->lc)+count_leaf(root->rc);
}

int least(node root)
{
    if(root==NULL)
    {
        return INT_MAX;
    }
    int res=root->value;
    int lres=least(root->lc);
    int rres=least(root->rc);
    if(lres<res)
    {
        res=lres;
    }
    if(rres<res)
    {
        res=rres;
    }
    return res;
}

int max(node root)
{
    if(root==NULL)
    {
        return INT_MIN;
    }
    int res=root->value;
    int lres=max(root->lc);
    int rres=max(root->rc);
    if(lres>res)
    {
        res=lres;
    }
    if(rres>res)
    {
        res=rres;
    }
    return res;
}
void countoutdegree(node root)
{
    int c=0;
    if(root->lc!=NULL && root->rc==NULL)
    {
        c=c+1;
    }
    else if(root->lc==NULL && root->rc!=NULL)
    {
        c=c+1;
    }
    else if(root->lc!=NULL && root->rc!=NULL)
    {
        c=c+2;
    }
    else
    {
        c=0;
    }
    printf("The number of out degree %d",c);
}

node delete(node root,int data)
{
    if(root==NULL)
    {
        return root;
    }
    node cur,p,parent,succ;
    cur=root;
    parent=NULL;
    while(cur!=NULL && cur->value!=data)
    {
        parent=cur;
        if(cur->value>data)
        {
            cur=cur->lc;
        }
        else if(cur->value<data)
        {
            cur=cur->rc;
        }
    }
    if(cur==NULL)
    {
        return root;
    }
    if(cur->lc==NULL)
    {
        p=cur->rc;
    }
    else if(cur->rc==NULL)
    {
       p=cur->lc;
    }
    else{
        succ=cur->rc;
        while(succ->lc!=NULL)
        {
            succ=succ->lc;
        }
        succ->lc=cur->lc;
         p=cur->rc;
    }
        if(parent==NULL)
        {
            free(cur);
            return p;
        }
        if(cur==parent->lc)
        {
            parent->lc=p;
        }
        else{
            parent->rc=p;
        }
        free(cur);
        return root;
}

int maxDepth(node root)
{
    if (root== NULL)
        return 0;
    else {
        /* compute the depth of each subtree */
        int lDepth = maxDepth(root->lc);
        int rDepth = maxDepth(root->rc);

        /* use the larger one */
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }
}
