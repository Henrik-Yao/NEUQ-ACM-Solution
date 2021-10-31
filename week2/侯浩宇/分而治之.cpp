#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int num[N]= {0},temp[N];
int main() {
	int n,m,k,goal,cdn;
	cin>>n>>m;
	vector<vector<int> >cp;
	int a,b;
	cp.resize(n + 1);
	while(m--) {
		cin>>a>>b;
		cp[a].push_back(b);
		cp[b].push_back(a);
		num[a]++;
		num[b]++;
	}
	cin>>k;
	while(k--) {
		int v=n;
		while(v--){
			temp[v+1]=num[v+1];
            
		}
		cin>>cdn;
		while(cdn--) {
			cin>>goal;
			temp[goal]=0;
			for(int i=0; i<cp[goal].size(); i++) {

				temp[cp[goal][i]]--;
			}
		}
		int flag=1;
		for(int i=1; i<=n; i++) {
			if(temp[i]>0)flag=0;
		}
		if(flag==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
