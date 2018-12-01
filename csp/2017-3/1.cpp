#include "../../common.h"

int main(int argc, char const *argv[])
{
    testin("../../data.in");
    IOS;
    int n,k,t;
    cin>>n>>k;
    ll ans=0,tmp=0;
    for(int i=0;i<n;i++){
        cin>>t;
         tmp+=t;
        if(tmp>=k){
            ans++;
            tmp=0;
        }
    }
    if(tmp && tmp<k) ans++;   
    cout<<ans<<endl;
    return 0;
}