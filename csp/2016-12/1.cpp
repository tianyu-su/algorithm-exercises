#include "../../common.h"
int seq[1005];
int main(int argc, char const *argv[])
{
    testin("../../data.in");
    IOS;
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>seq[i];
    sort(seq,seq+n);
    int mid=seq[n/2];
    int ans=0;
    for(int i=0,j=n-1;i<=j;i++,j--){
        if(seq[i]<mid) ans++;
        if(seq[j]>mid) ans--;
    }
    printf("%d\n", ans?-1:mid);
    return 0;
}