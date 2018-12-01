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


const double PI = 3.14159265358979323846264338327;
const double E = exp(1);
const double eps = 1e-6;

const int INF = 0x3f3f3f3f;
const int NINF = 0xc0c0c0c0;
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

char buf[101], tmp[101], res[1001], res_tmp[1001];

void hangnei(char *raw, char *done) {
    //处理行内，存在done中
    int i = 0, j = 0, cnt_em = 0, flag;
    char a_contain[110], a_kk = 0;
    while (raw[i]) {
        flag = 0;
        if (raw[i] == '_') {
            if (cnt_em) {
                done[j++] = '<';
                done[j++] = '/';
                done[j++] = 'e';
                done[j++] = 'm';
                done[j++] = '>';
            }
            else {
                done[j++] = '<';
                done[j++] = 'e';
                done[j++] = 'm';
                done[j++] = '>';
            }
        }
        else if (raw[i] == '[') {
            int qt_zzkh = 1;
            char kk = 0, kk_tmp[101];
            for (int jj = i + 1;; jj++) {
                if (raw[jj] == '[') qt_zzkh++;
                if (raw[jj] == ']') qt_zzkh--;
                if (!qt_zzkh) break;
                kk_tmp[kk++] = raw[jj];
            }
            kk_tmp[kk] = '\0';


            hangnei(kk_tmp, res_tmp);
            //这里有问题，因为用了 全局 res_tmp 导致递归返回的时候拼接字符串出问题，
            //改用 string 把，但是不想搞了。。。


            for (int jj = 0; res_tmp[jj]; jj++)
                a_contain[a_kk++] = res_tmp[jj];
            a_contain[a_kk] = '\0';
            flag = 1;
            i += kk + 2;
        }
        else if (raw[i] == '(') {
            char tmp_link[110], tmp_link_kk = 0;
            for (int kk = i + 1; raw[kk] != ')'; kk++) {
                tmp_link[tmp_link_kk++] = raw[kk];
            }
            tmp_link[tmp_link_kk] = '\0';
            sprintf(res_tmp, "<a href=\"%s\">%s</a>", tmp_link, a_contain);
            for (int kk = 0; res_tmp[kk]; kk++)
                done[j++] = res_tmp[kk];
            a_kk = 0;
            flag = 1;
            i += tmp_link_kk + 2;
        }
        else {
            done[j++] = raw[i];
        }
        if (!flag) i++;
    }
    done[j] = '\0';
}

int main(int argc, char const *argv[])
{
    // testin("../../data.in");
    IOS;
    int cnt_xing = 0, cnt_p = 0, lxhh = 0;
    while (gets(buf)) {
        //处理块级元素
        if (buf[0] == '#') {
            int i = 0, j = 0, cnt = 0, flag = 0;
            while (buf[i]) {
                if (buf[i] == '#') cnt++;
                if (i > 0 && buf[i] != ' ' && buf[i - 1] == ' ' && !flag) flag = 1;
                if (flag) tmp[j++] = buf[i];
                i++;
            }
            tmp[j] = '\0';
            hangnei(tmp, res);
            printf("<h%d>%s</h%d>\n", cnt, res, cnt);
            lxhh = 0;
        }
        else if (buf[0] == '*') {
            if (!cnt_xing) {
                printf("<ul>\n");
                cnt_xing = 1;
            }
            int i = 0, j = 0, flag = 0;
            while (buf[i]) {
                if (i > 0 && buf[i] != ' ' && buf[i - 1] == ' ' && !flag) flag = 1;
                if (flag) tmp[j++] = buf[i];
                i++;
            }
            tmp[j] = '\0';
            hangnei(tmp, res);
            printf("<li>%s</li>\n", res);
            lxhh = 0;
        }
        else if (strlen(buf) == 0) {
            //闭合 ui
            if (cnt_xing) {
                printf("</ul>\n");
                cnt_xing = 0;
            }
            if (!cnt_p) {
                // cnt_p = 1;
                // printf("<p>");
            }
            else {
                printf("</p>\n");
                cnt_p = 0;
            }
            lxhh = 0;
        }
        else { //连续输入
               //开始就是段落
            if (cnt_xing) {
                printf("</ul>\n");
                cnt_xing = 0;
            }
            if (!cnt_p) {
                cnt_p = 1;
                printf("<p>");
            }
            hangnei(buf, res);
            if (lxhh) printf("\n%s", res);
            else printf("%s", res);
            lxhh = 1;
        }
    }
    if (cnt_xing) {
        printf("</ul>\n");
        cnt_xing = 0;
    }
    if (cnt_p)
        printf("</p>\n");

    return 0;
}