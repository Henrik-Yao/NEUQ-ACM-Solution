#include <bits/stdc++.h>
using namespace std;
map<string, pair<string, string>> depo;
char part(string s)
{
    int sum = 0;
    for (int i = 0; i < s.length(); ++i)
        (s[i] >= '0' && s[i] <= '9') ? sum += s[i] - '0' : sum += tolower(s[i]) - 'a' + 10;
    sum %= 36; //取36进制的个位
    return sum < 10 ? sum + '0' : sum - 10 + 'a';
}
string Hash(string s)
{
    string hash = "0000"; //设初值，不然会无端碰撞
    int l = s.length();
    int len[4] = {0}; //长度数组
    for (int i = 0; i < l % 4; ++i)
    {
        len[i]++;
    }
    int t = 0;
    for (int i = 0; i < 4; ++i)
    {
        len[i] += l / 4;
        string s1 = s.substr(t, len[i]);
        t += len[i];
        char h = part(s1);
        hash[i] = h;
    }
    return hash;
}
int main(void)
{
    int n;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char ch;
        string account, password, hash;
        cin >> ch >> account >> password;
        hash = Hash(password);
        if (ch == 'R')
        {
            if (depo.find(account) != depo.end()) //用户已存在
                cout << "Repeated!" << endl;
            else //向库中存数据
            {
                depo[account].first = password;
                depo[account].second = hash;
                cout << "Signed!" << endl;
            }
        }
        else if (depo.find(account)->second.first == password) //账号密码匹配
            cout << "Success!" << endl;
        else if (depo.find(account)->second.second == hash) //账号密码不匹配但撞哈希值
            cout << "Attention!" << endl;
        else
            cout << "Failed!" << endl;
    }
    return 0;
}