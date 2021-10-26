#include <bits/stdc++.h>
using namespace std;

int N;
char Nam[5][10005];

inline int Els(int x,int y) {
	if (x>y) swap(x,y);
	if (x==1&&y==2) return 3;
	if (x==1&&y==3) return 2;
	return 1;
}

void dfs(int x,int y,int Sum) {
	if (Sum>1) dfs(x,Els(x,y),Sum-1);
	printf("%s->%s\n",Nam[x],Nam[y]);
	if (Sum>1) dfs(Els(x,y),y,Sum-1);
}

int main() {
	cin>>N;
	for (int i=1; i<=3; ++i) cin>>Nam[i];
//	for (int i=1; i<=3; ++i) cout<<Nam[i]<<endl;
	dfs(1,3,N);
	return 0;
}
