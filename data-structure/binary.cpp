#include "../common.h"


//返回目标值的下标，若目标值不存在则返回可插入的位置
int binary_int(int *data, int l, int r, int target){
	while(l <=r ){
		int mid = l + (r - l) / 2;
		if (data[mid] < target)
			l = mid + 1;
		else
			r = mid - 1;
	}
	return l;
}


//浮点数二分需要设置 eps，根据题目来设定，题目要求精度为1e-5时，我们的eps需要设置到1e-8甚至更多
double binary_double(double *data, double l, double r){
	const double eps = 1e-8;
	while(l + eps <= r){
		double mid = (l + r) / 2;
		if(check(mid))
			l = mid + eps;
		else
			r = mid - eps;
	}
	return l;

}

//浮点数二分，如果eps 太小会陷入死循环，那么就强行规定次数
//100次循环能达到1e-30的精度

double binary_double(double *data, double l, double r){
	for(int i = 0; i < 100; i++){
		double mid = (l + r) >> 1;
		if(check(mid))
			l = mid;
		else
			r = mid;
	}
	return l;

}

int main(int argc, char const *argv[])
{
	int a[] = {1, 2, 3, 4, 9};
	int data_len = sizeof(a) / sizeof(int);

	//返回找到的下标, output: 1
	cout << binary_int(a, 0, data_len - 1, 2) << endl;
	
	//返回可插入 5  的位置下标：output 4
	cout << binary_int(a, 0, data_len - 1, 5) << endl;
	return 0;
}