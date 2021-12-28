#include <iostream>
#define lowbit(i) ((i)&(-i))
using namespace std;
const int maxn=1000005;

int n,q;
long long c[maxn];

void update(int x,int v)
{
    for(int i=x;i<=n;i=i+lowbit(i))
    {
        c[i]=c[i]+v;
    }
}
long long sum(int x){
    long long sum=0;
    for(int i=x;i>0;i=i-lowbit(i))
    {
        sum=sum+c[i];
    }
    return sum;
}
 int main()
 {
     cin>>n>>q;
     for(int i=1;i<=n;i++)
     {
        int ans;
        cin>>ans;
        update(i,ans);
     }
     while(q--){
        int mode,temp,x;
        cin>>mode>>temp>>x;
        if(mode==1)
        {
            update(temp,x);
        }
        else
        {
            cout<<sum(x)-sum(temp-1);
        }
     }
 }