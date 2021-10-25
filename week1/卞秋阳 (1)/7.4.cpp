#include<iostream>
using namespace std;
int a[1005];
int f(int n){
	int sum=0;
	if(n==1) return 1;
	else if(a[n]==-517){
		for(int i=1;i<=n/2;i++){
			if(n%i==0) sum=sum+f(i);
		}
		a[n]=sum+1;
		return a[n];
	}
	else return a[n];
	
}


int main()
{int n; 
cin>>n;
for(int i=1;i<=n+1;i++){
	a[i]=-517;
}
cout<<f(n);
	
} 
