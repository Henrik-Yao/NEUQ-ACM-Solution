#include<iostream>
using namespace std;

int n,number,quan=1,i;
int a[1000100]={0},b[1000100]={0},q[1000100]={0},h[1000100]={0},shu[1000100]={0};

int main(){
	
	scanf("%d",&n);
	scanf("%d",&number);
	shu[1] = number;
	q[1] = 1;
	a[number] = 1;
	for(i=2; i<=n; i++){
		scanf("%d",&number);
		shu[i] = number;
		if(a[number]==0) q[i]=q[i-1]+1;
		else q[i] = q[i-1];
		a[number]++;
	}
	b[shu[n]] = 1;
	h[n] = 1;
	for(i=n-1; i>=1; i--){
		number = shu[i];
		if(b[number]==0) h[i]=h[i+1]+1;
		else h[i] = h[i+1];
		b[number]++;
	}
	for(i=1; i<n; i++){
		if(q[i]+h[i+1]>quan)
		quan = q[i]+h[i+1];
	}
	cout << quan;
	
	
	return 0;
} 
