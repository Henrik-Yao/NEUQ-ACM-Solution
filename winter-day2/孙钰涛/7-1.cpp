#include<bits/stdc++.h>
using namespace std;
int book[404],sum[101];
int a[101],m,n,x,i,mmax=-99999999,res=0;

struct node
{
	int x;
	int h;
}tree[404];

void create(int idx,int h)
{
    if(book[idx]==0)
    {
        tree[idx].x=a[++m];
        tree[idx].h=h;
        book[idx]=1;
        n=max(n,idx);
        if(a[m]==0) return ;
    }
    create(idx*2,h+1);
    create(idx*2+1,h+1);
}

void fun(int ddd)
{
	if(tree[ddd].x!=0)
	{
		if(tree[ddd*2].x==0 && tree[ddd*2+1].x==0)
			sum[tree[ddd].h]=sum[tree[ddd].h]+tree[ddd].x;
			fun(ddd*2);
			fun(ddd*2+1);
	}
}

int main()
{
    n=0;
    while(cin>>x)
    {
        n++;
        a[n]=x;
    }
    m=0,n=0;
    memset(book,0,sizeof(book));
    memset(sum,0,sizeof(sum));
    create(1,0);
    fun(1);
    for(i=1;i<=8;i++)
    {
        if(sum[i]>=mmax && sum[i]!=0)
        { 
            res=i;
            mmax=sum[i];
        }
    }
    cout<<res;
    return 0;
}
