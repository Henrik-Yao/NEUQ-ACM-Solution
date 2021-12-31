#include <iostream>
using namespace std;
typedef long long ll;
int arr[1000001];
ll c[1000001];
int lowbit(int a)
{
    return a&(-a);
}
void change(int a,int b,int n)
{
    int i;
    for(i=a;i<=n;i+=lowbit(i))
    {
        c[i]+=b;
    }
}

ll getsum(int a)
{
    int i;
    ll sum=0;
    for(i=a;i;i-=lowbit(i))
        sum+=c[i];
    return sum;
}

int main()
{
    int n,q;
    cin>>n>>q;
    int i,j,s=0;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        change(i,arr[i],n);
    }
    for(i=0;i<q;i++)
    {
        int o;
        cin>>o;
        if(o==1)
        {
            int x,y;
            cin>>x>>y;
            change(x,y,n);
        }
        else if(o==2)
        {
            int x,y;
            cin>>x>>y;
            cout<<getsum(y)-getsum(x-1)<<endl;
        }
            
    }
}
