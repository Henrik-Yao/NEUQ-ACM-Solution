#include <cstdio>
#define N 20001
using namespace std;
int n,e,p=0,head[N],u[N];
struct ss{
	int to,ls;
}q[51];
void add(int a,int b){q[++p]=(ss){b,head[a]};head[a]=p;}
void dfs(int p){
	u[p]=1;
	printf("%d ",p);
	int minn=N;
	for(int i=head[p];i;i=q[i].ls){
		int T=q[i].to;
		if(minn>T&&!u[T]) minn=T;
	}
	if(minn!=N) dfs(minn);
}
int main(){
	scanf("%d%d",&n,&e);
	for(int i=1;i<=e;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		add(a,b);
	}
	for(int i=0;i<n;i++)
		if(!u[i])
			dfs(i);
	return 0;
}
