#include<bits/stdc++.h>
using namespace std;
int n,lens,lens1,flag,cnt,r,d;
double sum;
string s,s1;
int main(){
	cin>>r>>d>>n;
	d=abs(d);
	n=abs(n);
	if(r>=n){
		sum=(2*d)-r;
		if(sum<0)sum=0;
		printf("%.2lf",sum);
	}
	else{
		sum=sqrt((d*d)+((n-r)*(n-r)));
		sum*=2;
		sum-=r;
		if(sum<0)sum=0;
		printf("%.2lf",sum);
	}
	return 0;
}
