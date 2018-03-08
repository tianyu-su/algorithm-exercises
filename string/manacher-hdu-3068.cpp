
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;


char src[110000+2],pre_src[110000*2+2];
int R[110000*2+2];
//处理字符串，统一奇回文串和偶回文串，通过添加特殊字符，处理完后字符串长度： 2*n + 1 = n + n + 1
void init(char *src, char *pre_src, char special_char){
	int src_len = strlen(src);
	int i = 0, j = 0;
	while(i < src_len){
		pre_src[j++] = special_char;
		pre_src[j++] = src[i++];
	}
	pre_src[j++] = special_char;
	pre_src[j] = '\0';
}


int manacher(char *pre_src, char special_char){
	int pre_src_len = strlen(pre_src);
	int pos = 0, max_right = 0;         //需要维护的两个辅助变量，充分利用已经求得的回文序列半径
	int max_len = 0;                    //最长回文序列
	memset(R, 0, sizeof(int)*pre_src_len);
	for(int i = 0;i < pre_src_len; i++){
		if(i <= max_right)  //处理 i 在最右边界左边的情况，其中有分成两种，
                            //一种是 2*pos-i 处的回文长度较短和较长的时候.
			R[i] = min(R[2*pos-i], max_right-i);
        //暴力以当前 i 为对称轴进行回文检测
        //此处处理了 i 在 max_right 左侧但是 2*pos-i 处回文半径较长的情况和 i 在 max_right 右侧的情况
		while(i-R[i] >= 0 && i + R[i] < pre_src_len){
			if(pre_src[i-R[i]] == pre_src[i+R[i]]) R[i]++;
			else break;
		}
		//维护辅助变量
		if(i+R[i] > max_right){
			max_right = i + R[i] - 1;
			pos = i;
		}
		max_len = max(max_len ,R[i]);
	}
	return max_len - 1;			//回文半径-1 就是原来字符串的回文长度(由 2*R[i]-R[i]-1)
}

int main(int argc, char const *argv[])
{

    while(~scanf("%s",src)){
	init(src,pre_src,'#');
	printf("%d\n", manacher(pre_src,'#'));
    }
	return 0;
}

