#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int main(){
	long long d,n;
	double result,m,R;
	cin>>R>>d>>n;
	d=fabs(d);
	n=fabs(n);
	m=d*d+(n-R)*(n-R);
	result=sqrt(m)*2.0-R;
	if (n>=R)printf("%.2lf",result);
	else printf("%.2lf",2*d-R);
	
	
	return 0;
}
