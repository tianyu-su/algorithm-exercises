#include <stdio.h>
#include <string.h>
#include "common.h"
#define MAX 55
#define INF 1000000000
 
int graph[MAX][MAX] ;
bool visited[MAX];
int prim(int n)
{
    int lowCost[MAX] ;
    for(int i = 1 ; i <= n ; ++i)
    {
        lowCost[i] = graph[1][i] ; 
    }
    memset(visited,false,sizeof(visited)) ;
    visited[1] = true ;
    lowCost[0] = INF ;
    int sum = 0 ;
    for(int i = 1 ; i < n ; ++i)
    {
        int index = 0 ;
        for(int j = 1 ; j <= n ; ++j)
        {
            if(!visited[j] && lowCost[index]>lowCost[j])
            {
                index = j ;
            }
        }
        if(index == 0)
            break ;
        sum += lowCost[index] ;
        visited[index] = true ;
        for(int j = 1 ; j <= n ; ++j)
        {
            if(!visited[j] && lowCost[j]>graph[index][j])
            {
                lowCost[j] = graph[index][j] ;
            }
        }
    }
    return sum ;
}
 
 
int main()
{
    testin("data.in");
    int n , m ;
    while(scanf("%d",&n) && n)
    {
        scanf("%d",&m);
        for(int i = 0 ; i < MAX ; ++i)
        {
            graph[i][i] = INF ;
            for(int j = 0 ; j < i ; ++j)
            {
                graph[i][j] = graph[j][i] = INF ;
            }
        }
        
        for(int i = 0 ; i < m ; ++i)
        {
            int x, y , len ;
            scanf("%d%d%d",&x,&y,&len);
            if(graph[x][y]>len)
            {
                graph[x][y] = graph[y][x] = len ;
            }
        }
        int sum = prim(n) ;
        printf("%d\n",sum) ;
    }
    return 0 ;
}
