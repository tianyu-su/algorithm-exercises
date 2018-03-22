#include "../common.h"
/*reference: http://blog.csdn.net/qq_30241305/article/details/52068640
			 http://blog.csdn.net/qq_25605637/article/details/47173033
*/

//严格上升子序列

/*
O(n^2)
dp[i] 代表当前字符可到达的最长升序长度
*/
int lis_n2(int data[], int len){
	int *dp = new int[len];
	int ans = 1;
	//初始状态,自身算长度 1
	fill(dp, dp + len, 1);

	//这个 i 是从 1 开始，不然下面 dp[j] 越界
	for(int i = 1; i < len; i++){
		int j = i - 1;
		while(j >= 0){
			if(data[i] > data[j]){
				dp[i] = dp[j] + 1;
				break;
			}
			j--;
		}
		ans = max(ans, dp[i]);
	}

	delete dp;
	return ans;
}


/*
O(nlogn)
dp[i] 代表最长子序列为 i 时, 序列最末尾的值
*/

int lis_nlogn(int data[], int len){
	int *dp = new int[len];
	int ans = 0;
	for(int i = 0; i < len; i++){
		if(ans == 0 || data[i] > data[i-1]){
			dp[ans] = data[i];
			ans++;
		}
		else{
			int index = lower_bound(dp, dp + ans, data[i]) - dp;
			dp[index] = data[i];
		}
	}

	delete dp;
	return ans;
}


int lis_nlogn_optimize(int data[], int len){
	int *dp = new int[len];
	int ans = 0;
	for(int i = 0; i < len; i++){
		//如果使用 lower_bound 查找的数是最大的，那么自然返回最后一个位置
		int index = lower_bound(dp, dp + ans, data[i]) - dp;
		dp[index] = data[i];
		if(ans == index)
			ans++;
	}

	delete dp;
	return ans;
}

int main(int argc, char const *argv[])
{
	int a[] = {2,1,5,3,6,4,8,9,7};
	//int a[] = {9,8,7,6,5,4,3,2,1};

	int len = sizeof(a) / sizeof(int);

	cout<<"lis_n2:"<<lis_n2(a, len)<<endl;
	cout<<"lis_nlogn:"<<lis_nlogn(a, len)<<endl;
	cout<<"lis_nlogn_d:"<<lis_nlogn_d(a, len)<<endl;
	return 0;
}


