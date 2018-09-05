#include <iostream>
#include <algorithm>
using namespace std;

int seq[1005];

int main(int argc, char const *argv[])
{
	//testin("../../data.in");
	int n, k;
	cin >> n >> k;
	int t = n;
	int i = 1;
	long long no = 1;
	while (t != 1) {
		if (!seq[i]) {
			if (no % 10 == k || no % k == 0) {
				t--;
				seq[i] = 1;
			}
			no++;
		}
		i++;
		i %= (n + 1);
		if (!i) i = 1;
	}
	for(i=1;i<=n && seq[i];i++);
	cout << i << endl;
	return 0;
}