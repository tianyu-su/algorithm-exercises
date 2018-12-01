#include "../../common.h"

int seq[1005];
int n,m,p,q;
int findj(int val){
    for(int i=1;i<=n;i++)
        if(seq[i]==val) return i;
}
int main(int argc, char const *argv[])
{
    testin("../../data.in");
    IOS;
    cin>>n>>m;
    for(int i=1;i<=n;i++) seq[i]=i;
    for(int i=0;i<m;i++){
        cin>>p>>q;
        int idx;
        if(q>0){
            idx=findj(p);
            for(int j=idx;j<idx+q;j++)
                swap(seq[j],seq[j+1]);
        }else{
            idx=findj(p);
            for(int j=idx;j>idx+q;j--)
              swap(seq[j],seq[j-1]);  
        }
    }
    for(int i=1;i<=n;i++)
        cout<<seq[i]<<" ";
    cout<<endl;
    return 0;
}