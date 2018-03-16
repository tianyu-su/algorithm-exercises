#include <stdio.h>
#include <string.h>
int line[100001];
int num[100001];
int q[100010];
int dir[2]= {1,-1};
int head,last;
int s,e;
int isEmpty()
{
    if(head==last)
        return 1;
    else
        return 0;
}
void push(int x)
{
    q[last]=x;
    last++;
}
void pop()
{
    head++;
}
void init()
{

    memset(q,0,sizeof(q));
    head=0;
    last=0;
}
int isLine(long long  x)
{
    if(x>=0 && x<=100000)
        return 1;
    else
        return 0;
}
int bfs(int x)
{
    int k;
    long long nx;
    init();
    num[x]=0 ;
    line[x]=1;
    push(x);
    while(!isEmpty())
    {
        pop();
        for(k=0; k<3; k++)
        {
            if(k==2)
                nx=x*2;
            else
                nx=x+dir[k];
            if(nx==e) return num[x]+1;
            if(!line[nx] && isLine(nx))
            {
                num[nx]=num[x]+1;
                line[nx]=1;
                push(nx);
            }
        }
        x=q[head];
    }
}
int main()
{

    int ans;

    memset(line,0,sizeof(line));
    memset(num,0,sizeof(num));
    scanf("%d%d",&s,&e);
    if(s>=e)  printf("%d\n",s-e);
    else
   {
        ans=bfs(s);
        printf("%d\n",ans);

    }
    return 0;
}
