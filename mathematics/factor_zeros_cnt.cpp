//https://blog.csdn.net/qq_40679299/article/details/81167283
#include "../common.h"
const int MAXN = 100;

//素数表
int prime[MAXN]={2};
//保存 alpha
int ind[MAXN]={0};
//保存 alpha·k 的乘积
int cnt[MAXN]={0};

//一种方式
int cnt_R_10_1(int n){
	int ans=0,mult=5;
	while(mult<=n){
		ans+=n/mult;
		mult*=5;
	}
	return ans;
}

//另一种方式，乘法的逆向思维
int cnt_R_10_2(int n){
	int ans=0;
	while(n){
		ans+=n/5;
		n/=5;
	}
	return ans;
}


void init(){
	int k=1;
	for(int i=3;i<=MAXN;i+=2){
		int flag=0;
		for(int j=2;j*j<=i;j++){
			if(i%j==0){
				flag=1; break;
			}
		}
		if(!flag)
			prime[k++]=i;
	}
}


//求 alpha·k 的乘积
int getcnt(int x, int p){
	int ans = 0;
	while(x){
		ans+=x/p;
		x/=p;
	}
	return ans;
}

int cnt_R_M(int n,int M){
	init();

	//看 M 可以被哪些质数分解
	for(int i=0;i<MAXN;i++){
		if(prime[i]){
			while(M % prime[i]==0){
			ind[prime[i]]++;
			M /= prime[i];
			}
		}		
	}


	for(int i=0;i<MAXN;i++){
		if(ind[i]) cnt[i]=getcnt(n,i);
	}

	int ans=1e8;
	for(int i=0;i<MAXN;i++){
		if(cnt[i]) ans=min(ans,cnt[i]/ind[i]);
	}

	return ans;

}


int main(int argc, char const *argv[])
{
	//求解十进制下 N! 中末尾连续零
	// cout<<"1: "<<cnt_R_10_1(2015)<<endl;
	// cout<<"2: "<<cnt_R_10_2(2015)<<endl;


	//2015! 在 M 进制下末尾连续零
	cout<<cnt_R_M(2015,10)<<endl;
	return 0;
}