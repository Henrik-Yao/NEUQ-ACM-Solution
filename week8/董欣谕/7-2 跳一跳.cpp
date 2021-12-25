#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
int a[1000001],n,vis[1000001],ans[1000001];
queue<int>q;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	q.push(0);
	vis[0]=1;
	ans[0]=0;
	int res,maxdis=-1;
	while (!q.empty()){
		int cur=q.front();
		q.pop();
		if (cur+a[cur]>=n-1) {
			res=ans[cur]+1;
			break;
		}
		if (a[cur]+cur<=maxdis) continue;
		maxdis=max(a[cur]+cur,maxdis);
		for (int i=cur+1;i<=cur+a[cur];i++){
			if (vis[i]) continue;
			vis[i]=1;
			q.push(i);
			ans[i]=ans[cur]+1;
		}
	}
	cout<<res;
	return 0;
} 
