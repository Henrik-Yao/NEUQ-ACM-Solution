#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int vis[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,m,k,now=1,flag=1;
	cin>>n>>m>>k;
	for (int i=0;i<n;i++){
		if (flag==1){
			int cnt=1;
			while (cnt<m){
				now--;
				if (now<=0) now=n;
				if (vis[now]) continue;
				cnt++; 
			}
			vis[now]=1;
			cout<<now<<" ";
		}
		else {
			int cnt=1;
			while (cnt<k){
				now++;
				if (now>n) now=1;
				if (vis[now]) continue;
				cnt++;
			}
			vis[now]=1;
			cout<<now<<" ";	
		}
		flag=-flag;
	}
	return 0;
} 
