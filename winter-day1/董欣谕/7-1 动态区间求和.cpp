#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
template<typename T,int N> struct bit
{
	T a[N],s[N];
	int n;
	bit()
	{
		memset(s,0,sizeof s);
		memset(a,0,sizeof a);
	}
	void init(int nn)
	{
		n=nn;
		memset(a+1,0,n*sizeof a[0]);
		memset(s+1,0,n*sizeof a[0]);
	}
	void init(int nn,T *b)
	{
		n=nn;
		for (int i=1;i<=n;i++) s[i]=s[i-1]+b[i];
		for (int i=1;i<=n;i++) mdf(i,b[i]);
	}
	void mdf(int x,T y)
	{
		a[x]+=y;
		while ((x+=x&-x)<=n) a[x]+=y; 
	}
	T sum(int x)
	{
		T r=a[x];
		while (x^=x&-x) r+=a[x];
		return r;
	}
	T sum(int x,int y)
	{
		return sum(y)-sum(x-1);
	}
};
bit<ll,1000001>s;
ll num[1000001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,q,opt;
	cin>>n>>q;
	s.init(n);
	for (int i=1;i<=n;i++)
		cin>>num[i];
	s.init(n,num);
	while (q--){
		cin>>opt;
		if (opt==1){
			int x,pos;
			cin>>pos>>x;
			s.mdf(pos,x);
		}
		else {
			int l,r;
			cin>>l>>r;
			cout<<s.sum(l,r)<<endl;
		}
	}
	
	return 0;
} 
