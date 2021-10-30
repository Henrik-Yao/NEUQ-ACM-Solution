#include<iostream>
#include<cmath>
using namespace std;

int main(){
	float R,d,n;
	float dis,dis1,dis2;
	cin >> R >> d >> n;
	if(d<0) d = -d;
	if(n<0) n = -n;
	if(R<n){
		dis1 = sqrt(d*d+(n-R)*(n-R));
		dis2 = dis1-R;
	}
	else{
		dis1 = d;
		dis2 = d-R;
	}
	dis = dis1+dis2;
	printf("%.2f",dis);
	
	return 0;
} 
