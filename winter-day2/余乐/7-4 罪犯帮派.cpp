#include <cstdio>
#define N 1001
using namespace std;
int n,m,q,ans;
int fa[N],v[N];
int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void build(int a,int b){
	int A = find(a),B = find(b);
	if(A == B) return;
	fa[A] = B;
}
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i = 1;i <= n;i ++)
		fa[i] = i;
	for(int i = 1;i <= m;i ++){
		int a,b;
		scanf("%d%d",&a,&b);
		build(a , b);
	}
	for(int i = 1;i <= q;i ++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(find(a) == find(b))
			printf("In the same gang.\n");
		else printf("In different gangs.\n");
	} 
	for(int i = 1;i <= n;i ++){
		int F = find(i);
		if(v[F] == 0){
			ans ++;
			v[F] = 1;
		}
	}
	printf("%d\n",ans);
	return 0;
}
