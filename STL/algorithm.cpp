#include "../common.h"


void test_lower_upper_bound(){
	int a[] = {0,1,2,2,3};
	int len = sizeof(a) / sizeof(int);

	//2 的上下边界
	cout<<"lower_bound:"<<lower_bound(a, a + len, 2) - a << endl;
	cout<<"upper_bound:"<<upper_bound(a, a + len, 2) - a << endl;

	// 4 是大于序列所有值
	cout<<"lower_bound:"<<lower_bound(a, a + len, 4) - a << endl;
	cout<<"upper_bound:"<<upper_bound(a, a + len, 4) - a << endl;

}

int main(int argc, char const *argv[])
{
	
	test_lower_upper_bound();
	return 0;
}