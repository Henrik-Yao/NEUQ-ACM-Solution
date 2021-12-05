```c++
#include<bits/stdc++.h>
const int MAX = 1e6+10;
using namespace std;
int a[MAX];
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
int link(int n, int m){
	int ans = n;
	for(int i = ans; i <= m; i ++){
		if(a[n] < a[i]+(i-n)){
			n = i;
		}
	}
	return n;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	int j = 0, t = 1; 
	while(j+a[j] < n-1){
        int p = a[j]; 
		int m = find(j,a[j]+j); 
		j = link(m,p+j); 
		t ++;
	}
	cout << t << endl;
}

```

