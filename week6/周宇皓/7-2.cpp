#include<bits/stdc++.h>
using namespace std;
int cal(string str)
{
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        ans+=str[i]-'0';
        else if(str[i]<='Z')
        {
            ans+=str[i]-'A'+10;
        }
        else 
        ans+=str[i]-'a'+10;
    }
    return ans%36;
}
int Cal(string str)
{
    int len=str.size();
    int ave=len/4,mod=len%4;
    int a[5];
    for(int i=1;i<=4;i++)
    {
        if(i<=mod) a[i]=ave+1;
        else a[i]=ave;
    }
    int temp=0,ans=0;
    for(int i=1;i<=4;i++)
    {
        string now=str.substr(temp,a[i]);
        ans=ans*36+cal(now);
        temp+=a[i];
    }
    return ans;
}
unordered_map<string,string> mstr;
unordered_map<string,int> mint;
char choice;
string name,pass;
int t;
int main()
{
    cin>>t;
    while(t--)
    {
        cin>>choice>>name>>pass;
        if(choice=='R')
        {
            if(mstr.count(name))
            cout<<"Repeated!"<<endl;
            else 
            {
                mstr[name]=pass;
                mint[name]=Cal(pass);
                cout<<"Signed!"<<endl;
            }
        }
        else if(choice=='L')
        {
            if(mstr.count(name))
            {
                if(mstr[name]==pass) cout<<"Success!"<<endl;
                else 
                {
                    if(mint[name]==Cal(pass)) cout<<"Attention!"<<endl;
                    else cout<<"Failed!"<<endl;
                }
            }
            else cout<<"Failed!"<<endl;
        }
    }
    return 0;
}
