#include<stdio.h>
void palindrome(int n);
void main()
{
    int n;
    scanf("%d",&n);
    palindrome(n);
}
void palindrome(int n)
{
    int j,sum=0,temp;
    temp=n;
    while(n>0)
    {
        j=n%10;
        sum=(sum*10)+j;
        n=n/10;
    }
    printf("%d\n",sum);
    if(temp==sum){
    printf("Palindrome");
    }
    else{
    printf("Not palindrome");
    }
}
