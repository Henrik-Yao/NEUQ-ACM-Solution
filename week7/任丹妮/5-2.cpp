#include<bits/stdc++.h>
using namespace std;

string decoding()
{
    char ch;
    string str="",t="";
    int n;
    while(cin>>ch)
    {
        if(ch=='[')
        {
            cin>>n;
            str=decoding();
            for(int i=1;i<=n;i++)
            {
                t+=str;
            }
        }
        else if(ch==']')
        {
            return t;
        }
        else
        {
            t+=ch;
        }
    }
}

int main()
{
    cout<<decoding()<<endl;
    return 0;
}

