struct Edge{ 
    int from,to,dist;
    Edge(int u,int v,int w):from(u),to(v),dist(w){}
};
const int maxn = 40010;//节点数
vector<Edge> edges;//边的具体信息
vector<int> G[maxn];//边的编号

void addEdge(int u, int v, int w){//加入一条边（无向图）
    edges.push_back(Edge(u,v,w));
    edges.push_back(Edge(v,u,w));
    int size = edges.size();
    G[u].push_back(size-2);
    G[v].push_back(size-1);
}