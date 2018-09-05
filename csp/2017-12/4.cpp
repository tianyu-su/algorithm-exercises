#include "../../common.h"


struct Edge
{
	int t,v,type;
	Edge(int tt, int vv,int ttype){
		t=tt;
		v=vv;
		type=ttype;
	}
};

//flag =0 转移过来这个点之前是大路
//flag =1 记录转移来之前小路的距离
struct Status
{
	int v,flag;
};


Status rank[505];
vector<int> G[505];
vector<Edge> edges;
int n,m;
bool vis[505];

void Dijkstra(int s) {
	ll tmpCost=0;
    priority_queue<pii, vector<pii>, greater<pii> > que;
    for(int i=0;i<=n;i++)
    	rank[i].v=INF;
    rank[s].v = 0;
    que.push(mk(0, s));  //first:d[i] second:i 
    while (!que.empty()) {

        pii p = que.top(); que.pop();
        int v = p.second;
        vis[v]=true;
        if(rank[v].v < p.first) continue;    //如下图   //d[v] < p.first 说明，v 点已经通过其他路径变得松弛，距离更短。而 p.first 只是之前入队的旧元素
        for (int i = 0; i < G[v].size(); i++) {
            Edge e = edges[G[v][i]];
            //debug_b(v),debug_b(e.t),debug_b(rank[v].v),debug_b(rank[e.t].v);
            if(e.type==1)
            	tmpCost=rank[v].v-(rank[v].flag)*(rank[v].flag)+(rank[v].flag+e.v)*(rank[v].flag+e.v);
            else
            	tmpCost=rank[v].v+e.v;

            if (rank[e.t].v > tmpCost) {
                rank[e.t].v = tmpCost;
                // if(e.type==1 && !vis[e.t])
            	if(e.type==1)
                	rank[e.t].flag=e.v+rank[v].flag;
                else
                	rank[e.t].flag=0;
                que.push(mk(rank[e.t].v, e.t));
            }
            //debug_b(rank[e.t].v),debug_l(tmpCost);

        }
    }
}

int main(int argc, char const *argv[])
{
	//testin("../../data.in");
	cin>>n>>m;

	int t,a,b,c;
	for(int i=0;i<m;i++){
		cin>>t>>a>>b>>c;
		edges.pb(Edge(b,c,t));
		G[a].pb(edges.size()-1);
		edges.pb(Edge(a,c,t));
		G[b].pb(edges.size()-1);
	}

	Dijkstra(1);
	cout<<rank[n].v<<endl;
	// cout<<"Over!"<<endl;
	return 0;
}