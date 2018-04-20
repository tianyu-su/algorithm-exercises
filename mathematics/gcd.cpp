#include "../common.h"


int gcd(int a, int b){
	return b > 0 ? (gcd(b, a % b)):(a);
}


ll gcd_for(ll a, ll b){
	ll tmp;
	while(b){
		tmp = b;
		b = a % b;
		a = tmp;
	}
	return a;
}


int main(int argc, char const *argv[])

{
	
	ll a = 549755813888 , b = 524288 ;
	cout<< gcd_for(a, b)<<a/b;
	return 0;
}
