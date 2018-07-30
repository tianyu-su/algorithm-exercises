#include "../common.h"
//原理：https://www.cnblogs.com/TianyuSu/p/9391331.html
const int maxn = 3e3 + 5;

//直接法，根据定义求解 欧拉函数，适用于求解少量
ll euler_direct(ll x) {
	ll ans = x;
	for (ll i = 2; i * i <= x; i++) {
		if (x % i == 0) {
			ans = ans / i * (i - 1); //使用定义式计算，先除后乘防止溢出
			while (x % i == 0) x /= i; //除掉所有这个因子
		}
	}
	//当剩余的 x 为质数的时候, e.g. 10带入算法
	if (x > 1) ans = ans / x * (x - 1);
	return ans;
}


//线性筛选法，适用于多求解多个数的欧拉函数
ll euler_table[maxn];

void euler_filter() {
	//每一个都初始化为n,相当于公式里面的n
	for (int i = 2; i < maxn; i++)
		euler_table[i] = i;
	//筛法
	for (ll i = 2; i < maxn; i++) {
		if (euler_table[i] == i) //这一步保证 i 一定是质数
			for (int j = i; j < maxn; j += i)	//给所有公式中包含这个质数的项求解
				euler_table[j] = euler_table[j] / i * (i - 1);
	}
}


int main(int argc, char const *argv[])
{

	testout("data.out");
	// for (int i = 2; i < 20; i++)
	// 	cout << euler_direct(i) << endl;


	euler_filter();
	for (int i = 1; i < maxn; i++)
		cout << euler_table[i] << endl;


	return 0;
}