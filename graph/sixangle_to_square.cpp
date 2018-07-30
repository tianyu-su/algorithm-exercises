// 原理：https://www.cnblogs.com/TianyuSu/p/9382779.html
// 题目：https://www.nowcoder.com/acm/contest/85/G
#include "../common.h"

int Cur[maxn], Map[maxn][maxn];


int main(int argc, char const *argv[])
{
	memset(Map, NINF, sizeof(Map));
	testin("../data.in");
	int n;
	cin >> n;
	int vis = 4 * n - 3;
	int cur = 2 * n - 1;

	//计算每行录入数量,写一下每行的数量就能发现规律
	for (int i = 0; i < vis - n; i++) {
		if (i <= i % n)
			Cur[i] = i % n + 1;
		else {
			if (n & 1)
				Cur[i] = (i & 1) ? n - 1 : n;
			else
				Cur[i] = (i & 1) ? n : n - 1;
		}
	}
	for (int i = vis - 1; i >= vis - n; i--)
		Cur[i] = vis - i;

	vector<int> edges[vis];
	//读入边
	int tmp;
	for (int i = 0; i < vis; i++) {
		for (int j = 0; j < Cur[i]; j++) {
			cin >> tmp;
			edges[i].pb(tmp);
		}
	}

	//转换六边形存储到二维数组中
	//从六边形“右斜”来看，按二维数组行构造

	//首先构造从第一斜到最长的斜
	int i, j;	//i 是第几行，j 是斜线上有几个元素
	int len = cur / 2 + 1;
	int flag = 0;
	for (j = n, i = 0; i < len; i++, j++) {
		for (int k = 0, L = flag; k < j; k++, L++) {
			Map[i][k] = edges[L][edges[L].size() - 1];
			edges[L].ppb();
			if (edges[L].size() == 0)
				flag++;
		}
	}



	//构造剩下的半个
	//j - 2
	for (j -= 2; i < cur; i++, j--) {
		for (int k = cur - j, L = flag; k < cur; k++, L++) {
			Map[i][k] = edges[L][edges[L].size() - 1];
			edges[L].ppb();
			if (edges[L].size() == 0)
				flag++;
		}
	}

	for (int i = 0; i < cur; i++) {
		for (int j = 0; j < cur; j++)
			cout << Map[i][j] << " ";
		cout << endl;
	}

	return 0;
}
