#include<stdio.h>
void read(int a[100],int n);
void insert(int a[100],int n,int p,FILE *fp);
void main()
{
    FILE *fp;
    int a[100],n,p;
    printf("No\n");
    scanf("%d",&n);
    printf("Pos\n");
    scanf("%d",&p);
    fp=fopen("insert_array.txt","w+");
    read(a,n);
    fclose(fp);
    insert(a,n,p,fp);

}
void read(int a[100],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        printf("Array elements: \n");
        scanf("%d",&a[i]);
    }
    for(i=0;i<n;i++){
    printf("%d\n",a[i]);
    }
}
void insert(int a[100],int n,int p,FILE *fp)
{
    int i,j;
    printf("Element to be inserted: \n");
    scanf("%d",&j);
    for (i = n-1; i >= p; i--)
    {
    a[i] = a[i - 1];
    a[p - 1] = j;
    }
    for(i=0;i<n;i++)
    {
        printf("Updated array:%d\n",a[i]);
        fprintf(fp,"%d\t",a[i]);
    }
}
