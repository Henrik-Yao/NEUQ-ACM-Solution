#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int a[maxn];
int link(int n, int m);
int find(int n, int m);
int main(){
    int n;
cin>>n;
for(int i=0;i<n;i++)
  {
   cin>>a[i];
  }

	int k = 0, t = 1; 
	while(k+a[k] < n-1)
	{
        int p = a[k]; 
		int m = find(k,a[k]+k);
		k = link(m,p+k);
		t++;
	}
	cout << t << endl;
}
int link(int n, int m){
	int ans = n;
	for(int i = ans; i <= m; i ++){
		if(a[n] < a[i]+(i-n)){
			n = i;
		}
	}
	return n;
}
int find(int n, int m){
	int ans = n+1;
	for(int i = n; i <= m; i ++){
		if(a[n] < a[i]){
			a[n] = a[i];
			ans = i;
		}
	}
	return ans;
}
