//https://www.cnblogs.com/TianyuSu/p/9391376.html
#include "../common.h"
const int N = 2e5+10;
const ll mod = 998244353;
ll fac[N];

void extgcd(ll a,ll b,ll& d,ll& x,ll& y){
    if(!b){ d=a; x=1; y=0;}
    else{ extgcd(b,a%b,d,y,x); y-=x*(a/b); }
}
ll inv(ll a,ll n){
    ll d,x,y;
    extgcd(a,n,d,x,y);
    return d==1?(x+n)%n:-1;
}

void init() {
    fac[0] = fac[1] = 1;
    for(int i = 2; i < N; ++i) {
        fac[i] = fac[i-1]*i%mod;
    }
}
ll cat(ll n) {
    return fac[2*n]*inv(fac[n+1]*fac[n],mod)%mod;
}
int main(int argc, char *argv[]) {
    init();
    ll t;
    while(cin>>t) cout<<cat(t)<<endl;
}