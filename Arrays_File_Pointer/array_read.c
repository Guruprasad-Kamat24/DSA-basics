#include<stdio.h>
void read(int a[100],int n);
void main()
{
    int a[100],n;
    scanf("%d",&n);
    read(a,n);
}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
    printf("%d",a[i]);
    }
}
