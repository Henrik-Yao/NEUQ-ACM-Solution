#include<bits/stdc++.h>
using namespace std;
int main(){
	int m,n;
	cin>>n>>m;
	int l = 1, r = n;
	int mid,a[1000001];
	for(int i = 1; i <= n; i++){
		cin>>a[i];
	}
	if(m>a[n])
	cout<<n+1;
	
	else{
		
		while(l<r){
			mid = (l+r)/2;
			if(m>a[mid])
				l = mid+1;
			
			else
			r = mid;
		}
	
	cout<<r;
}
}

