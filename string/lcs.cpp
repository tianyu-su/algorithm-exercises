/* reference: http://blog.csdn.net/yebanxin/article/details/52186706
			  http://blog.csdn.net/yebanxin/article/details/52190683
			  */

/* lcs 可以解决删除字符串中某些字符，变成一个回文序列
(核心：将字符串翻转，找这两个的最长公共子序列就是那个回文序列)
*/

#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;


//思路：通过判断两个字符串最后一位是否相等分情况

//这种递归的方法只能求解长度，不能知道 LCS 串的构成
int lcs_recursion(char *str1, char *str2, int str1_len, int str2_len){
	if(str1_len == 0 || str2_len == 0) return 0;
	if(str1[str1_len-1] == str2[str2_len-1])
		return 1 + lcs_recursion(str1, str2, str1_len-1, str2_len-1);	//这步实现递归向结果进行
	else{
		int a = lcs_recursion(str1, str2, str1_len, str2_len-1);
		int b = lcs_recursion(str1, str2, str1_len-1, str2_len);
		return max(a,b);
	}
}


int lcs_length_dp(char *str1, char *str2, vector<vector<int> > &vec){
	//初始化 dp 矩阵， 数值表示 i，j 长度中最长公共串大小

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);

	//vec 构造成矩阵
	for(int i = 0; i < str1_len+1; i++)
		vec[i].assign(str2_len+1, 0);		//全部赋值0，顺带将 0行， 0列 赋值为0,作为dp的起始状态

	//初始化 dp 矩阵的 0行，0列
	// for(int i = 0; i < str1_len+1; i++)
	// 	vec[0][i] = 0;
	// for(int i = 0; i < str2_len+1; i++)
	// 	vec[i][0] = 0;

	for(int i = 0; i < str1_len; i++){
		for(int j = 0; j < str2_len; j++){
			if(str1[i] == str2[j])		//如果局部最后一个字符相等，那么就是左上角数值+1
				vec[i+1][j+1] = vec[i][j] + 1;
			else						//如果局部最后一个字符不相等，那么就是上边和左边的最大值，延续之前求出的这个值，为了继续求解
				vec[i+1][j+1] = max(vec[i][j+1], vec[i+1][j]);	
		}
	}
	return vec[str1_len][str2_len];
}



//回溯得到最长公共序列，和求解方式一样考虑，只有值为左上角+1得到才是lcs其中字符
//参数中 i, j 需要根据 Vector 中的数据来分配
void lcs_dp(char *str, vector<vector<int> > &vec, int i, int j){
	if(i == 0 || j == 0) return;
	if(vec[i][j] == vec[i][j-1]) 
		lcs_dp(str, vec, i, j-1);
	else if(vec[i][j] == vec[i-1][j]) 
		lcs_dp(str, vec, i-1, j);
	else {
		//局部末尾相等
		lcs_dp(str, vec, i-1, j-1);
		cout << str[i-1];
	}
}


//http://blog.csdn.net/liuchenjane/article/details/52618783
//优化上面使用矩阵进行dp，由于dp中只用到了，左上角，左边，上边的数值，因此只要维护3个值即可
//使用 a[0] 存储 左上角， a[i] 原值是上边， a[i-1] 是左边
int lcs_length_dp_optimize(char *str1, char *str2){
	int str1_len = strlen(str1);
	int str2_len = strlen(str2); 
	vector<int> vec(str1_len+1, 0);
	for(int i = 0; i < str2_len; i++){
		vec[0] = 0;			//a[0] 充当了左边和左上角双重作用，在j=0时
		for(int j = 0; j < str1_len; j++){
			int tmp = vec[j+1];
			if(str1[j] == str2[i])
				vec[j+1] = vec[0] + 1;
			else
				vec[j+1] = max(vec[j+1], vec[j]);
			vec[0] = tmp;
		}

	}
	return vec[str1_len];
}


//http://blog.csdn.net/yebanxin/article/details/52190683
int lcs_consecutive_length_dp_optimize(char *str1, char *str2){
	int str1_len = strlen(str1);
	int str2_len = strlen(str2); 

	int max_len = 0, max_len_end_index = 0;
	vector<int> vec(str1_len+1, 0);					//滚动数组记录长度
	vector<int> str_index_len(str1_len, 0);			//记录当前行每个字符的最大长度

	for(int i = 0; i < str2_len; i++){
		vec[0] = 0;
		for(int j = 0; j < str1_len; j++){
			int tmp = vec[j+1];
			vec[j+1] = (str1[j] == str2[i] ? vec[0] + 1 : 0);
			str_index_len[j] = (vec[j+1]>str_index_len[j]) ? vec[j+1] : str_index_len[j];
			max_len = max_len < vec[j+1]? vec[j+1] : max_len;
			vec[0] = tmp;				//左上角元素
		}
	}

	cout<<"最长连续子串:";
	int tmp_len = str_index_len.size();
	for(int i = 0;i < tmp_len; i++){
			if(str_index_len[i] == max_len){
				for(int j = max_len-1; j >= 0; j--)
					cout<<str1[i - j];
				cout<<'\t';
			}
	}
	cout<<endl;
	return max_len;
}


int main(int argc, char const *argv[])
{
	char *str1="fjasdklfjjsaionclkskdjfiojsckljsaijfiojclknlkdsfoijakj;ajfoisajklfjaskln;asfjiacna;";
	char *str2="asdklfijjaj";

	int str1_len = strlen(str1);
	int str2_len = strlen(str2);
	


	//这种方式直接初始化好了
	// vector<vector<int> > vec (str1_len+1, vector<int>(str2_len+1,0));
	vector<vector<int> > vec (str1_len+1);
	cout<<"dp_length:"<<lcs_length_dp(str1,str2,vec)<<endl;
	cout<<"lcs:";
	lcs_dp(str1,vec,str1_len,str2_len);
	// LCS(str1,vec,strlen(str1)-1,strlen(str2)-1);
	
	cout<<endl;

	cout<<"dp_length_optimize_space:" << lcs_length_dp_optimize(str1,str2);
	cout<<endl;
	// cout<< "\nrecursion_length:"<<lcs_recursion(str1,str2,strlen(str1),strlen(str2))<<endl;


	//最长公共连续子序列
	char *str3="ababila";
	char *str4="alibaba";
	lcs_consecutive_length_dp_optimize(str3,str4);
	return 0;
}
