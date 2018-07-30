#include <iostream>
#include "common.h"
#include <cmath>
using namespace std;
typedef long long ll;
ll n;
ll h[100005];
ll quickPow(ll a,ll b)
{
    ll res = 1;
    a %= 998244353;
    while(b)
    {
        if(b & 1){
            res = (res*a)%998244353;
        }
        b >>= 1;
        a = (a*a)%998244353;
    }
    return res;
}
int main()
{
    testout("data1.out");
    int t;
    h[0] = h[1] = 1;
    for(int i=2;i<=100005;i++){
        h[i] = h[i-1]*(4*i-2)%998244353*quickPow(i+1,998244351)%998244353;
    }

    for(int i=0;i<100005;i++)
    cout<<h[i]<<" ";


    return 0;
}