#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<char> s1;
stack<char> s2;
stack<char> s3;

int main()
{
    string s;
    bool flag = true;
    getline(cin,s);
    for(int i=0;i<s.length();i++)
    {
        if(s[i] == '(')
        {
            s1.push('(');
        }
        else if(s[i] == ')')
        {
            s1.pop();
        }
        else if(s[i] == '[')
        {
            s2.push('[');
        }
        else if(s[i] == ']')
        {
            s2.pop();
        }
        else if(s[i] == '{')
        {
            s3.push('{');
        }
        else if(s[i] == '(')
        {
            s3.pop();
        }
        else
        {
            continue;
        }
    }

    if(s1.empty() && s2.empty() && s3.empty())
    {
        cout<<"yes";
    }
    else
    {
        cout<<"no";
    }

    return 0;
}

