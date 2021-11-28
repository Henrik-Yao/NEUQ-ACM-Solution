#include<bits/stdc++.h>
using namespace std;

string trans()
{
    char c;
    string s="";
    string ans="";
    int i;
    while(cin>>c)
    {
        if(c=='[')//遇到【进行递归
        {
            cin>>i;
            s=trans();
            for(int j=1;j<=i;j++)
            {
                ans = ans +s;
            }
        }
        else if(c==']')
        {
            return ans;
        }
        else
        {
            ans = ans +c;
        }
    }

}

int main()
{
    cout<<trans();
    return 0;
}
