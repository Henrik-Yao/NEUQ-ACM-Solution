#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n,x,Max=-1;
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>x,a[x]++,Max=max(Max,x);
	ll cnt=0;
	for (int i=1;i<Max;i++){
		if (a[i+1]!=0&&a[i]!=0) cnt+=a[i+1]*a[i];
	}
	cout<<cnt;
	return 0;
} 
