#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#define N 66
#define ll long long
using namespace std;

int ans,n,m;
int f[N],tree[10001],Top;
ll A[N];

struct s{
	int id,v;
	bool operator < (const s &r)const{return r.v < v;}
};

int head[10001],p;
struct ss{
	int to,ls;
}q[10001];
void add(int a,int b){q[ ++p] = (ss){b , head[a]};head[a] = p;}

void dfs(int x , int c){
	if(head[x] == 0){
		ans += c * f[x];
		return;
	}
	for(int i = head[x];i;i = q[i].ls)
			dfs(q[i].to , c + 1);
}

int main(){
	scanf("%d",&n);Top = n;
	priority_queue<s>u;
	for(int i = 1;i <= n;i ++){
		char ch;
		cin >> ch >> f[i];
		u.push((s){i , f[i]});
	}
	while(1){
		s x = u.top();u.pop();
		s y = u.top();u.pop();
		if(x.id == y.id) break;
		Top ++;
		add(Top , x.id);add(Top , y.id);
		u.push((s){Top , x.v + y.v});
	}
	dfs(Top , 0);
	scanf("%d",&m);
	while(m --){
		char ch;string a;int flag = 0,tot = 0;
		memset(tree,0,sizeof(tree));
		for(int i = 1;i <= n;i ++){
			cin >> ch >> a;
			int len = a.size();
			ll x = 1;
			tot += len * f[i];
			for(int j = 0;j < len;j ++){
				if(a[j] == '0') x *= 2;
				else x = x * 2 + 1;
			}
			A[i] = x;
		}
		for(int i = 1;i <= n;i ++)
			for(int j = 1;j <= n && j != i;j ++)
				if(A[i] == A[j]){
					flag = 1;
					break;
				}
		if(flag == 0)
	 		for(int i = 1;i <= n;i ++){
				ll x = A[i];
				while(x > 1){
					x /= 2;
					for(int j = 1;j <= n;j ++)
						if(x == A[j] && i != j){
							flag = 1;
							break;
						}
					if(flag == 1) break;
				}
				if(flag == 1) break;
			}
		if(tot != ans) flag = 1;
		if(flag) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
