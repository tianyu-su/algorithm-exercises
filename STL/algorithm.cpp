#include "../common.h"


void test_lower_upper_bound(){
	int a[] = {0,1,2,2,3,5,5,5,5};
	int len = sizeof(a) / sizeof(int);

	//2 的上下边界
	cout<<"lower_bound:"<<lower_bound(a, a + len, 2) - a << endl;
	cout<<"upper_bound:"<<upper_bound(a, a + len, 2) - a << endl;

	// 4 是大于序列所有值
	cout<<"lower_bound:"<<lower_bound(a, a + len, 4) - a << endl;
	cout<<"upper_bound:"<<upper_bound(a, a + len, 4) - a << endl;

	//获取某一元素在数组中的个数
	cout << "get numebers of 2: " << upper_bound(a, a + len, 5) - lower_bound(a, a + len, 5) << endl;
}

int main(int argc, char const *argv[])
{
	
	test_lower_upper_bound();
	return 0;
}