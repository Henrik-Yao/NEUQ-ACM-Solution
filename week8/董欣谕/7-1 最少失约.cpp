#include <bits/stdc++.h>
using namespace std;
#define pair <int,int> pii
const int mod=1e9+7;
const int INF=0x3f3f3f3f; 
typedef long long ll;
struct node{
	int l;
	int r;
}a[100001];
int n;
bool cmp(node a,node b){
	if (a.r!=b.r) return a.r<b.r;
	else return a.l<b.l;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int t;
	cin>>t;
	while (t--){
		cin>>n;
		for (int i=1;i<=n;i++)
			cin>>a[i].l>>a[i].r;
		sort(a+1,a+1+n,cmp);
		int cnt=0,now=0;
		for (int i=1;i<=n;i++)
			if (a[i].l>=now) now=a[i].r;
			else cnt++;
		cout<<cnt<<endl;
	}
	return 0;
} 
