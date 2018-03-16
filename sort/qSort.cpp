//reference：http://blog.csdn.net/newbie006/article/details/54747360

#include "../common.h"

//挖坑填数，快排不是稳定的算法，最差就是排序已经有序数组
void qSort(int left, int right, int *data){

	int l=left, r=right, key=data[l];
	if(l<r){
		while(l<r){
			while(l<r && data[r] > key)
				r--;
			data[l]=data[r];
			while(l<r && data[l] <= key)
				l++;
			data[r]=data[l];
		}
		data[l]=key;

		qSort(left, l-1, data);
		qSort(l+1, right, data);
	}
}

int main(int argc, char const *argv[])
{
	int a[]={6,5,4,3,2,1};
	qSort(0,5,a);
	print_arr(a,6);
	return 0;
}