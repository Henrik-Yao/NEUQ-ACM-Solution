#include<bits/stdc++.h>
using namespace std;

int n;
int a[1000005];
int b[1000005];
long long res = 0;

void msort(int l, int r){
	if(l == r) return;
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid+1, r);
	//ºÏ²¢ 
	int left = l, right = mid+1;
	int node = l;
	while(left <= mid && right <= r){
		if(a[left] > a[right]){
			b[node++] = a[left++];
			res = res + r - right +1;
		}
		else{
			b[node++] = a[right++];
		}
	}
	while(left <= mid){
		b[node++] = a[left++];
	}
	while(right <= r){
		b[node++] = a[right++];
	}
	for(int i = l; i < node; i++){
		a[i] = b[i];
	}
}


int main() {
	cin >> n;
	for(int i= 0; i < n; i++){
		scanf("%d", &a[i]);
	} 
	msort(0, n-1);
	cout << res;

}
