#include<bits/stdc++.h>
using namespace std;
typedef struct node{
    int cj;
    string s;
}node;
#define N 100
bool cmp(node a,node b)
{
    if(a.cj < b.cj)return false;
    else if(a.cj > b.cj)return true;
    else {
        if(a.s.compare(b.s) > 0)return false;
        else return true;
    }
}
int main()
{
    int n;
    cin>>n;
    node f[N];
    for(int i = 0; i < n; i++)cin>>f[i].s>>f[i].cj;
    sort(f,f+n, cmp);
    for(int i = 0; i < n; i++)
    {
        if(i!=n - 1)
        cout<<f[i].s<<" "<<f[i].cj<<endl;
        else  cout<<f[i].s<<" "<<f[i].cj;
    }
    return 0;
}
