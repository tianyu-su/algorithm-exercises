#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
char src[1000002],pattern[10002];
int next[10002];

int kmp_matches(char *text, char *pattern, int *next){
	int res_i = 0;
	int i = 0 ,j = 0, text_len = strlen(text), pattern_len = strlen(pattern);
	while(i < text_len){
		if(j >= pattern_len){	//此处说明完成一次匹配
			res_i++;
			j=next[j];		//回溯 J 的位置，不是 j=0; 匹配完继续匹配看作是失配，所以继续查找next值
							//如果 j=0; 主串 abababa， 模式串 aba 的结果是1次匹配，正确是3次
		}
		if(j == -1 || text[i] == pattern[j]) {i++;j++;}
		else j = next[j];
	}
	if(j >= pattern_len) res_i++;
	return res_i;
}

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
	int t;
	cin>>t;

	while(t--){
		scanf("%s%s",pattern, src);
		get_next(pattern,next);
		printf("%d\n",kmp_matches(src,pattern,next));
	}
	return 0;
}

