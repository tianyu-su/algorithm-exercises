#include "../common.h"

//求 m^n % k 
ll quick_power(ll m, ll n, ll k){
	ll ans = 1;
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
	cout << quick_power(2, 300000, 1e9+7) << endl;
	return 0;
}