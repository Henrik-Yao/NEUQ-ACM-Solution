#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n;
int a[101];
int binary_search(int x){
	int l=1,r=n;
	while (l<=r){
		int mid=(l+r)>>1;
		if (a[mid]==x) return mid;
		else if (a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	return 0;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	while (cin>>n){
		for (int i=1;i<=n;i++)
			cin>>a[i];
		sort(a+1,a+1+n);
		for (int i=1;i<=n;i++)	
			if (i!=n) cout<<a[i]<<" ";
			else cout<<a[i]<<endl;
		int m;
		cin>>m;
		while (m--){
			int x;
			cin>>x;
			if (m) cout<<binary_search(x)<<" ";
			else cout<<binary_search(x)<<endl;
		}
	}
	
	return 0;
} 
