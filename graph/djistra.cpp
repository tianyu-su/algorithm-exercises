#include "../common.h"

using namespace std;
const int MAXN = 1005;

struct edge
{
    int from, to, cost;
    edge(int f, int t, int c) :from(f),to(t),cost(c) {}
};
int d[MAXN];
vector<edge>edges;
vector<int>G[MAXN]; 
typedef pair<int, int> P;

void Dijkstra(int s) {
    priority_queue<P, vector<P>, greater<P> > que;
    fill(d, d + MAXN, INF);
    d[s] = 0;
    que.push(make_pair(0, s));
    while (!que.empty()) {
        P p = que.top(); que.pop();
        int v = p.second;
        if(d[v] < p.first) continue;        //d[v] < p.first 说明，v 点已经通过其他路径变得松弛，距离更短。而 p.first 只是之前入队的旧元素
        for (int i = 0; i < G[v].size(); i++) {
            edge e = edges[G[v][i]];
            if (d[e.to] > d[v] + e.cost) {
                d[e.to] = d[v] + e.cost;
                que.push(P(d[e.to], e.to));
            }
        }
    }
}

int main() {
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        if (n == m && n == 0) break;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
        for (int i = 0; i < m; i++) {
            int f, t, c;
            scanf("%d%d%d", &f, &t, &c);
            edges.push_back(edge(f, t, c));
            G[f].push_back(edges.size() - 1);

            edges.push_back(edge(t, f, c));
            G[t].push_back(edges.size() - 1);
        }
        Dijkstra(1);
        printf("%d\n", d[n]);
    }
    return 0;
}