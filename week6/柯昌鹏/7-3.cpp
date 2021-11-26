#include <bits/stdc++.h>
using namespace std;

string a,b;
string  cont[10000];
int res;

int main ()
{
    getline(cin,a);
    getline(cin,b);
    int xa=a.length();
    int xb=b.length();
    for(int i=0;i<xb;i++)
    {
        if(b[i]>='A'&&b[i]<'Z')
    {
        b[i]+=32;
    }
    }
    int temp=0;int f=0;
    for(int i=0;i<xa;i++)
    {
        if(a[i]>'z'&&a[i]<'a'||a[i]<'A'&&a[i]>'Z')
        {
            if(f==1) f=0;
        }
        else {
            if(a[i]>='A'&&a[i]<'Z') a[i]+=32;
            if(f==0){
                f=1;
            temp++; }
            cont[temp]+=a[i];
        }
    }
    res=0;
    for(int i=0;i<=temp;i++)
    {
      if(cont[i].find(b)!=-1) res++;
    }
    cout<<res;
    return 0;
}