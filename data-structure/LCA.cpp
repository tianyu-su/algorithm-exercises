/*

	*
	//离线 算法， 
	tutorial: reference: http://www.cnblogs.com/JVxie/p/4854719.html
	 poj1330 https://blog.csdn.net/qq_33183401/article/details/70233900
	//倍增LCA
	https://blog.csdn.net/Janis_z/article/details/52937631?locationNum=6&fps=1
*/
/*

	通过dfs先序遍历，维护并查集
*/

#include "../common.h"

const int MAXN = 10;
int points;//实际输入点的个数
int from_p, to_p; //这两个点之间的LCA
bool flag[MAXN];	//离线算法在一颗数中遍历，必须找到树根。 flag[i], i 具有前驱节点，类似也可以找所有的叶子节点
int parent[MAXN];
bool vis[MAXN];
struct Edge{
	int u,v;
	Edge(int u, int v):u(u),v(v){}
}
vector<Edge> edges;//存储边的实际信息
vector<int> G[MAXN];//邻接矩阵存图

//添加一条边，无向图
void addEdge(int u, int v){
	edges.pb(u, v);
	edges.pb(v, u);
	int size = edges.size();
	G[u].pb(size - 2);
	G[v].pb(size - 1);
}

int init_parent(){
	for(int i = 0; i < MAXN; i++)
		parent[i] = -1;
}

int find(int x){
	int s;
	for(s = x; parent[s] >= 0; s = parent[s]);
	// compress path
	int tmp;
	while(s != x){
		tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}

int merge(int x, int y){
	int r1 = find(x), r2 = find(y);
	if(r1 == r2) return false;
	if(parent[r1] < parent[r2]){
		parent[r1] += parent[r2];
		parent[r2] = r1;
	}else{
		parent[r2] += parent[r1];
		parent[r1] = r2;
	}
	return true;
}

int dfs(root){





}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		memset(vis, false, sizeof(vis));
		init_parent();
		edges.clear();
		for(int i = 0; i < MAXN; i++)
			G[i].clear();

		cin >> points;
		for(int i = 0; i < points; i++){
			int u,v;
			cin >> u >> v;
			addEdge(u, v);
			flag[v] = true; //记录 V 具有前驱节点，这样就能找出来 root 节点，因为他们有前驱。
		}
		cin >> from_p >> to_p;
		int root_p;
		//寻找树根
		for(int i = 1; i <= points; i++)
			if(!flag[i]){
				root_p = i;
				break;
			}
		cout << dfs(root_p) << endl;
	}
	return 0;
}