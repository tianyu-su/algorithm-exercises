#include "../../common.h"

map<string,int> qxmap;
map<string, map<string, int> > role;
map<string, vector<string> > user;

int query(string name, string priv) {
    string priv_name;
    int level;
    int strlen = priv.size();
    if (strlen - 2 >= 0 && priv[strlen - 2] == ':') {
        priv_name = string(priv, 0, strlen - 2);
        level = priv[strlen - 1] - '0';
    } else {
        priv_name = priv;
        level = -1;
    }

    //check name in users

    if (!user.count(name)) return 0;

    int flag = 0, maxl = NINF;
    for (vector<string>::iterator it = user[name].begin(); it != user[name].end(); ++it) {
        map<string, int>::iterator iter = role[*it].find(priv_name);
        if (iter != role[*it].end()) {
            if (level == -1 && iter->second == -1) return -1;
            if (level != -1 && level <= iter->second ) return -1;
            flag = 1;
            maxl = max(maxl, iter->second);
        }
    }
    if (flag)
        return maxl>qxmap[priv_name]?0:maxl;
    return 0;
}




int main(int argc, char const *argv[])
{
    testin("../../data.in");
    // IOS;
    int p, r, u, q;
    cin >> p; getchar();
    while (p--) {
        string priv,priv_name;
        int level;
        cin >> priv;
        int strlen = priv.size();
        if (strlen - 2 >= 0 && priv[strlen - 2] == ':') {
            priv_name = string(priv, 0, strlen - 2);
            level = priv[strlen - 1] - '0';
        } else {
            priv_name = priv;
            level = -1;
        }
        qxmap[priv_name]=level;

    }


    cin >> r; getchar();
    while (r--) {
        string str, rolename;
        int ln;
        cin >> rolename >> ln;
        map<string, int> tmpmap;
        for (int i = 0; i < ln; i++) {
            int flag = 0;
            cin >> str;
            if (tmpmap.count(str)) flag = 1;
            int strlen = str.size();
            if (strlen - 2 >= 0 && str[strlen - 2] == ':') {
                string ss = string(str, 0, strlen - 2);
                int le = str[strlen - 1] - '0';
                if (flag)
                    tmpmap[ss] = max(tmpmap[ss], le);
                else
                    tmpmap[ss] = le;
            }
            else {
                tmpmap[str] = -1;
            }
        }
        role[rolename] = tmpmap;
    }

    string name, ur, priv;
    int un, rn;;
    cin >> un; getchar();
    while (un--) {
        cin >> name >> rn;
        for (int i = 0; i < rn; i++) {
            cin >> ur;
            user[name].pb(ur);
        }
    }
    int qn;
    cin >> qn; getchar();

    while (qn--) {
        cin >> name >> priv;
        int ret = query(name, priv);
        if (ret == 0) printf("false\n");
        else if (ret == -1) printf("true\n");
        else
            printf("%d\n", ret);
    }
    return 0;
}