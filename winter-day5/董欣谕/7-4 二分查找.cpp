#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int a[1001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int n;
	cin>>n;
	for (int i=0;i<n;i++)
		cin>>a[i];
	int x;
	cin>>x;
	int l=0,r=n-1,pos=n,cnt=0;
	while (l<=r){
		cnt++;
		int mid=(l+r)>>1;
		if (a[mid]==x){
			pos=mid;
			break;
		}
		else if (a[mid]>x) r=mid-1;
		else l=mid+1;
	}
	if (pos!=n) {
		cout<<pos<<endl<<cnt;
	}
	else cout<<-1<<endl<<cnt;
	return 0;
} 
