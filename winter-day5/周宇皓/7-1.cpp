#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
int a[N];
int main(){
	int m = 0,n;
	cin>>n;
	for(int i = 0;i < n; i++)
	cin >> a[i];
	sort(a,a+n);
	for(int i = 0; i < n; i++){
		if(a[i] + 1 == a[i+1])
		m++;
	}
	cout<<m;
}
