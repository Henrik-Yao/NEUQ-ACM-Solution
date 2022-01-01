#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<int,int>
const int mod=1e9+7;
const int INF=0x3f3f3f3f;
int n,a[10001];
void quicksort(int a[],int l,int r){
	if (l>=r) return;
	int templ=l,tempr=r;
	int temp=a[l];
	while (templ<tempr){
		while (templ<tempr&&a[tempr]>temp) tempr--;
		while (templ<tempr&&a[templ]<=temp) templ++;
		if (templ<tempr) swap(a[templ],a[tempr]);
	}
	swap(a[templ],a[l]);
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	quicksort(a,l,templ-1);
	quicksort(a,templ+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	quicksort(a,1,n);
	for (int i=1;i<=n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
} 
