#include <bits/stdc++.h>
#define N (int)1e6
using namespace std;

typedef struct persom
{
    char Sex;
    int F;
    int M;
    int c;
}Person;
Person s[N];
int v[N];
int Xun[N];
int t = 0;
void p(int x,int n){
    if(n==6||x==-1){
        return ;
    };
    v[x] = 1;
    if(s[x].c!=1)return ;
    p(s[x].F,n+1);
    p(s[x].M,n+1);
}
void pn(int x,int n){
    if(n==6||x==-1){
        return ;
    };
    v[x] = 0;
    if(s[x].c!=1)return ;
    pn(s[x].F,n+1);
    pn(s[x].M,n+1);
}
void f(int x,int n){
    if(n==6||x==-1)return ;
    if(v[x]==1){
        t = 1;
    }
    if(s[x].c!=1)return ;
    f(s[x].F,n+1);
    f(s[x].M,n+1);
}
int main()
{
    int n;
    cin>>n;
    for(int i = 0; i < n; i++){
        int m;
        cin>>m;
        cin>>s[m].Sex>>s[m].F>>s[m].M;
        s[m].c = 1;
        s[s[m].F].Sex = 'M';
        s[s[m].M].Sex = 'F';
    }
    int k;
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        int a,b;
        cin>>a>>b;
        if(s[a].Sex==s[b].Sex)
        {
            cout<<"Never Mind";
            if(i!=k-1)cout<<endl;
            continue;
        }
        p(a,1);
        f(b,1);
        if(t==1)cout<<"No";
        else cout<<"Yes";
        if(i!=k-1)cout<<endl;
        t = 0;
        pn(a,1);
    }
    return 0;
}