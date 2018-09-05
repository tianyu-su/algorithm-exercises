#include "../../common.h"
//正解是用树状数组维护区间，忘了 = =，直接暴力 = =
const int MANX = 100005;
int seq[MANX];

int main(int argc, char const *argv[])
{
    testin("../../data.in");
    IOS;
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        cin >> seq[i];
    int opt, l, r, v;
    for (int i = 0; i < m; ++i) {
        /* code */
        cin >> opt >> l >> r;
        if (opt == 1) {
            cin >> v;
            for(int j=l;j<=r;j++){
                if(seq[j]%v==0)
                    seq[j]/=v;
            }
        } 
        else {
            ll ans=0;
            for(int j=l;j<=r;j++)
                ans+=seq[j];
            cout<<ans<<endl;
        }
    }
    return 0;
}