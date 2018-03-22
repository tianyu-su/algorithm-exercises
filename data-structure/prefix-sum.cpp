#include "../common.h"

/*
	前缀和：当题目给你一组数据，不停的进行询问操作，为了不重复计算先预处理一个数组
	dp[i] : 代表到 0-i 位置的和

*/
int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6, 7};
	int len_data = sizeof(a) / sizeof(int);
	int *pre = new int[len_data];
	
	//pretreatment
	pre[0] = a[0];
	for (int i = 1; i < len_data; ++i){
		pre[i] = pre[i-1] + a[i];
	}

	//print_arr(pre, len_data);

	/*
	输出： m n 之前数据的和
	*/
	int l, r;
	while(~scanf("%d %d", &l, &r)){
		if(l == 0)
			cout << pre[r] << endl;
		else
			cout << pre[r] - pre[l-1] << endl;
	}

	delete pre;
	return 0;
}