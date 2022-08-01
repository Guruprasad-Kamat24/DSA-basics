#include<stdio.h>
void radii(int *p);
void main()
{
  int *p,r;
  printf("Enter the radius: \n");
  scanf("%d",&r);
  p=&r;
  radii(p);
}
void radii(int *p)
{
    int area;
    area = 3.14 * (*p) * (*p);
    printf("Area: %d\n",area);
}
