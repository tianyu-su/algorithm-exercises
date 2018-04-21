/*
	* reference: http://www.cnblogs.com/JVxie/p/4854719.html
*/
/*
	通过dfs先序遍历，维护并查集
*/

#include "../common.h"

const int MAXN = 10;
int parent[MAXN];
bool vis[MAXN];
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

void dfs(int root){




}

int main(int argc, char const *argv[])
{
	

	memset(vis, false, sizeof(vis));
	init_parent();
	return 0;
}