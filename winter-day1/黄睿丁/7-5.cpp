#include <bits/stdc++.h>
using namespace std;
bool state[100001];
int main()
{
    string s;
    while(cin>>s)
    {
        int left=0,right=0;
    int i,j,len=s.length();
    for(i=0;i<len;i++)
    {
        if(s[i]=='(')
        {
            int n=1;
            ++i;
            while(i<len)
            {
                if(s[i]=='(')
                {
                    n++;
                }
                else if(s[i]==')')
                {
                    n--;
                    if(n==0)
                        break;
                }
                i++;
            }
            right+=n;
        }
        else if(s[i]==')')
        {
                left++;
        }
    }
    if(left||right)
    {
        cout<<left+right<<endl;
    for(i=0;i<left;i++)
        cout<<"(";
    cout<<s;
    for(i=0;i<right;i++)
        cout<<")";
    cout<<endl;
    }
    else
        cout<<"Match"<<endl;
        memset(state,0,len);
    }
}
