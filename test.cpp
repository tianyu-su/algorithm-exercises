#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <string>
#include <ctime>
#include <cmath>
using namespace std;

string LCS_continuous(string str1,string str2)
{
    int i,j,maxnum=0,maxj=0;
    int n1=str1.size(),n2=str2.size();
    vector<int> last,cur,temp;//last、cur记录上一行、当前行的LCS信息，temp作为辅助数组。
    for(i=0;i<n2+1;i++)//初始值：第0行第0列置0
    {
        last.push_back(0);
        cur.push_back(0);
    }
    temp=cur;
    for(i=1;i<=n1;i++)
    {
        cur=temp;//cur清零
        for(j=1;j<=n2;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                cur[j]=last[j-1]+1;
                if(cur[j]>maxnum)//更新最大值
                {
                    maxnum=cur[j];
                    maxj=j-1;//记录最大值列号
                }
            }
        }
        last=cur;//把当前行信息传递给last
    }

    for(int i=0;i<temp.size();i++)
        cout<<temp[i]<<'\t';
    
    return str2.substr(maxj-maxnum+1,maxnum);
}


int main(int argc, char const *argv[])
{
   int a=sqrt(15);
   cout<<a;
    return 0;
}