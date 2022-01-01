#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,a[10001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>n){
		for (int i=1;i<=n;i++){
			cin>>a[i];
		}
		for (int i=2;i<=n;i++){
			for (int j=1;j<=i;j++)
				if (a[i]<a[j]) swap(a[i],a[j]);
			for (int j=1;j<=n;j++){
				if (j!=n) cout<<a[j]<<" ";
				else cout<<a[j];
			}
			if (i!=n) cout<<endl;
		}
	}	
	
	return 0;
} 
