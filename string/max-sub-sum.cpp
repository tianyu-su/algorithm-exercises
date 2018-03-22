/*
	reference: https://www.cnblogs.com/aabbcc/p/6504605.html

*/

#include "../common.h"

/*
	思路：将数组分成左边，右边两部分，分别计算最大和
		 最大和主要有三个来源：
		 	1. mid 左边部分（不包含mid）
		 	2. mid 右边部分（不包含mid）
		 	3. 跨越mid的左右部分

		 1 2 部分可以通过递归求得，3 部分需要从 mid 开始，分别向左右直到 left(s1), right(s2),计算累加值
		 最后将左右两部分值相加就是跨域mid的最大和

		 最后一步： max(leftsum, right, s1+s2)

*/

int recursion(int *data, int left, int right){
	if(left == right){
		return max(0, data[left]);
	}
	int mid = (right - left) / 2 + left;
	int leftsum = recursion(data, left, mid);
	int rightsum = recursion(data, mid + 1, right);
	int s1 = 0, lefts = 0;
	for(int i = mid; i >= left; i--){
		lefts += data[i];
		s1 = max(s1, lefts);
	}
	int s2 = 0, rights = 0;
	for(int j = mid + 1; j <= right; j++){
		rights += data[j];
		s2 = max(s2, rights);
	}

	return max(max(leftsum, rightsum), s1 + s2);

}


int dp(int *data, int len){
	//记录字段和的头尾，使用一个临时头指针不停记录每一小段的开始。只有遇到更新最大值的时候才更新正式头指针
	int tmp_head = 0, sub_head = 0, sub_tail = 0;
	
	int ans = 0, d = 0;
	for(int i = 0; i < len; i++){
		if(d > 0)
			d += data[i];
		else{
			d = data[i];
			tmp_head = i;
		}
		if(d > ans){
			ans = d;
			sub_head = tmp_head;
			sub_tail = i;
		}
	}

	//打印序列
	for(int i = sub_head; i <= sub_tail; i++)
		cout<< data[i] << "\t";
	cout << endl;

	return ans;
}


int main(int argc, char const *argv[])
{
	int a[] = {-2,11,-4,13,-5,-2};
	cout << "recursion:" << recursion(a, 0, sizeof(a) / sizeof(int) - 1) << endl;
	cout << "dp:" << dp(a, sizeof(a) / sizeof(int)) << endl;
	return 0;
}