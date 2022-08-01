#include<stdio.h>
void add(int n,FILE *fp);
void main()
{
    FILE *fp;
    int n;
    scanf("%d",&n);
    fp=fopen("add_file.txt","w");
    add(n,fp);
    fclose(fp);
}
void add(int n,FILE *fp)
{
    int i,j=0;
    for(i=0;i<=n;i++)
    {
        j=j+i;
    }
    fprintf(fp,"%d",j);
    printf("%d",j);
}
