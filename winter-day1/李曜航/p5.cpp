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
    while(cin>>a)
    {
        stack <char> st;
        for(int i=0;i<a.size();i++)
        {
            if(!st.empty()&& st.top()=='('&&a[i]==')') 
                st.pop();
            else 
                st.push(a[i]);
        }
        int right = 0, left = 0;
        while(!st.empty())
        {
            if(st.top()=='(')
            {
                right++;
                st.pop();
            }
            else if(st.top()==')')
            {
                left++;
                st.pop();
            }
            // cout<<st.top();st.pop();
        }
        if(left+right)
        {
            cout<<left+right<<endl;
            for(int i=1;i<=left;i++)
                printf("(");
            cout<<a;
            for(int i=1;i<=right;i++)
                printf(")");
            cout<<endl;
        }
        else
        {
            printf("Match\n");
        }
        // cout<<endl;
    }

}