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

int main()
{
    string s;
    cin >> s;
    int l = 0, r = 0;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == '(') l = i;
        if(s[i] == ')') r = i;
    }
    for(int i = 0 ; i < s.size(); ++i)
    {
        if(s[i] == 'A') cout << "sae";
        else if(s[i] == 'B') cout << "tsaedsae";
        else if(s[i] == '(')
        {
            cout << s[i + 1];
            for(int j = r - 1; j >= l + 2; --j)
            {
                cout << s[j];
                cout << s[i + 1];
            }
            i = r;
        }
        else if(s[i] == '#') return 0;
    }
    return 0;
}