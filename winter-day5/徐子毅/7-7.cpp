#include<iostream>
#include<algorithm>
using namespace std;
long long a[100005];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> a[i];
	sort(a, a+n);
	int left=0,right= a[n-1]-a[0];
	while(left < right){
		long long middle = (left+right)/2, living_cows = 0;
		for(int i=0; i<n; i++){
			int t = i;
			while(a[i+1]-a[t]< middle && i < n)  i++;
			living_cows++;
		}
		if(living_cows >= m) left = middle + 1;
		else if(living_cows < m) right = middle;
	}
	cout << left-1 << endl;
	return 0;	
}