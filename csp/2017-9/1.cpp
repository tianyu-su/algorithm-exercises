#include "../../common.h"
int main(int argc, char const *argv[])
{
	testin("../../data.in");
	int n;
	cin>>n;
	int cnt=n/50*7;
	cnt+=(n%50)/30*4;
	cnt+=((n%50)%30)/10;
	cout<<cnt<<endl;

	return 0;
}