#include<bits/stdc++.h>
using namespace std;
int n;
char x;
string name[1005];
string mima[1005];
void zhuce(string name)
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(name==name[i])
        {
            f=1;
            break;
        }
    }
    if(f==1)cout<<"Repeated!"<<endl;
    else if(f==1)cout<<"Signed!"<<endl;
}
void login(string name,string mima)
{
    int f=0;
    for(int i=0;i<n;i++)
    {
        if(name==name[i])
        {
            f=1;
            break;
        }
    }
}
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        x=getchar();
        string a,b;
        cin>>a;
        cin>>b;
        if(x=='R')
        {
            name[i]=a;
            mima[i]=b;
        }
    }
}