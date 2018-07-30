#include "../common.h"
//原理：https://www.cnblogs.com/TianyuSu/p/9391102.html
//idea: 5 * 5 = 5 * (101)_2 = 5 * (100 * 1 + 10 * 0 + 1 *1) = 5 *( 4*1+2*0+1*1) = 5*1*1 + 5*2*0 + 5*4*1;
//use binary to optimize multiply

ll q_mult(ll a, ll b ,ll mod){
	ll ans = 0;
	while(b){
		if(b&1)
			ans = (ans + a)%mod;
		a = (a<<1) % mod;
		b>>=1;
	}
	return ans;
}

int main(int argc, char const *argv[])
{

	
	debug_l(q_mult(5,5000000001,100));

	return 0;
}