#include <cstdio>
#include <cstring>
#define N 100000
using namespace std;
int n,k,xb[N],head[N],A[N],P=0;
struct ss{
	int to,ls;
}q[N*2];
void add(int a,int b){q[++P]=(ss){b,head[a]};head[a]=P;}
void finda(int p,int c){
	if(c==6) return;
	A[p]=1;
	for(int i=head[p];i;i=q[i].ls){
		int T=q[i].to;
		finda(T,c+1);
	}
}
int findb(int p,int c){
	if(c==6) return 0;
	if(A[p]) return 1;
	for(int i=head[p];i;i=q[i].ls){
		int T=q[i].to;
		if(findb(T,c+1)) return 1;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int a,b,c;char x;
		scanf("%d %c%d%d",&a,&x,&b,&c);
		if(b>0) {
			add(a,b);xb[b]=1;
		}
		if(c>0) add(a,c);
		if(x=='M') xb[a]=1;
	}
	scanf("%d",&k);
	for(int i=1;i<=k;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(xb[a]==xb[b])
			printf("Never Mind");
		else{
			memset(A,0,sizeof(A));
			finda(a,1);
			if(findb(b,1)) printf("No");
			else printf("Yes");
		}
		if(i<k) printf("\n");
	}
	return 0;
}
