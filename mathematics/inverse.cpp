#include "../common.h"
// 原理：https://www.cnblogs.com/TianyuSu/p/9391316.html


void extend_gcd(ll a, ll b, ll &gcd, ll &x, ll &y) {
	if (b == 0) {
		gcd = a;
		x = 1;
		y = 0;
	} else {
		extend_gcd(b, a % b, gcd, x, y);
		int x2 = x, y2 = y;
		x = y2;
		y = x2 - (a / b) * y2;
	}
}

//ax + by = gcd(a,b)
//gcd 保存了 a,b 的最大公约数
void ext_gcd(ll a, ll b, ll &gcd, ll &x, ll &y) {
	if (!b) { gcd=a; x=1; y=0; }
	else { ext_gcd(b,a%b,gcd,y,x); y-=(a/b)*x; }
	// 理解上面这个这句话就用上面的 extend_gcd 来理解，主要是使用了引用的概念
	// 并且 ext_gcd 在 y-=(a/b)*x 上面，也就是说 ext_gcd 参数中的 x,y 都是
	// 下一层函数返回的 x2, y2
	// 然后使用 y-=(a/b)*x 处理一下本层函数 y1 即可
}


ll inverse_ext_gcd(ll a, ll mod) {
	ll x, y, gcd;
	ext_gcd(a, mod, gcd, x, y);
	// gcd(x,mod) ==1 是有逆元的充要条件
	// 当满足有逆元的时候，需要调整 x 到 0-mod 之间
	// 对于负数 x+mod 即可调整正确，
	// 为了编码统一将正数页进行调整， (x+mod)%mod
	return gcd == 1 ? (x + mod) % mod : -1;
}


// 递推法快速求 逆元
const int maxn = 3e3 + 5;
ll inv[maxn];

//要求： mod 为奇质数
//公式: inv[i]=(mod - mod /i) * inv[mod%i]%mod
//初始条件: inv[1]=1;
void inverse_recursion(ll mod) {
	inv[1] = 1;
	for (int i = 2; i < maxn; i++)
		inv[i] = (mod - mod / i) * inv[mod % i] % mod;
}



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

ll inverse_quick_pow(ll a, ll mod){
	return quick_power(a,mod-2,mod);
}


int main(int argc, char const *argv[])
{
	// ll a,b,gcd,x,y;
	// a=6,b=12;
	// extend_gcd(a,b,gcd,x,y);
	// debug_b(gcd),debug_b(x),debug_b(y);


	inverse_recursion(23);
	for (int i = 1; i <= 22; i++) {
		debug_b(inv[i]), debug_b(inverse_ext_gcd(i, 23)),debug_l(inverse_quick_pow(i,23));
	}

	return 0;
}