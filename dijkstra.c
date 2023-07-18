#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int start=0;
int dist[5], path[5], visited[5], min_num=999, min;

void dijkstra(int graph[5][5])
{
   int i,j;
   for(i=0;i<5;i++)
   {
       dist[i] = graph[start][i];
       path[i] = start;
       visited[i] = 0;
   }
   dist[start] = 0;
   visited[start] = 1;

   for(i=0;i<5;i++)
   {
       for(j=0;j<5;j++)
       {
           if(visited[j] == 0)
           {
              if(dist[j] < min_num)
               {
                   min_num = dist[j];
                   min = j;
               }
           }
       }

       for(j=0;j<5;j++)
       {
           if(graph[min][j] + dist[min] < dist[j] && visited[j] == 0 && graph[min][j] != 0)
           {
               dist[j] = graph[min][j] + dist[min];
               path[j] = min;
           }
       }
       visited[min] = 1;
       min_num = 999;
   }

   for(j=0;j<5;j++)
   {
       printf("%d\n", dist[j]);
   }
}

int main()
{
    int graph[5][5] = {
        {0, 5, 6, 7, 8},
        {5, 0, 3, 6, 7},
        {6, 3, 0, 3, 4},
        {7, 6, 3, 0, 5},
        {8, 7, 4, 5, 0}
    };

   dijkstra(graph);
   return 0;
}
