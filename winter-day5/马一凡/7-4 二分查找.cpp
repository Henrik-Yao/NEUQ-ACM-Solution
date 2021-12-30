#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

int n,m; 


int search(int head, int end, int x, int a[]){
	int mid = head+end >> 1;
	if(a[mid]== x){
		return mid;
	}
	if(mid == 0 || mid == n-1) return -1;
	if(head == end) return -1;
	if(x<a[head] || x>a[end]) return -1;
	
	else if(x < a[mid]){
		return search(head, mid-1,x,a); 
	} 
	else return search(mid+1, end,x,a);
}

int main(){
	while(~scanf("%d",&n)){
	int a[10000]={0};
	int x;
	
	for(int i=0; i<n; i++){
		scanf("%d",a+i);
	}
	sort(a,a+n);
	int flag = 0;
	for(int i=0; i<n; i++){
		if(flag == 1) cout << " ";
		cout << a[i];
		flag = 1;
	} 
	cout << endl;
	scanf("%d",&m);
	flag = 0;
	for(int i=0; i<m; i++){
		cin >> x;
		int head,mid,end;
		head = 0;
		end = n-1;
		mid = search(head,end,x,a);
		if(flag == 1) cout << " ";
		printf("%d",mid+1);
		flag = 1;
	}
	cout << endl;
}
	return 0;
}
