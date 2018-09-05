#include "../../common.h"
char totalStr[9010];
char scanStr[100];

int totalStrIndex = 0;
void catstr(char * scanStr) {
	int i = -1;
	while (scanStr[++i]) {
		if (scanStr[i] != ' ') {
			if ((scanStr[i] == '\"' || scanStr[i]  == '\\') && totalStr[totalStrIndex - 1] == '\\') {
				totalStr[--totalStrIndex] = scanStr[i];
			}
			else
				totalStr[totalStrIndex] = scanStr[i];
			totalStrIndex++;
		}
	}
}


vector<string> split(char * extra) {
	int i = 0;
	int begin = 0;
	vector<string> ans;
	while (extra[i]) {
		if (extra[i] == '.') {
			ans.pb(string(extra + begin, i - begin));
			begin = i + 1;
		}
		i++;
	}
	ans.pb(string(extra + begin, i - begin));
	return ans;
}

int ans_type, ans_start, ans_end;
void solve(vector<string> cxzd, int now, int start, int end) {
	int i = start;
	int nowLen = cxzd[now].size();
	int flag = 0;
	while (i <= end) {
		int j = 0;
		if (totalStr[i] == '\"' && flag == 0) {
			i++;
			if (i + nowLen <= end) {
				for (; j < nowLen; j++) {
					if (cxzd[now][j] != totalStr[i + j]) break;
				}
				if (j == nowLen && totalStr[i + j] == '\"') {
					for (j++; i + j <= end; j++) {
						if (totalStr[i + j] == '\"') {
							ans_type = 0;
							ans_start = i + j + 1;
							int z = 0;
							for (; i + j + z <= end; z++) {
								if (totalStr[i + j + z] == ',') break;
							}
							ans_end = i + j + z - 2;
							return;
						} else if (totalStr[i + j] == '{') {
							int num = 1;
							int z = 1;
							for (; num && i + j + z <= end; z++) {
								if (totalStr[i + j + z] == '{') num++;
								if (totalStr[i + j + z] == '}') num--;
							}
							if (now == cxzd.size() - 1) {
								ans_type = 1;
								return;
							} else {
								solve(cxzd, ++now, i + j + 1, i + j + z - 2);
								return;
							}
						}
					}
				}
			}
		}
		if (totalStr[i] == ':') flag = 1;
		else if (totalStr[i] == ',' && flag == 1) flag = 0;
		if (j && j <= nowLen)
			i += j;
		else
			i++;

	}
	ans_type = 3; //不存在
}


int main(int argc, char const *argv[])
{
	// testin("../../data.in");
	int n, m;
	cin >> n >> m;
	getchar();
	while (n--) {
		gets(scanStr);
		catstr(scanStr);
	}
	totalStr[totalStrIndex] = '\0';
	while (m--) {
		gets(scanStr);
		vector<string> cxzd = split(scanStr);
		solve(cxzd, 0, 1, strlen(totalStr) - 2);
		if (ans_type == 0) {
			cout << "STRING ";
			for (int i = ans_start; i <= ans_end; i++)
				putchar(totalStr[i]);
			putchar('\n');
		} else if (ans_type == 1) {
			cout << "OBJECT" << endl;
		} else
			cout << "NOTEXIST" << endl;

	}
	return 0;
}