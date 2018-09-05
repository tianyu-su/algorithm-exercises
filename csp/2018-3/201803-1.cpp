#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	
	long long preSum=0;
	long long sum=0;
	int pre=-1;
	long long now;
	int first=0;
	while(cin>>now){
		if(now==0) break;
		if(now==2){
			if(!first || pre==1){
				first=1;
				sum+=2;
				preSum=2;
			}else{
				preSum+=2;
				sum+=preSum;
			}
		}
		else if(now==1){
			sum++;
			preSum=1;
		}
		pre=now;
	}
	cout<<sum<<endl;
	return 0;
}