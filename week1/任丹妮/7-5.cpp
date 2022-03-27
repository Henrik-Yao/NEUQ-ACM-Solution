#include <iostream>
#include <string>
using namespace std;
struct club{
    int a;
    string b;
}mem[100001];
struct code{
    int c;
    int d;
}tip[100001];
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>mem[i].a>>mem[i].b;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>tip[i].c>>tip[i].d;
    }
    int j=1;
    for(int i=1;i<=m;i++)
    {
        for(int l=1;l<=m;l++)
        if((mem[j].a==0&&tip[l].c==0)||(mem[j].a==1&&tip[l].c==1)) j=(j-tip[l].d+n)%n;
        else if((mem[j].a==0&&tip[l].c==1)||(mem[j].a==1&&tip[l].c==0)) j=(j+tip[l].d+n)%n;
    }
    cout<<mem[j].b;
}
