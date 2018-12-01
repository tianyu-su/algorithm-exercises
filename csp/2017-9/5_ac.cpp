//https://blog.csdn.net/zearot/article/details/45028723
#include "../../common.h"
const int MANX = 101024;
long long  tree[MANX];
int seq[MANX];
int n, m;
void update(int idx, int delta) {
    while (idx <= n) {
        tree[idx] += delta;
        idx += idx & (-idx);
    }
}

ll get_sum(int idx) {
    ll ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        idx -= idx & (-idx);
    }
    return ans;
}


int main(int argc, char const *argv[])
{
    //testin("../../data.in");
    IOS;
     scanf("%d %d",&n,&m);
    for (int i = 1; i <= n; ++i) {
         scanf("%d",&seq[i]);
        update(i, seq[i]);
    }
    
    for (int i = 0; i < m; ++i) {
        int opt, l, r, v;
        scanf("%d %d %d",&opt,&l,&r);
        if (opt == 1) {
             scanf("%d",&v);
            if (v == 1) continue;
            for (int j = l; j <= r; j++) {
                if (seq[j] >= v && seq[j] % v == 0) {
                    update(j, -(seq[j] - seq[j] / v));
                    seq[j] /= v;
                }
            }
        }
        else
            printf("%lld\n",get_sum(r)-get_sum(l-1));
    }
    return 0;
}