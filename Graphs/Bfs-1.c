#include<stdio.h>
#include<stdlib.h>

int graph[20][20], visited[10],total;

void BFS();

main()
{
    int i,j;
    printf("Enter the total number of vertices:");
    scanf("%d",&total);

    // adjacency matrix input
    for(i=0;i<total;i++)
    {
        for(j=0;j<total;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    for ( i = 0; i < total; i++)
    {
        visited[i]=0;
    }
    
    BFS(0);
}

void BFS(int vertex)
{
    int j;
    printf("%d",vertex);
    visited[vertex]=1;

    for(j=0;j<total;j++)
    {
        if(!visited[j]&& graph[vertex][j]==1)
        {
            BFS(j);
        }
    }
}