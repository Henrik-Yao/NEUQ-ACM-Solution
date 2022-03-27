#include <cstdio>
#include <cstring>
using namespace std;

int n,T,maxn;
int tree[1001];
int stack[1001],top;

void print(int x , int ce){
	int ls = x << 1,rs = (x << 1) | 1;
	if(ce > maxn) maxn = ce;
	if(tree[ls]) print(ls , ce + 1);
	stack[++ top] = tree[x];
	if(tree[rs]) print(rs , ce + 1);
}
int main(){
	scanf("%d",&T);
	while(T --){
		maxn = top = 0;
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		for(int i = 1;i <= n;i ++) scanf("%d",&tree[i]);
		print(1 , 1);
		for(int i = 1;i <= top;i ++){
			printf("%d",stack[i]);
			if(i < top) printf(" ");
		}
		printf("\n%d\n",maxn);
	}
	return 0;
} 
