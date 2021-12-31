#include <map>
#include <cstdio>
using namespace std;

int n;
int hg[11],zg[11];
char tree[201];
map<int,int> p1,p2;
int top,stack[11];

void build(int l , int r , int fid , int flag){
	if(l > r) return;
	int minn = n + 1,po;
	for(int i = l;i <= r;i ++)
		if(p1[zg[i]] < minn){
			minn = p1[zg[i]];
			po = i;
		}
	tree[2 * fid + flag] = zg[po];
	build(l , po - 1 , 2 * fid + flag , 0);
	build(po + 1 , r , 2 * fid + flag , 1);
}

void print(int x){
	int ls = x << 1,rs = (x << 1) | 1;
	stack[++ top] = tree[x];
	if(tree[rs]) print(rs);
	if(tree[ls]) print(ls);
}

int main(){
	scanf("%d",&n);
	for(int i = 1;i <= n;i ++){
		scanf("%d",&hg[i]);
		p1[hg[i]] = i;
	}
	for(int i = 1;i <= n;i ++){
		scanf("%d",&zg[i]);
		p2[zg[i]] = i;
	}
	tree[1] = hg[1];
	build(1 , p2[hg[1]] - 1 , 1 , 0);
	build(p2[hg[1]] + 1 , n , 1 , 1);
	print(1);
	for(int i = top;i >= 1;i --)
		printf("%d ",stack[i]);
	return 0;
}
