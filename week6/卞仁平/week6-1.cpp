#include <bits/stdc++.h>
using namespace std;
int nex[100005];
int sum=0;
void getnext(string p,int plen)
{
    int k=-1;
    nex[0]=-1;
    for(int i=1;i<plen;i++)
    {
        while(k>-1&&p[k+1]!=p[i])
        k=nex[k];
        if(p[k+1]==p[i])
        k++;
        nex[i]=k;
    }
}
void kmp(string p,int plen,string t,int tlen)
{
    int k=-1;
    for(int i=0;i<tlen;i++)
    {
        while(k>-1&&p[k+1]!=t[i])
        k=nex[k];
        if(p[k+1]==t[i])
        k++;
        if(k==plen-1)sum++;
    }
}
int main()
{
    string t,p;
    cin>>t>>p;
    int tlen=t.length();
    int plen=p.length();
    getnext(p,plen);
    kmp(p,plen,t,tlen);
    cout<<sum;
    return 0;
}