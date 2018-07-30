#include "../common.h"

vector<pll> p_factor(ll x) {
	vector<pll> ans;
	for (ll i = 2; i * i <=x ; i++) {
		if(x % i == 0){
			ll cnt = 0;
			while(x%i==0){
				cnt++;
				x/=i;
			}
			ans.pb(mk(i,cnt));
		}
	}
	if(x>1) ans.pb(mk(x,1));
	return ans;
}

int main(int argc, char const *argv[])
{

	vector<pll> ans=p_factor(100);
	int len = ans.size();
	for(int i=0;i<len;i++)
		cout<< ans[i].first <<"^"<<ans[i].second<<" ";
	cout<<endl;
	return 0;
}