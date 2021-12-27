#include <bits/stdc++.h>
using  namespace  std;
//#define  N 10000
int main()
{
    char t;
    stack <char> s;
    while (cin>>t)
    {
        if(t=='('||t=='['||t=='{')s.push(t);
        else if(t==')'||t==']'||t=='}')
        {
            if(t==')'&&s.top()=='(')s.pop();
            else if(t==']'&&s.top()=='[')s.pop();
            else if(t=='}'&&s.top()=='{')s.pop();
            else {
                cout<<"no"<<endl;
                return 0;
            }
        }
        else ;
    }
    if(s.empty())cout<<"yes"<<endl;
    else cout<<"no"<<endl;
    return 0;
}