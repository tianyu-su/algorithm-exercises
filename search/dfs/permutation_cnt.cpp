#include "../../common.h"
const int MAXN=50;

bool vis[MAXN];

int ans;

void dfs(int cur, int layer){
	if(cur==layer){
		ans++;
	}
	for(int i=0;i<layer;i++){
		if(!vis[i]){
			vis[i]=true;
			dfs(cur+1,layer);
			vis[i]=false;
		}
	}
}


int main(int argc, char const *argv[])
{
	ans=0;
	dfs(1,5);
	debug_l(ans);
	return 0;
}