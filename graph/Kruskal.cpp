//reference: https://blog.csdn.net/qq_35644234/article/details/59106779

//边 拓展
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int p, r;
int parent[60];
const int MAXN = 200;
struct edge
{
    int u, v, w;
    edge(int u=0, int v=0, int w=0) :u(u), v(v), w(w) {}
}edges[MAXN];

int cmp(edge &e1, edge &e2) {
    return e1.w < e2.w;
}

int find(int x) {
    int s;
    for (s = x; parent[s] >= 0; s = parent[s]);
    int tmp;
    while (s != x) {
        tmp = parent[x];
        parent[x] = s;
        x = tmp;
    }
    return s;
}

void Union(int R1, int R2) {
    int r1 = find(R1), r2 = find(R2);
    if (r1 == r2) return; 
    if (parent[r1] < parent[r2]) {
        parent[r1] += parent[r2];
        parent[r2] = r1;
    }
    else {
        parent[r2] += parent[r1];
        parent[r1] = r2;
    }
}
long long  Kruskal() {
    memset(parent, -1, sizeof(parent));
    int sumEdge = 0;
    long long ans = 0;
    for (int i = 0; i < r; i++) {
        if (find(edges[i].u) != find(edges[i].v)) {
            Union(edges[i].u, edges[i].v);
            sumEdge++;
            ans += edges[i].w;
        }
        if (sumEdge > p - 1) break;
    }
    return ans;
}

int main() {
    while (cin >> p) {
        if (!p) break;
        cin >> r;
        for (int i = 0; i < r; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            edges[i] = edge(u, v, w);
        }
        sort(edges, edges + r,cmp);
        cout << Kruskal() << endl;
    }
    return 0;
}