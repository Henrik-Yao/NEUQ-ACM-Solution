#include<bits/stdc++.h>
using namespace std;
char str[200009];
int main()
{
    while(cin>>str)
    {
        stack<char> s;
        while(!s.empty()) s.pop();
        int zuo=0;
        bool flag=1;
        int len=strlen(str);
        for(int i=0;i<len;i++)
        {
            if(str[i]=='(')
            {
                s.push('(');
            }
            else 
            {
                if(s.empty()) 
                {
                    zuo++;
                    flag=0;
                }
                else s.pop();
            }
        }
        if(flag&&s.empty()) cout<<"Match"<<endl;
        else 
        {
            cout<<zuo+s.size()<<endl;
            for(int i=0;i<zuo;i++) cout<<'(';
            cout<<str;
            for(int i=0;i<s.size();i++) cout<<')';
            cout<<endl;
        }
    }
    return 0;
}
