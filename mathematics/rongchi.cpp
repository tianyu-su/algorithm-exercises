//容斥原理,思路和 二进制求解子集差不多
// 示例:求解 [1,n] 中，不含 my_set  中因子的数目
// reference：
//https://www.cnblogs.com/xin-hua/p/3213050.html
#include "../common.h"


int my_set[] = {2, 5};

int rongchi(int n) {
	int ans = 0;
	int len_set = sizeof(my_set) / sizeof(int);
	int tot = 1 << len_set;
	for (int i = 1; i < tot; i++) {
		int bits = 0, mult = 1; //判断当前选中几个元素，容斥原理 奇加 偶减
		for (int k = 0; k < len_set; k++) {
			if (i & (1 << k)) {
				bits++;
				mult *= my_set[k];
				//处理爆 int 范围,如果不处理，下面的个数的时候出错
				if (mult < 0 || mult > n)
					mult = 0;
			}
		}
		if (mult && bits & 1)
			ans += n / mult;
		else if (mult)
			ans -= n / mult;

	}
	return n - ans;
}


int rongchi2(int n) {
	int ans = 0;
	int len_set = sizeof(my_set) / sizeof(int);
	int tot = 1 << len_set;
	for (int i = 1; i < tot; i++) {
		int bits = 0, tmp = n; //判断当前选中几个元素，容斥原理 奇加 偶减
		for (int k = 0; k < len_set; k++) {
			if (i & (1 << k)) {
				bits++;
				//把乘法逆过来使用，这样不需要考虑爆 INT
				tmp /= my_set[k];
			}
		}
		if (bits & 1)
			ans += tmp;
		else
			ans -= tmp;

	}
	return n - ans;

}



int main(int argc, char const *argv[])
{

	cout << rongchi2(10) << endl;
	return 0;
}