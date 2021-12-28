#include<bits/stdc++.h>
using namespace std;
const int k = 1e4 + 10;
int fa[k]; 
struct t{
  int x,y,val;
};
t a[k];

int find(int x)
{
  if(x!=fa[x])  fa[x]=find(fa[x]);
  return fa[x];
}
bool cmp(t a,t b){
  return a.val<b.val;
}

int main()
{
  int max_ = INT_MIN; 
  int n,m;
  cin>>n>>m;
  for(int i=1;i<=n;i++){
      fa[i] = i;
  }
  for(int i=1;i<=m;i++)
  {
  	cin>>a[i].x>>a[i].y>>a[i].val;
  }
  int k=0;
  sort(a+1,a+1+m,cmp);
  for(int i=1;i<=m;i++)
  {
  	if(find(a[i].x)!=find(a[i].y))
  	{
  	    max_=a[i].val;
  		int tx=find(a[i].x);
  		int ty=find(a[i].y);
  		if(tx!=ty) fa[tx]=ty;
  		k++;
  		if(k==n-1)    break;
  	}
  }
  cout<<n-1<<" "<<max_<<endl;
}
