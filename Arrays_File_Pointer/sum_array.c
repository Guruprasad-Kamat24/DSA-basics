#include<stdio.h>
void read(int a[100],int n);
void sum(int a[100],int n);
void main()
{
    int a[100],n;
    scanf("%d",&n);
    read(a,n);
    sum(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
    printf("%d\n",a[i]);
    }
}
void sum(int a[100],int n)
{
    int i,j=0;
    for(i=0;i<n;i++)
    {
        j=j+a[i];
    }
    printf("Sum= %d\n",j);
}
