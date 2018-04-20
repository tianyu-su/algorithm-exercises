#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <queue>


#define max3(x, y, z) max(max((x), (y)), (z))
#define min3(x, y, z) min(mix((x), (y)), (z))
#define pb push_back
#define mk make_pair

typedef long long ll;

using namespace std;

template<typename T>
void print_arr(T *arr, int arr_len){
	for(int i=0;i<arr_len;i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}

