/*
link:http://codevs.cn/problem/2370
资料：http://www.cnblogs.com/JVxie/p/4854719.html
题解：http://www.cnblogs.com/duskfire/p/7087443.html
*/

/*
3
1 0 1
2 0 1
3
1 0
2 0
1 2
*/

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
//DFS+并查集

const int MAXN = 50000;

int parent[MAXN+5];
bool vis[MAXN+5],vt[MAXN+5];
vector<pair<int, int>> edges[MAXN+5];//pair(to,value)
vector<pair<int,int> > V[MAXN+5];//pair(x，index) index是为了对应答案
int ans[MAXN + 5];
int len[MAXN + 5];
int N;

void init_parent(){
    for(int i=0;i<=MAXN;i++) parent[i]=-1;
}

int find(int x){
    int s;
    for(s=x;parent[s]>=0;s=parent[s]);
    int tmp;
    while(s!=x){
        tmp=parent[x];
        parent[x]=s;
        x=tmp;
    }
    return s;
}

void Union(int r1,int r2){
    r1=find(r1); r2=find(r2);
    if(r1==r2) return;
    if(parent[r1]<parent[r2]){
        parent[r2]=r1;
        parent[r1]+=parent[r2];
    }else{
        parent[r1]=r2;
        parent[r2]+=parent[r1];
    }
}

//每个节点含义，编号+本节点到起始点的value
void dfs(int x,int value){
    len[x] = value;
    if (!vis[x]) {
    vis[x] = true;
    for (int i = 0; i < edges[x].size(); i++) {
            vis[edges[x][i].first] = true;
            dfs(edges[x][i].first, value + edges[x][i].second);
            Union(x, edges[x][i].first);
    }

    for (int i = 0; i < V[x].size(); i++)
        if (vis[V[x][i].first])
            ans[V[x][i].second] = len[x] + len[V[x][i].first] - 2 * len[find(V[x][i].first)];
            //两个点到起始点距离之和减去最近公共节点到起点的距离就是两点之间的
    }
}
 
int main(){
    while(cin>>N){
        //init
        init_parent();
        memset(vis, 0, sizeof(vis));
        memset(vt, 0, sizeof(vt));
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < N-1; i++) {
            int a, b,v;
            cin >> a >> b>>v;
            edges[a].push_back(make_pair(b,v));
            edges[b].push_back(make_pair(a,v));
        }
        int cas;
        cin >> cas;
        for (int i = 0; i < cas; i++) {
            int a, b;
            cin >> a>>b;
            V[a].push_back(make_pair(b,i));
            V[b].push_back(make_pair(a,i));
        }
        dfs(0,0);
        for (int i = 0; i < cas; i++)
            cout << ans[i] << endl;
    }
    return 0;
}
