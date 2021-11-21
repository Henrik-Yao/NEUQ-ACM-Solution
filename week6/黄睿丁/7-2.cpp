#include<iostream>
#include <map>
#include <bits/stdc++.h>
using namespace std;
#define base 36
typedef unsigned long long  ull;
map<string,ull> account_hash;
map<string,string> account;
int read(char a)
{
    if(a>='a'&&a<='z')
        return a-87;
    if(a<='Z'&&a>='A')
        return a-55;
    if(a>='0'&&a<='9')
        return a-48;
    return 0;
}
ull ha(char a[])
{
    int len=strlen(a),i=0,l=len/4,x=len%4,sh1;
    while(i<len)
    {
        if(x>0)
        {
            int sum=0;
            for(int j=0;j<l;j++)
            {
                sum+=read(a[i++]);
            }
            sum=sum%base;
            x--;
            sh1=sh1*base+sum;
        }
        else
        {
            int sum=0;
            for(int j=0;j<l;j++)
            {
                sum+=read(a[i++]);
            }
            sum=sum%base;
            sh1=sh1*base+sum;
        }
        
    }
    return sh1;
}

int main()
{
    int n;
    cin>>n;
    for(int q=0;q<n;q++)
    {
        char way;
        cin>>way;
    if(way=='R')
    {
        char n[101],k[101];
        cin>>n>>k;
        ull key=ha(k);
        if(account.count(n))
            cout<<"Repeated!"<<endl;
        else
        {
            account[n]=k;
            account_hash[n]=key;
            cout<<"Signed!"<<endl;
        }
    }
    else if(way=='L')
    {
        char n[101],k[101];
        cin>>n>>k;
        ull key=ha(k);
        if(!account.count(n))
            cout<<"Failed!"<<endl;
        else
        {
            if(account_hash[n]==key)
            {
                if(account[n]!=k)
                    cout<<"Attention!"<<endl;
                else
                    cout<<"Success!"<<endl;
            }
            else
                cout<<"Failed!"<<endl;
            
            
        }
    }
    }
}
