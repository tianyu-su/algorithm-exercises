#include "../common.h"

//求 m^n % k 
int quick_power(int m, int n, int k){
	int ans = 1;
	m %= k;
	while(n){
		if(n & 1)
			ans = ans * m % k;
		n >>= 1;
		m = m * m % k;
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	cout << quick_power(2, 300000, 20) << endl;
	return 0;
}