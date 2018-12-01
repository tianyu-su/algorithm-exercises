#include <cstdio>
long long tree[101024];
int n,m,a[101024];
void update(int idx, int delta) {
    while (idx <= n) {
        tree[idx] += delta;
        idx += idx & (-idx);
    }
}

long long getsum(int idx) {
    long long ans = 0;
    while (idx > 0) {
        ans += tree[idx];
        idx -= idx & (-idx);
    }
    return ans;
}

int main()
{
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;++i)
    {
        scanf("%d",&a[i]);
        update(i,a[i]);
    }
    for(int i=1;i<=m;++i)
    {
        int opt,l,r,v;
        scanf("%d %d %d",&opt,&l,&r);
        if(opt==1) 
        {
            scanf("%d",&v);
            if(v==1)continue;
            for (int j = l; j <= r; j++) {
                if (a[j] >= v && a[j] % v == 0) {
                    update(j, -(a[j] - a[j] / v));
                    a[j] /= v;
                }
            }
        }
        else
            printf("%lld\n",getsum(r)-getsum(l-1));
    }
    return 0;
}