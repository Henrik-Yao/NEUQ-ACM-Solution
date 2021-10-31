#include<iostream>
using namespace std;

int F(int n,int *a){
	int sum = 0, max = 0,i=0;
	for(i=0; i<n; i++){
			if(sum+a[i] > a[i]) sum = sum + a[i];
			else sum = a[i];
			if(sum > max){
				max = sum;
		}
		
	}
	return max;
}


int main(){
	int n,i,flag=0 ;
	cin >> n;
	int a[10100];
	for(i=0; i<n; i++){
		cin >> a[i];
		if(a[i]>0) flag = 1;
	}
	int sum;
	sum	= F(n,a);
	if(flag == 0) sum = 0;
	cout << sum << endl;
	
	
	
	return 0;
}
