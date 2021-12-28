#include <queue> 
#include <cstdio>
#define N 20001
using namespace std;

int n,m;

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
	for(int i = 1;i <= m;i ++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		add(a , b , c);
	}
	for(int i = 0;i < n;i ++)
		if(head[i] != 0)
			print(i);
	return 0;
}
