#include<stdio.h>
#include<string.h>
struct cell_phone{
char os[10];
char display_type[10];
float price;
int RAM;
};
struct cell_phone read(struct cell_phone p[],int n);
void display(struct cell_phone p[],int n);
void avg(struct cell_phone p[],int n);
void sort(struct cell_phone p[],int n);
void main()
{
    int n;
    struct cell_phone p[100];
    printf("Enter the no of cell phones: \n");
    scanf("%d",&n);
    read(p,n);
    display(p,n);
    avg(p,n);
    sort(p,n);
    display1(p,n);
    search(p,n);
}
struct cell_phone read(struct cell_phone p[],int n)
{
    int i;

    for(i=0;i<n;i++)
    {
        printf("Enter the Os type, Display type, Price and RAM : \n");
        scanf("%s %s %f %d",p[i].os,p[i].display_type,&p[i].price,&p[i].RAM);
    }
    return p[i];
}
void display(struct cell_phone p[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("The Os type:%s , Display type:%s , Price:%f and RAM:%d \n",p[i].os,p[i].display_type,p[i].price,p[i].RAM);
    }
}
void avg(struct cell_phone p[],int n)
{
    int i,sum=0,avg;
    for(i=0;i<n;i++)
    {
        sum=sum+p[i].price;
    }
    avg=sum/n;
    printf("Avg = %d\n",avg);
}
void sort(struct cell_phone p[],int n)
{
    int i,j;
    struct cell_phone swap;
    for(i=0;i<n;i++)
    {
        for(j=0;j>n-1-i;j++)
        {
            if(p[j].price>p[j+1].price)
            {
                swap=p[j];
                p[j]=p[j+1];
                p[j+1]=swap;
            }
        }
    }
}
void display1(struct cell_phone p[],int n)
{
    int i;
    printf("After sorting: ");
    for(i=0;i<n;i++)
    {
        printf("The Os type:%s , Display type:%s , Price:%f and RAM:%d \n",p[i].os,p[i].display_type,p[i].price,p[i].RAM);
    }
}
void search(struct cell_phone p[],int n)
{
    int r,i;
    printf("Enter the RAM of mobile to search: ");
    for(i=0;i<n;i++)
    {
        if(p[i].RAM==r)
        {
            printf("Os = %s, Display = %s, Price = %f, RAM = %d",p[i].os,p[i].display_type,p[i].price,p[i].RAM);
        }
    }
}
