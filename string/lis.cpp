#include "../common.h"
/*reference: http://blog.csdn.net/qq_30241305/article/details/52068640
			 http://blog.csdn.net/qq_25605637/article/details/47173033
*/

//严格上升子序列

/*
O(n^2)
dp[i] 代表当前字符可到达的最长升序长度
*/
/**错误的 n*n 算法 ***/
int lis_n2_wrong(int data[], int len){
	int *dp = new int[len];
	int ans = 1;
	//初始状态,自身算长度 1
	fill(dp, dp + len, 1);

	//这个 i 是从 1 开始，不然下面 dp[j] 越界
	for(int i = 1; i < len; i++){
		int j = i - 1;
		while(j >= 0){
			//这是错误的算法。。。。 example: 2 5 3 4 1 7 6 
			if(data[i] > data[j]){
				dp[i] = dp[j] + 1;
				
				//不能遇到第一个小的就停止，应该和 j 前面的所有数字进行比较，正确删除 Break;
				break;
			}
			j--;
		}
		ans = max(ans, dp[i]);
	}

	delete dp;
	return ans;
}



int lis_n2(int data[], int len){
	int *dp = new int[len];
	int ans = 1;
	//初始状态,自身算长度 1
	fill(dp, dp + len, 1);

	//这个 i 是从 1 开始，不然下面 dp[j] 越界
	for(int i = 0; i < len; i++){
		for(int j = 0; j < i; j++){
			if(data[j] < data[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}

	delete dp;
	return ans;
}



/*
O(nlogn)
dp[i] 代表 长度为 i 的字符串, 序列最末尾的值
！！！ dp 数组不是 lis 串，仅仅是 i 长度的末尾字符， 
		dp[i] 随着 i 的增大，dp[i] 没有顺序关系
		仅仅是表示最末尾字符而已
*/

int lis_nlogn(int data[], int len){
	int *dp = new int[len];
	int ans = 1;
	//初始化第一个
	dp[0] = data[0];

	for(int i = 1; i < len; i++){
		if(data[i] > data[i-1]){
			dp[ans] = data[i];
			ans++;
		}
		else{
			int index = lower_bound(dp, dp + ans, data[i]) - dp;
			dp[index] = data[i];
		}
	}
	delete[] dp;
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
	// int a[] = {2,1,5,3,6,4,8,9,7};
	int a[] ={2, 5, 3, 4, 1, 7, 6};
	//int a[] = {9,8,7,6,5,4,3,2,1};

	int len = sizeof(a) / sizeof(int);

	cout<<"lis_n2:"<<lis_n2(a, len)<<endl;
	cout<<"lis_nlogn:"<<lis_nlogn(a, len)<<endl;
	cout<<"lis_nlogn_optimize:"<<lis_nlogn_optimize(a, len)<<endl;
	return 0;
}


