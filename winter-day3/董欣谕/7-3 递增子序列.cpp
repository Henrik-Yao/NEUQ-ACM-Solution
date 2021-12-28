#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n;
int a[20];
map<string,int>mp;
void dfs(int pos,string tot,int geshu,int last){
    if (geshu>=2) {
		mp[tot]=1;
	}
    if(geshu>=n) return;
	for (int i=pos;i<=n;i++){
		if (a[i]>=last){
			string temp;
			stringstream ss;
			ss<<a[i];
			ss>>temp;
			dfs(i+1,tot+','+temp,geshu+1,a[i]);
		}
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	dfs(1,"",0,-INF);
	cout<<mp.size();
	return 0;
} 
