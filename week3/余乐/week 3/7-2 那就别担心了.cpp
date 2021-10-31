#include <cstdio>
#define N 501
using namespace std;
int n,m,pd=0,p=0,ans=0,A,B,head[N],tot[N],v[N];
struct ss{
	int to,ls;
}q[N*N];
void add(int a,int b){q[++p]=(ss){b,head[a]};head[a]=p;}
int y(int a){
	if(!head[a]&&a!=B) {
		pd=1;v[a]=1;return 0;
	}
	if(v[a]) return tot[a];
	v[a]=1;
	if(a==B) {
		tot[a]=1;
		return 1;
	}
	for(int i=head[a];i;i=q[i].ls){
		int t=q[i].to;
		tot[a]+=y(t);
	}
	return tot[a];
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);
	}
	scanf("%d%d",&A,&B);
	ans=y(A);
	if(pd) printf("%d No\n",ans);
	else printf("%d Yes\n",ans);
	return 0;
}
