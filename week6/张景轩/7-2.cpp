#include<iostream>
#include<vector>
#include<map>
using namespace std;

typedef long long ll;

vector<int> Hash(string s)
{
    for(int i = 0; i < s.size(); ++i)
        if(s[i] >= 'A' && s[i] <= 'Z')
        {
            s[i] = s[i] - 'A' + 'a';
        }
    vector<int> num;
    for(int i = 0; i < s.size(); ++i)
    {
        int a;
        if(s[i] >= '0' && s[i] <= '9') a = s[i] - '0';
        else a = s[i] - 'a' + 10;
        num.push_back(a);
    }
    for(int i = 0; i < 10; ++i) num.push_back(0);
    vector<int> ans;
    int div = s.size() / 4, sum = div * 4, now = 0;
    for(int i = 1; i <= 4; ++i)
    {
        int len = div;
        if(sum < s.size()) ++sum, ++len;
        int x = 0;
        for(int j = now; j <= now + len - 1; ++j) x += num[j];
        ans.push_back(x % 36);
        now += len;
    }
    return ans;
}

map<string, string> pw;
map<string, vector<int> > hs;

int main()
{
    int n; scanf("%d", &n);
    for(int i = 1; i <= n; ++i)
    {
        string opr, ids, pws;
        cin >> opr >> ids >> pws;
        if(opr == "R")
        {
            if(pw.count(ids))
            {
                puts("Repeated!");
                continue;
            }
            pw[ids] = pws;
            hs[ids] = Hash(pws);
            puts("Signed!");
        }
        else
        {
            if(!pw.count(ids))
            {
                puts("Failed!");
                continue;
            }
            if(pw[ids] == pws)
            {
                puts("Success!");
                continue;
            }
            if(hs[ids] == Hash(pws)) puts("Attention!");
            else puts("Failed!");
        }
    }
    return 0;
}