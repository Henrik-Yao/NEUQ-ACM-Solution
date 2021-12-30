#include <queue> 
#include <cstdio>
#define N 20001
#define E 1001
using namespace std;

int n,m,k,a[E],b[E],c[E],u[E];

int head[N],p;
struct ss{
	int to,v,ls;
	bool operator < (const ss &r)const{return r.to < to;}
}q[N];
void add(int a , int b , int c){q[++ p] = (ss){b , c , head[a]};head[a] = p;}

void print(int x){
	printf("%d:",x);
	priority_queue<ss>que;
	for(int i = head[x];i;i = q[i].ls)
		que.push(q[i]);
	while(!que.empty()){
		ss t = que.top();
		printf("(%d,%d,%d)",x,t.to,t.v);
		que.pop();
	}
	printf("\n");
}

int main(){
	scanf("%d%d",&n,&m);
	for(int i = 1;i <= m;i ++)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	scanf("%d",&k);
	for(int i = 1;i <= k;i ++){
		int x,y;
		scanf("%d%d",&x,&y);
		for(int j = 1;j <= m;j ++)
			if(x == a[j] && y == b[j]){
				u[j] = 1;
				break;
			}
	}
	for(int i = 1;i <= m;i ++)
		if(u[i] == 0)
			add(a[i] , b[i] , c[i]);
	for(int i = 0;i < n;i ++)
		if(head[i] != 0)
			print(i);
	return 0;
}
