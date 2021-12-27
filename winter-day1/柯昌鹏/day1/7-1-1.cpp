#include <iostream>
using namespace std;
int n,q;
long long  a[1000005],c[1000005];

int lowbit(int i)//lowbit运算
{
    return i&(-i);
}

void update(int i,int k)//更新区间
{
   while(i<=n)
   {
       c[i]+=k;
       i+=lowbit(i);
   }
}

long long  getsum(int i)//求1-i这个区间的和
{
    long long  res=0;
    while (i>0)
    {
        res+=c[i];
        i-=lowbit(i);
    }
    return res;
}

int main ()
{
    cin>>n>>q;
    
    c[0]=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        update(i,a[i]);
    }
    while(q--)
    {
      int x,m,b;
      cin>>x>>m>>b;
      if(x==1)
      {
        update(m,b);
      }
      else if(x==2)
      {
        long long  sum=getsum(b)-getsum(m-1);//这个m-1，emm
        cout<<sum<<endl;
      }
    } 
    return 0; 
}