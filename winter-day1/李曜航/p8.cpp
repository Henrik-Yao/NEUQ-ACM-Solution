#include <bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){ if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){ x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
    return x*f;
}
int main()
{
    // freopen("read.in","r",stdin);
    string a;
    cin>>a;
    stack <char> st;
    for(int i=0;i<a.size();i++)
    {
        if(!st.empty()&& (
        (st.top()=='('&&a[i]==')') || 
        (st.top()=='['&&a[i]==']') ||
        (st.top()=='{'&&a[i]=='}')
        ))
        {
            st.pop();
        }
        else if(a[i]=='('||a[i]==')'||a[i]=='['||a[i]==']'||a[i]=='{'||a[i]=='}')
        {
            st.push(a[i]);
        }
    }
    if(st.empty())
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }
    

}