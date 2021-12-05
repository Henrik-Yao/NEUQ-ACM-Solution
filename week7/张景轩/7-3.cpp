#include<iostream>
#include<vector>
#include<map>
using namespace std;

int n, m;
string S, str;
map<char, int> mp;
int main()
{
    while (getline(cin, S))
    {
        getline(cin, str);
        vector<char> vec;

        n = S.size(),m = str.size();
        for (int i = 0; i <= m; i++) 
        {
            if (!mp.count(str[i]))
            {
                mp[str[i]] = 1;
            }
        }
        for (int i = 0; i <= n; i++) 
        {
            if (mp.count(S[i]))
            {
                continue;
            }
            else
            {
                vec.push_back(S[i]);
            }
        }
        for (int i = 0; i < vec.size(); i++) 
        {
            i != vec.size() - 1 ? cout << vec[i] : cout << vec[i] << endl;
        }
        vec.clear();
        S = "", str = "";
        mp.clear();
    }
    
    return 0;
}