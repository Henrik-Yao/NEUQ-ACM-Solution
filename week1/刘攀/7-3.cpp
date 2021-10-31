#include<bits/stdc++.h>
using namespace std;
int main(){
	double d,n;
	double r;
	double s=0;
	cin>>r>>d>>n;
	if(abs(n)<=r)  s=2*abs(d)-r;
	else s=sqrt(d*d+(abs(n)-r)*(abs(n)-r))*2-r;
	cout<<fixed;
	cout<<setprecision(2);
	cout<<s;
} 
