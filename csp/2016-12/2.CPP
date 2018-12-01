#include "../../common.h"

const int MAXN = 100000;

int ok(int mon) {
    int tmp = mon - 3500;
    double sum = 0;
    if (tmp <= 0) return mon;

    if(tmp<=1500)
            sum=tmp*0.03;
        if(tmp>1500&&tmp<=4500)
            sum=1500*0.03+(tmp-1500)*0.1;
        if(tmp>4500&&tmp<=9000)
            sum=1500*0.03+3000*0.1+(tmp-4500)*0.2;
        if(tmp>9000&&tmp<=35000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(tmp-9000)*0.25;
        if(tmp>35000&&tmp<=55000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(tmp-35000)*0.3;
        if(tmp>55000&&tmp<=80000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(tmp-55000)*0.35;
        if(tmp>80000)
            sum=1500*0.03+3000*0.1+(9000-4500)*0.2+(35000-9000)*0.25+(55000-35000)*0.3+(80000-55000)*0.35+(tmp-80000)*0.45;
    return mon-sum;
}

int test(int t) {
    int l = 1, r = MAXN;
    while (l <= r) {
        int mid = (l + r) >> 1;
        int tmp = mid * 100;
        int flag = ok(tmp);
        if (flag == t) return tmp;
        if (flag > t)
            r = mid - 1;
        else
            l = mid + 1;
    }
    return t;
}

int main(int argc, char const *argv[])
{

    testin("../../data.in");
    int t;
    cin >> t;
    cout<<test(t)<<endl;
    return 0;
}