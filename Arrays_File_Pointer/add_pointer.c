#include<stdio.h>
void add(int *p,int *q);
void main()
{
    int *p,*q,a=10,b=20;
    p=&a;
    q=&b;
    add(p,q);

}
void add(int *p,int *q)
{
    int c;
    c=*p+*q;
    printf("%d",c);

}
