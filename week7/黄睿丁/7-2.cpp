#include <iostream>
#include <string>
using namespace std;
string open(string a)
{
    int len=a.length(),flag=0;;
    string b="";
    for(int i=1;i<len;i++)
    {
        if(a[i]!='['&&a[i]!=']')
        b+=a[i];
        if(a[i]=='[')
        {
            flag=1;
             int k=i;
            int j=0;
            while(1)
            {
                if(a[i]=='[')
                    j++;
                if(a[i]==']')
                    j--;
                if(j==0)
                    break;
                i++;
            }
            b+=open(a.substr(k+1,i-k));
        }
    }
    string ans="";
    int s=a[0]-'0';
    if(flag==0)
    {
    for(int i=0;i<s;i++)
    {
        ans+=a.substr(1,a.length()-2);
    }
    return ans;
    }
    else
    {
        for(int i=0;i<s;i++)
        ans+=b;
        return ans;
    }
        
}
string da(string a)
{
    string b="";
    int len=a.length();
    for(int i=0;i<len;i++)
    {
        if(a[i]!='['&&a[i]!=']')
            b+=a[i];
        if(a[i]=='[')
        {
            int k=i;
            int j=0;
            while(1)
            {
                if(a[i]=='[')
                    j++;
                if(a[i]==']')
                    j--;
                if(j==0)
                    break;
                i++;
            }
            b+=open(a.substr(k+1,i-1));
        }
    }
    return b;
}
int main()
{
    string a;
    cin>>a;
    cout<<da(a);
}
