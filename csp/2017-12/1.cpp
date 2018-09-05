#include <iostream>
#include <algorithm>
using namespace std;
int d[10005];

int main(int argc, char const *argv[])
{
	
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>d[i];
	sort(d,d+n);
	int minn=0x3f3f3f3f;
	for(int i=0;i<n-1;i++)
		minn=min(minn,d[i+1]-d[i]);
	cout<<minn<<endl;
	return 0;
}