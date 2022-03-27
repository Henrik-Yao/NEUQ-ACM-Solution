#include<bits/stdc++.h>
using namespace std;
char s[200001];
int main()
{
    while(cin>>s)
    {
        stack<char> st;
        while(!st.empty()) st.pop();
        int left=0;
        bool flag=1;
        int l=strlen(s);
        for(int i=0;i<l;i++)
        {
            if(s[i]=='(')
            {
                st.push('(');
            }
            else
            {
                if(st.empty())
                {
                    left++;
                    flag=0;
                }
                else st.pop();
            }
        }
        if(flag&&st.empty())
        cout<<"Match"<<endl;
        else
        {
            cout<<left+st.size()<<endl;
            for(int i=0;i<left;i++) cout<<'(';
            cout<<s;
            for(int i=0;i<st.size();i++) cout<<')';
            cout<<endl;
        }
    }
    return 0;
}
