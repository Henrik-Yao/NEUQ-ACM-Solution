#include<bits/stdc++.h>
using namespace std;
const int N = 333;
int n,c,fa[N],cnt,maxn;

struct edge{
	int s,e,w;
	bool operator < (const edge & a) const {
		return w>a.w;
	}
};
priority_queue<edge>h;

void init(){
	for(int i=1; i<=n; i++) fa[i] = i;
}

int find(int x){
	if(fa[x]==x) return x;
	else return fa[x] = find(fa[x]);
}

void merge(int a,int b){
	fa[find(a)] = find(b);
}

bool ask(int a,int b){
	return find(a)==find(b);
}

void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

int main(){
	read(n), read(c); 
	init();
	for(int i=1; i<=c; i++) {
		edge tmp;
		read(tmp.s), read(tmp.e), read(tmp.w);
		h.push(tmp);
	}
	while(!h.empty()) {
		int s = h.top().s;
		int e = h.top().e;
		int w = h.top().w;
		h.pop();
		if(!ask(s,e)) {
			cnt++;
			maxn = max(maxn,w);
			merge(s,e);
		}
	}
	printf("%d %d\n",cnt,maxn);
    return 0;
}

