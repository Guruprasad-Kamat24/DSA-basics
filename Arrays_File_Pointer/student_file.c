//Create a students file, enter name and roll no
#include<stdio.h>
#include<stdlib.h>
struct student{
char name[10];
int rn;
};
typedef struct student st;
void read(st s[100],int n, FILE *fp);
void main()
{
    FILE *fp;
    st s[100];
    int n;
    printf("Enter the no of students: \n");
    scanf("%d",&n);
    fp=fopen("student.txt","w+");
    read(s,n,fp);
    fclose(fp);
    fp=fopen("student.txt","r");
    show(s,n,fp);
    fclose(fp);
}
void read(st s[100],int n,FILE *fp)
{
    int i;
    for(i=0;i<n;i++)
    {
       printf("Enter the name and roll no of a student: \n");
       scanf("%s %d",s[i].name,&s[i].rn);
       fprintf(fp,"Name:%s\t ,Roll no:%d\n",s[i].name,s[i].rn);
    }
}
void show(st s[100],int n,FILE *fp)
{
    char ch;
    printf("The file contains: \n");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
}

