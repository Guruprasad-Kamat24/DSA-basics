#include<stdio.h>
#include<stdlib.h>
void main()
{
    FILE *fp;
    char ch;
    fp=fopen("sample.dat","w");
    if(fp==NULL)
    {
        printf("Error\n");
        exit(0);
    }
    printf("Input some txt: \n");
    while((ch=getchar())!=EOF)
    fputc(ch,fp);
    fclose(fp);
    printf("The file contains: \n");
    fp=fopen("sample.dat","r");
    while((ch=fgetc(fp))!=EOF)
        putchar(ch);
    fclose(fp);

}
