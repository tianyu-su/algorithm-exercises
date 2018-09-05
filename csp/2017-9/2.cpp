#include "../../common.h"

//status 0取，1还
struct Node
{
	int time,status,index;
};

Node events[1005];
int vis[1005];
int cmp(Node n1,Node n2){
	if(n1.time==n2.time){
		if(n1.status==1 && n2.status==1)
			return n1.index<n2.index;
		return n1.status>n2.status;
	}
	return n1.time<n2.time;
}

int main(int argc, char const *argv[])
{
	//testin("../../data.in");
	int N,K;
	cin>>N>>K;
	for(int i=1;i<=N;i++)
		vis[i]=i;
	int index,get,hold;
	int cur=0;
	for(int i=0;i<K;i++){
		cin>>index>>get>>hold;
		Node n1,n2;
		n1.time=get;n1.status=0;n1.index=index;
		n2.time=get+hold;n2.status=1;n2.index=index;
		events[cur++]=n1;
		events[cur++]=n2;
	}


	sort(events,events+cur,cmp);
	for(int i=0;i<cur;i++){
		Node n=events[i];
		if(n.status==0){
			int j=0;
			while(vis[++j]!=n.index);
			vis[j]=INF;//被取走
		}
		else{
			int j=0;
			while(vis[++j]!=INF);
			vis[j]=n.index;
		}

	}
	// for(int i=0;i<cur;i++)
	// 	printf("%d %d %d\n",events[i].time,events[i].status,events[i].index);

	for(int i=1;i<=N;i++)
		cout<<vis[i]<<" ";
	cout<<endl;
	return 0;
}