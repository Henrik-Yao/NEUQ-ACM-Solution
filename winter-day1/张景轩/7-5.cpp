#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> st1;
stack<char> st2;

int main()
{
    string s;
    while(getline(cin,s))
    {
        int len1 = 0;
        int len2 = 0;
        
        int len = s.length();
        for(int i=0;i<len;i++)
        {
            if(s[i] == '(')
            {
                st1.push('(');
            }
            else if(s[i] == ')')
            {
                if(st1.empty())
                {
                    st2.push(')');
                }
                else
                {
                    st1.pop();
                }
            }
        }
        
        if(st1.empty() && st2.empty())
        {
            cout<<"Match"<<endl;
        }
        else
        {
            
            while(!st1.empty())
            {
                len1++;
                st1.pop();
            }
            while(!st2.empty())
            {
                len2++;
                st2.pop();
            }
        }
        int oper = len1 + len2;
        if(oper != 0)
        {
            cout<<oper<<endl;
            for(int i=1;i<=len2;i++)
            {
                cout<<"(";
            }
            cout<<s;
            for(int i=1;i<=len1;i++)
            {
                cout<<")";
            }
            cout<<endl;
        }
        
    }
    
    return 0;
}
