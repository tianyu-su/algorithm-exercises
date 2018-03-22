/*
	重要： lazy 数组必须多开一个
	延迟标记： 主要用于多次对一个数组的区间内数字加减某个数，最后输出多次询问后的数组
	作用： 在每次询问的时候不对数组进行数据操作，只是在 lazy 数组里面进行标记，
	EG: 对 1-6 下标的元素进行 +5 操作，只需要 lazy[1] +=5 , lazy[6+1] -=5 即可
*/

#include "../common.h"
int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 5, 6};
	int data_len = sizeof(a) / sizeof(int);
	int *lazy = new int[data_len + 1];
	//init lazy
	fill(lazy, lazy + data_len, 0);

	//读入数据，l r n 表示区间 [l,r] + n 
	int l, r, n;
	while(~scanf("%d%d%d", &l, &r, &n)){
		lazy[l] += n;
		lazy[r + 1] -= n;
	}

	//output result

	int shift = 0;
	for(int i = 0; i < data_len; i++){
		shift += lazy[i];
		cout << a[i] + shift << "\t";
	}
	cout << endl;
	
	delete lazy;
	return 0;
}