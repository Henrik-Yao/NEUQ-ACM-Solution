#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int fa[1001],n,m,q;
int find(int x){
	if (x==fa[x]) return x;
	return fa[x]=find(fa[x]);
}
void merge(int x,int y){
	int xx=find(x);
	int yy=find(y);
	fa[xx]=yy;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m>>q;
	for (int i=1;i<=n;i++)
		fa[i]=i;
	for (int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		merge(a,b);
	}
	for (int i=1;i<=q;i++){
		int a,b;
		cin>>a>>b;
		if (find(a)==find(b)) cout<<"In the same gang."<<endl;		
		else cout<<"In different gangs."<<endl;
	}
    int cnt=0;
    for (int i=1;i<=n;i++)
    	if (fa[i]==i) cnt++;
    cout<<cnt;
	return 0;
} 