#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[100001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[x]++;
	}
	for (int i=0;i<=100000;i++){
		if (a[i]!=0) cout<<i<<":"<<a[i]<<endl;
	}
	return 0;
} 
