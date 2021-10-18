#include<iostream>
#include<string>
using namespace std;

struct people
{
    int num;
    string name;
} acm[100001];

int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>acm[i].num>>acm[i].name;
    }

    int now=1;
    for(int i=1;i<=m;i++)
    {
        int flag,x;
        cin>>flag>>x;
        if(acm[now].num==flag) now=now-x;
        else if(acm[now].num!=flag) now=now+x;

        if(now>n) now=now%n;
        else while (now<=0) now=now+n;
    }

    cout<<acm[now].name;
    return 0;
}