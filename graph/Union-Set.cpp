#include <cstdio>

const int  MAXN=20;

//parent数组记录 i 的父亲节点，初始化为-1，增加节点减一，
//负数代表根节点，本节点树的大小为 节点绝对值
int parent[MAXN];

//初始化 parnet 数组
void init(){
	for(int i=0;i<MAXN;i++) 
		parent[i]=-1;
}


//查找根节点
int find_root(int x){
	int s=x;
	while(parent[s]!=-1)
		s = parent[s];
	//路径压缩
	int tmp;
	while(x!=s){
		tmp = parent[x];
		parent[x] = s;
		x = tmp;
	}
	return s;
}


//合并两个集合，小树合并到大树
bool union_set(int x, int y){
	int x_root = find(x);
	int y_root = find(y);
	//如果是同一个集合，不可以合并，否则集合大小发生改变
	if(x_root == y_root) return false;
	int cnt = parent[x_root] + parent[y_root];
	if(parent[x_root] < parent[y_root]){
		//x_root 树大
		parent[x_root] = cnt;
		parent[y_root] = x_root;
	}else{
		parent[y_root] = cnt;
		parent[x_root] = y_root;
	}	
	return true;
}


int main(int argc, char const *argv[])
{
	

	return 0;
}