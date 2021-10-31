#include<bits/stdc++.h>
using namespace std;

int a[100001] ;
int b[100001] ;

void msort(int l, int r){
	if(l == r) return;
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid+1, r);
	//ºÏ²¢ 
	int left = l, right = mid+1;
	int node = l;
	while(left <= mid && right <= r){
		if(a[left] <= a[right]){
			b[node++] = a[left++];
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
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	//ÅÅÐò
	msort(0, n-1) ;
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}

}
