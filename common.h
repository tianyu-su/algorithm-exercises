#include <algorithm>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <vector>
#include <cstdlib>

using namespace std;


#define max3(x, y, z) max(max((x), (y)), (z))
#define min3(x, y, z) min(mix((x), (y)), (z))
#define mset(a,b) memset((a),(b),(sizeof(a)))
#define pb push_back
#define ppb pop_back
#define mk make_pair
#define pii pair<int, int>
#define pll pair<long long, long long>


#define debug_l(a) cout << #a << " " << (a) << endl
#define debug_b(a) cout << #a << " " << (a) << " "
#define testin(filename) freopen((filename) ,"r",stdin)
#define testout(filename) freopen((filename) ,"w",stdout)


#define IOS ios::sync_with_stdio(false);cin.tie(0)



typedef long long ll;
typedef unsigned long long ull;


const double PI  = 3.14159265358979323846264338327;
const double E   = exp(1);
const double eps = 1e-6;

const int INF    = 0x3f3f3f3f;
const int NINF   = 0xc0c0c0c0;
// int maxn   = 3e3 + 5;
// int MOD    = 1e9 + 7;


template <typename T>
void print_arr(T *arr, int arr_len)
{
	for (int i = 0; i < arr_len; i++)
		cout << arr[i] << " ";
	cout << endl;
}

/*==================================begin=======================================*/
