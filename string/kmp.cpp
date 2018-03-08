/*reference: https://www.zhihu.com/question/21923021
			 https://www.cnblogs.com/zhangtianq/p/5839909.html    优化next数组
			 */
//problems: poj 3461
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


//返回主串中第一次出现位置
int kmp_first_match(char *text, char *pattern, int *next){
	int first_match_index = -1;
	int i = 0 ,j = 0, text_len = strlen(text), pattern_len = strlen(pattern);
	while(i < text_len && j < pattern_len){
		if(j == -1 || text[i] == pattern[j]) {i++;j++;}		//next数组模式串0位置设置成-1，方便代码编写。
															//达到第一个字符不匹配时，主字符串向后移动，
															//模式串在0位置
		else j = next[j];	//回溯模式串，加速匹配
	}
	if(j == pattern_len) return i-j;
	else return -1;
}


//返回主串出现位置数组大小
int kmp_matches(char *text, char *pattern, int *next, int *res_indexs){
	int res_i = 0;
	int i = 0 ,j = 0, text_len = strlen(text), pattern_len = strlen(pattern);
	memset(res_indexs, 0, sizeof(res_indexs));
	while(i < text_len){
		if(j >= pattern_len){	//此处说明完成一次匹配
			res_indexs[res_i++] = i-j;
			j=next[j];		//回溯 J 的位置，不是 j=0; 匹配完继续匹配看作是失配，所以继续查找next值
							//如果 j=0; 主串 abababa， 模式串 aba 的结果是1次匹配，正确是3次
		}
		if(j == -1 || text[i] == pattern[j]) {i++;j++;}
		else j = next[j];
	}
	if(j >= pattern_len) res_indexs[res_i++] = i-j;		//处理模式串和主串一样长度并且匹配情况
	return res_i;
}



//获取next数组，获取next数组思路和kmp思路一样
//将模式串分别作为主串和模式串进行前缀和、后缀和的最长匹配
//i 指针指向主串代表后缀和，j 指针指向模式串代表前缀和
void get_next(char *pattern, int *next){
	memset(next, 0, sizeof(next));
	next[0] = -	1;
	int i = 0, j = -1, pattern_len = strlen(pattern);
	while(i < pattern_len){
		if(j == -1 || pattern[i] == pattern[j]) {
			i++;j++;
			next[i] = j;
		}
		else j = next[j];
	}
}



int main(int argc, char const *argv[])
{
	/* code */
	char *src="BAPC";
	char *p="BAPC";
	int* next = new int[strlen(p)];
	get_next(p, next);
	int res = kmp_first_match(src, p, next);
	int *res_arry = new int[strlen(src)];
	int matches = kmp_matches(src, p, next, res_arry);
	cout << "first_match_index: " << res <<endl;

	cout << "match list "<<matches<<":";
	for(int i=0; i< matches;i++)
		cout<<res_arry[i]<<"\t";
	cout << endl;
	return 0;
}
