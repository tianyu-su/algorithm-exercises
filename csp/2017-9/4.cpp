#include "../../common.h"
const int MAXN = 1005;
vector<int> edges[MAXN];
int  vis[MAXN], roger[MAXN][MAXN];
int N, M;
int main(int argc, char const *argv[])
{
    testin("../../data.in");
    cin >> N >> M;
    int f, t;
    for (int i = 0; i < M; i++) {
        cin >> f >> t;
        edges[f].pb(t);
    }
    for (int i = 1; i <= N; i++) {
        mset(vis, 0);
        queue<int> q;
        q.push(i);
        vis[i] = true;
        roger[i][i] = 1;
        while (!q.empty()) {
            int t = q.front(); q.pop();
            for (int k = 0; k < edges[t].size(); k++) {
                roger[i][edges[t][k]] = roger[edges[t][k]][i] = 1;
                if (!vis[edges[t][k]]) {
                    q.push(edges[t][k]);
                    vis[edges[t][k]] = 1;
                }
            }
        }
    }
    int ans = 0, j;
    for (int i = 1; i <= N; i++) {
        for (j = 1; j <= N; j++) {
            if (!roger[i][j]) break;
            // cout<<roger[i][j]<<" ";
        }
        // cout<<endl;
        if (j > N)
            ans++;
    }
    cout << ans << endl;
    return 0;
}