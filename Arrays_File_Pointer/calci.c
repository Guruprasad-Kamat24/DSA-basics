#include<stdio.h>
#include<stdio.h>
void main()
{
    int a,ch;
    int sum=0;
    while(1)
    {
        printf("\n enter 1 for sum,2 to print sum");
   scanf("%d",&ch);
   switch(ch)
   {
       case 1:scanf("%d",&a);
               sum=sum+a;
               break;
       case 2:printf("%d",sum);
       exit(0);
              break;


       default:printf("\n invalid operator");
                exit(0);
                break;
   }
    }

}
