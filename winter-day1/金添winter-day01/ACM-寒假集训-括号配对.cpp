#include <bits/stdc++.h>
using namespace std;
// ????? ? stack

int main()
{
    stack<char> mystack;
    string str;
    getline(cin,str);
    long long len=str.size();
    bool judge=true;
    for(int i=0;i<len;i++)
    {
        char remp;
        remp=str[i];
        if(remp=='('||remp=='{'||remp=='[')
        {
            mystack.push(remp);//???
        }
        else if(remp==')')
        {
            if(mystack.top()=='(')
            mystack.pop();     //??????????
            else
            {
                judge=false;
                break;
            }  
        }
        else if(remp=='}')
        {
            if(mystack.top()=='{')
            mystack.pop();     //??????????
            else
            {
                judge=false;
                break;
            }  
        }
        else if(remp==']')
        {
            if(mystack.top()=='[')
            mystack.pop();     //??????????
            else
            {
                judge=false;
                break;
            }  
        }
        else
        continue;
    }
    if(!mystack.empty())
    judge=false;

    if(judge)
    cout<<"yes"<<endl;
    else if(judge==false)
    cout<<"no"<<endl;
    return 0;
}