#include<bits/stdc++.h>
using namespace std;
string read()
{
    int n;
    char c;
    string s, s1;
    while(cin >> c)
    {
        if(c==']') return s;
        else 
        {
            if(c=='[') 
            {
                cin >> n;
                s1 = read();
                while(n--) s+=s1;
            }
            else s+=c;
        }
    }
}
int main()
{
    cout << read();
    return 0;
}
