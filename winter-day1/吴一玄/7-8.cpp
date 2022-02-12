#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 1000010;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

int stk1, stk2, stk3;

int main()
{
    string s;
    getline(cin, s);
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(') ++stk1;
        if(s[i] == '[') ++stk2;
        if(s[i] == '{') ++stk3;
        if(s[i] == ')')
        {
            if(!stk1) return cout << "no\n", 0;
            else --stk1;
        }
        if(s[i] == ']')
        {
            if(!stk2) return cout << "no\n", 0;
            else --stk2;
        }
        if(s[i] == '}')
        {
            if(!stk3) return cout << "no\n", 0;
            else --stk3;
        }
    }
    if(!stk1 && !stk2 && !stk3) cout << "yes\n";
    else cout << "no\n";
    return 0;
}