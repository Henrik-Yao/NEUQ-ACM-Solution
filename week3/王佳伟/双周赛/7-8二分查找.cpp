#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000005] ;

void find(int a[], int val){
	int l,r;
	l = 0, r = n-1;
	while(l <= r){
		int mid = (l+r)/2;
		if(a[mid] >= val){
			r = mid - 1;
		}
		else{
			l = mid+1;
		}
	}
	cout << l+1 << endl;
}

int main() {
	int val;
	cin >> n;
	cin >> val;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	find(a, val);
}
