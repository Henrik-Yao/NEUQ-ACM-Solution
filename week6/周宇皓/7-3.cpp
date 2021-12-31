#include<bits/stdc++.h>
using namespace std;
string a,b;
bool che(char a)
{
    if(a>='a'&&a<='z') return true;
    return false;
}
bool check(string a,string b)//a big
{
    int len=b.size();
    for(int i=0;i<a.size();i++)
    {
        if(a.substr(i,len)==b) return true;
    }
    return false;
}
int main()
{
    getline(cin,a);
    cin>>b;
    for(int i=0;i<a.size();i++)
    {
        if(a[i]>='A'&&a[i]<='Z')
        a[i]=char(a[i]-'A'+'a');
    }
    for(int i=0;i<b.size();i++)
    {
        if(b[i]>='A'&&b[i]<='Z')
        b[i]=char(b[i]-'A'+'a');
    }
    string A;
    int cnt=0;
    for(int i=0;i<a.size();i++)
    {
        if(che(a[i])) A=A+a[i];
        else 
        {
            if(!che(a[i-1])) continue;
            cnt+=check(A,b);
            A="";
        }
    }
    cnt+=check(A,b);
    cout<<cnt<<endl;
    return 0;
}
