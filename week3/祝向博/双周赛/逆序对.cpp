#include <bits/stdc++.h>
#define int long long
using namespace std;

const int maxn=1000005;
int N,Ans,a[maxn],b[maxn];

inline int read() {
	int ret=0,f=1;
	char ch=getchar();
	for (; !isdigit(ch); ch=getchar()) if (ch=='-') f=-f;
	for (; isdigit(ch); ch=getchar()) ret=ret*10+ch-48;
	return ret*f;
}

void msort(int L,int R) {
    if (L>=R) return ;
    int mid=L+(R-L>>1);
    msort(L,mid),msort(mid+1,R);
    for (int i=L; i<=R; ++i) b[i]=a[i];
    for (int i=L,j=mid+1,k=L; k<=R; ++k) {
        if (i>mid||j<=R&&b[i]>b[j]) a[k]=b[j],Ans+=mid-i+1,++j;
        else a[k]=b[i],++i;
    }
}

signed main() {
    N=read();
    for (int i=1; i<=N; ++i) a[i]=read();
    msort(1,N);
    printf("%lld\n",Ans);
	return 0;
}
