#include <bits/stdc++.h>
using  namespace  std;
#define  N 10000
int main()
{
    stack<char> f;
    char s[N];
    cin>>s;
    for(int i = 0; i < strlen(s); i++)f.push(s[i]);
    for(int i = 0; i < strlen(s); i++)
    {
        if(f.top()==s[i])f.pop();
        else {
            cout<<"no"<<endl;
            return 0;
        }
    }
    cout<<"yes"<<endl;
    return 0;
}