#include "../common.h"
//原理：https://www.cnblogs.com/TianyuSu/p/9401017.html


const int maxn = 1e3 + 5;
//存图
int mapp[maxn][maxn];
int n, m; //定点数，边数


int parent[maxn];
int find_root (int n) {
	return parent[n] == -1 ? n : parent[n] = find_root(parent[n]);
}


//连通分支数 = parent 中 -1 个数
bool union_solve() {
	memset(parent, -1, sizeof(parent));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mapp[i][j]) {
				int r1 = find_root(i), r2 = find_root(j);
				if (r1 != r2)
					parent[j] = r1;
			}
		}
	}

	//如果parent 中只有一个 根节点 那么就连通
	int cnt = 0;
	for (int i = 0; i < n; i++)
		if (parent[i] == -1)
			cnt++;
	return cnt == 1 ? true : false;
}




bool vis[maxn];
void dfs(int x) {
	vis[x] = true;
	for (int i = 0; i < n; i++) {
		if (mapp[x][i] && !vis[i])
			dfs(i);
	}
}

//连通分支数 = 对图中所有点进行 dfs，运行了几次，说明就有几个连通分支数
bool dfs_solve() {
	memset(vis, 0, sizeof(vis));
	dfs(0);
	for (int i = 0; i < n; i++)
		if (!vis[i])
			return false;
	return true;
}


//连通分支数 = 对图中所有点进行 bfs，运行了几次，说明就有几个连通分支数
bool bfs_solve() {
	int cnt = 0;
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	q.push(0);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		vis[x] = true;
		cnt++;
		for (int i = 0; i < n; i++)
			if (mapp[x][i] && !vis[i]) {
				q.push(i);
				vis[i] = true;	//保证cnt==n时访问全部点，防止一个节点被加入队列两次
			}
	}
	return cnt == n;
}


//连通分支数为主对角线上 单位阵的个数
// 利用传递闭包求解
bool warshall_solve() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++)
				mapp[i][j] = mapp[i][j] || (mapp[i][k] && mapp[k][j]);
			mapp[i][i] = 1; //自己和自己连通
		}
	}


	for (int i = 0; i < n; i++) {
		print_arr(mapp[i], n);
		cout << endl;
	}

	//矩阵中全为 1， 即表示连通图
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (!mapp[i][j])
				return false;
	return true;
}



//读入图,假定为无向图
void input() {
	memset(mapp, 0, sizeof(mapp));
	cout << "输入顶点数、边数：";
	cin >> n >> m;
	cout << "输入(u,v) 代表有一条边,编号从1开始" << endl;
	int u, v;
	for (int i = 0; i < m; i++) {
		cin >> u >> v;
		mapp[u - 1][v - 1] = mapp[v - 1][u - 1] = 1;
	}
}

int main(int argc, char const *argv[])
{

	testin("../data.in");
	input();
	debug_l(union_solve());
	debug_l(dfs_solve());
	debug_l(bfs_solve());
	debug_l(warshall_solve());
	return 0;
}