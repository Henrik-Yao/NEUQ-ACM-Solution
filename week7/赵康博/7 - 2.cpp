#include <bits/stdc++.h>
using namespace std;

string f()
{
    string s;
    char a;
    while(cin>>a)
    {
        if(a=='['){
            int n;
            cin>>n;
            string t = f();
            for(int i = 0; i < n; i++)
            {
                s+=t;
            }
        }
        else if(a==']')return s;
        else s+=a;
    }
    return s;
}
int main()
{
    cout<<f();
    system("pause");
    return 0;
}