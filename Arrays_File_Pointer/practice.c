#include<stdio.h>
#include<string.h>
typedef struct employee_details
{
    char name[20],c[20];
    int y,rn,sal;
}E;
void read(E d[100],FILE *fp,int n);
void hike(E d[100],FILE *fp,int n);
int main()
{
    E d[100];
    FILE *fp;
    int n;
    scanf("%d",&n);
    if(n>0){
    fp=fopen("employee.txt","w");
    read(d,fp,n);
    fclose(fp);
    hike(d,fp,n);
    }
    else{
        printf("N should be positive.");
    }
    return 0;
}
void read(E d[100],FILE *fp,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        scanf("%d",&d[i].rn);
        scanf("%s",d[i].name);
        scanf("%d",&d[i].y);
        scanf("%s",d[i].c);
        scanf("%d",&d[i].sal);
        fprintf(fp,"%d\t%s\t%d\t%s\t%d\n",d[i].rn,d[i].name,d[i].y,d[i].c,d[i].sal);
    }
}
void hike(E d[100],FILE *fp,int n)
{

    int i,inc=0;
    printf("Employee details working in India after increase in Salary:\n");
    for(i=0;i<n;i++)
    {
        fscanf(fp,"%d\t%s\t%d\t%s\t%d\n",&d[i].rn,d[i].name,&d[i].y,d[i].c,&d[i].sal);

        if(strcmp(d[i].c,"India")==0)
        {

            if(d[i].y>=5&&d[i].y<=10)
            {
                printf("%d %s %d %s ",d[i].rn,d[i].name,d[i].y,d[i].c);
                d[i].sal+=500;
                inc+=500;
                printf("%d\n",d[i].sal);
            }
            else if(d[i].y>10&&d[i].y<=15)
            {
                printf("%d %s %d %s ",d[i].rn,d[i].name,d[i].y,d[i].c);
                d[i].sal+=1000;
                inc+=1000;
                printf("%d\n",d[i].sal);
            }
            else if(d[i].y>15&&d[i].y<=20)
            {
                printf("%d %s %d %s ",d[i].rn,d[i].name,d[i].y,d[i].c);
                d[i].sal+=1500;
                inc+=1500;
                printf("%d\n",d[i].sal);
            }
            else if(d[i].y>20)
            {
                printf("%d %s %d %s ",d[i].rn,d[i].name,d[i].y,d[i].c);
                d[i].sal+=2000;
                inc+=2000;
                printf("%d\n",d[i].sal);
            }
        }
    }
    printf("\nTotal Amount in the form of Increment: %d",inc);
}
