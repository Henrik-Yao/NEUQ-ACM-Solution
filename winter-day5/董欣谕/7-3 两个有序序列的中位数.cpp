#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n;
int a[200001],num[200001],ans[200001];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=2*n;i++)
		cin>>a[i];
	sort(a+1,a+1+2*n);
	for(int i=1;i<=2*n;i++)
		num[i]=a[i];
	int len=unique(a+1,a+1+2*n)-a-1;
	for (int i=1;i<=2*n;i++)
		num[i]=lower_bound(a+1,a+1+2*n,num[i])-a;
	for (int i=1;i<=2*n;i++)
		num[i]=a[num[i]];
	cout<<num[(2*n+1)/2];
	return 0;
} 
