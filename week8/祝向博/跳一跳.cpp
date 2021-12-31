#include <bits/stdc++.h>
using namespace std;

const int maxn=1e6+5;

int N,a[maxn];

inline int read() {
	int ret=0,f=1;char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

class Seg_Tree {
#define ls (o<<1)
#define rs (o<<1|1)
#define mid (L+(R-L>>1))
#define INF (0x3f3f3f3f)
public:
	Seg_Tree() {
		memset(a,0x3f,sizeof a);
	}
	inline void pushup(int o) {a[o]=min(a[ls],a[rs]);}
	void Modify(int o,int L,int R,int p,int x) {
		if (L>R) return;
		if (L==R) return (void)(a[o]=x);
		if (p<=mid) Modify(ls,L,mid,p,x);
		else Modify(rs,mid+1,R,p,x);
		pushup(o);
	}
	int Query(int o,int L,int R,int lef,int rig) {
		if (lef>rig) return INF;
		if (lef<=L&&R<=rig) return a[o];
		if (L>rig||lef>R) return INF;
		return min(Query(ls,L,mid,lef,rig),Query(rs,mid+1,R,lef,rig));
	}
private:
	int a[maxn<<2];
#undef INF
#undef ls
#undef rs
} T;

int main() {
	N=read();
	for (int i=1; i<=N; ++i) a[i]=read();
	T.Modify(1,1,N,N,0);
	for (int i=N-1; i; --i) {
		int x=T.Query(1,1,N,i+1,i+a[i]);
		T.Modify(1,1,N,i,x+1);
	}
	printf("%d\n",T.Query(1,1,N,1,1));
	return 0;
}
