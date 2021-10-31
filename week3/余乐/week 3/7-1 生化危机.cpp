#include <cstdio>
using namespace std;
struct ss{
	int to,ls;
}q[201];
int m,n,k,s,d,p=0,sa[101],head[101],v[101];
int y(int a){
	v[a]=1;
	if(a==d) return 1;
	for(int i=head[a];i;i=q[i].ls){
		int t=q[i].to;
		if(!sa[t]||v[t]) continue;
		if(y(t)) return 1;
	}
	return 0;
}
void add(int a,int b){q[++p]=(ss){b,head[a]};head[a]=p;}
int main(){
	scanf("%d%d%d",&m,&n,&k);
	for(int i=1;i<=n;i++){
		int a;scanf("%d",&a);
		sa[a]=1;
	}
	for(int i=1;i<=k;i++){
		int a,b;scanf("%d%d",&a,&b);
		add(a,b);add(b,a);
	}
	scanf("%d%d",&s,&d);
	if(!sa[d]) printf("The city %d is not safe!",d);
	else {
		if(y(s)) printf("The city %d can arrive safely!",d);
		else printf("The city %d can not arrive safely!",d);
	}
	return 0;
}
