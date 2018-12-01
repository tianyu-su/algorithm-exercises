#include "../../common.h"

const  int MAXN=100010;
int n,m;
struct edge
{
    int t,v;
    edge(int tt,int vv){
        t=tt;
        v=vv;
    }
};
vector<edge> edges[MAXN];
// p[i] 代表 起点到 i 点的最短时间
int p[MAXN];
void Dijistra(int s){
    priority_queue<pii, vector<pii> , greater<pii> > q;
    p[s]=0;
    q.push(mk(0,s));
    while(!q.empty()){
        pii top=q.top();q.pop();
        int v=top.second;
        if(p[v]<top.first) continue;
        for(int i=0;i<edges[v].size();i++){
            edge e=edges[v][i];
            // 这个 max 是本题核心，不同以往是累计求最短。
            // 现在是，每次探索的时候用最大探索，状态转移点用最小
            if(p[e.t]> max(p[v],e.v)){
                p[e.t]=max(p[v],e.v);
                q.push(mk(p[e.t],e.t));
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    testin("../../data.in");
    IOS;    
    cin>>n>>m;
    int f,t,v;
    for (int i = 0; i < m; ++i) {
        cin>>f>>t>>v;
        edges[f].pb(edge(t,v));
        edges[t].pb(edge(f,v));
    }
    mset(p,INF);
    Dijistra(1);
    cout<<p[n]<<endl;
    return 0;
}