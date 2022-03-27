#include <cstdio>
#include <cstring>
using namespace std;
int t,ansce,Flag;
char hg[31],zg[31],tree[301];
int p1[301],p2[301],T[301];
void build(int l , int r , char fa , int id , int flag , int ce){
	if(l > r) return;
	if(ce > ansce) ansce = ce;
	int maxn = -1,po;
	for(int i = l;i <= r;i ++)
		if(p1[zg[i]] > maxn){
			maxn = p1[zg[i]];
			po = i;
		}
	tree[id * 2 + flag] = zg[po];
	if(po - 1 - l >= 0 && r - po - 1 >= 0){
		for(int i = l;i <= po - 1;i ++)
			for(int j = po + 1;j <= r;j ++)
				if(p1[zg[i]] > p1[zg[j]]){
					Flag = 1;
					return;
				}
	}
	build(l , po - 1 , zg[po] , id * 2 + flag , 0 , ce + 1);
	build(po + 1 , r , zg[po] , id * 2 + flag , 1 , ce + 1);
}
void print(int p){
	int ls = p << 1,rs = (p << 1) | 1;
	printf("%c",tree[p]);
	if(tree[ls]) print(ls);
	if(tree[rs]) print(rs);
}
int main(){
	while(~scanf("%s%s",hg,zg)){
		ansce = 0;Flag = 0;
		int len = strlen(hg);
		for(int i = 0;i < len;i ++)
			p1[hg[i]] = p2[zg[i]] = i;
		tree[1] = hg[len - 1];
		build(0 , p2[tree[1]] - 1 , tree[1] , 1 , 0 , 1);
		build(p2[tree[1]] + 1 , len - 1 , tree[1] , 1 , 1 , 1);
		if(p2[tree[1]] - 1 >= 0 && len - p2[tree[1]] - 2 >= 0){
		for(int i = 0;i <= p2[tree[1]] - 1;i ++)
			for(int j = p2[tree[1]] + 1;j <= len - 1;j ++)
				if(p1[zg[i]] > p1[zg[j]]){
					Flag = 1;
					break;
				}
		}
		if(Flag == 0){
			printf("%d\n",ansce);
			print(1);
			printf("\n");
		}
		else printf("INVALID\n");
	}
	return 0;
}
