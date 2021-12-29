#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,m;
int x[100001];
bool check(int s){
	int last=-INF,cnt=0;
	for (int i=1;i<=n;i++){
		if (x[i]-last>=s) last=x[i],cnt++;
	}
	if (cnt>=m) return 1;
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>x[i];
	sort(x+1,x+1+n);
	int l=0,r=a[n]+1,ans;
	while (l<=r){
		int mid=(l+r)>>1;
		if (check(mid)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
	return 0;
} 
