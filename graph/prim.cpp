//references: https://blog.csdn.net/Lionel_D/article/details/44650225
//POJ 1278
#include "../common.h"

const int MAXN = 55;
int edges[MAXN][MAXN];
// lowcost[i] i 到 另一个集合最短边值
int lowcost[MAXN], vis[MAXN];

int prim(int start, int n) {
    int tree_rank = 0;
    //init
    mset(vis, false);
    for (int i = 0; i < n; i++) {
        //隐含着 除了 start 林边，其他的值都被赋值为 INF， 因为 edges 没有边的地方为 INF
        lowcost[i] = edges[start][i];
    }
    vis[start] = true;

    //记录边数
    int cnt = 0;
    while (cnt != n - 1) {
        // 参考网址里面的 使用 a[0] 记录最小值，巧妙
        int tmp_min = INF, tmp_min_indx;
        for (int i = 0; i < n; i++) {
            if (!vis[i] && tmp_min > lowcost[i]) {
                tmp_min = lowcost[i];
                tmp_min_indx = i;
            }
        }
        vis[tmp_min_indx] = true;
        tree_rank += tmp_min;
        cnt++;
        for (int i = 0; i < n; i++) {
            if (!vis[i]){
                // 查看 i 点是原来的和集合中的点距离近，还是新找出来的点近
                lowcost[i] = min(lowcost[i], edges[tmp_min_indx][i]);
            }
        }
    }
    return tree_rank;
}

int main() {
    int p, r;
    testin("data.in");
    while (cin >> p) {
        if (!p) break;
        cin >> r;
        //关键点，必须进行 最大值 初始化
        memset(edges, 0x3f, sizeof(edges));
        for (int i = 0; i < r; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--; v--;
            edges[u][v] = min(w, edges[u][v]);
            edges[v][u] = min(w, edges[u][v]);
        }
        cout << prim(0, p) << endl;
    }
    return 0;
}