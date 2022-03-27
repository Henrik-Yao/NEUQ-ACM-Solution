#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
int a[100001],dif[100001];
int n,m;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for (int i=1;i<n;i++)
		dif[i]=a[i+1]-a[i];
	sort(dif+1,dif+n);
	int sum=0;
	for (int i=1;i<=n-m;i++)
		sum+=dif[i];
	sum+=m;
	cout<<sum;
	return 0;
} 
