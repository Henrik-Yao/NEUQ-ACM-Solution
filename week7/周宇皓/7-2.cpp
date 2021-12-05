#include<bits/stdc++.h>
using namespace std;

string t()
{
    char ch;
    string s="";
    string a="";
    int i;
    while((ch=getchar())!='\n')
    {
        if(ch=='[')
        {
            cin>>i;
            s=t();
            for(int j=1;j<=i;j++)
            {
                a+=s;
            }
        }
        else if(ch==']')
        {
            return a;
        }
        else
        {
            a+=ch;
        }
    }

}

int main()
{
    cout<<t();
    return 0;
}

