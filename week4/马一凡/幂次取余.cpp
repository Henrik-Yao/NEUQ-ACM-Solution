#include<iostream>
using namespace std;

long long getmod(long long a, long long b, long long c){
	long long x,y,z;
	if(b==1) return a%c;
	else{
		x = getmod(a,b/2,c);
		y = getmod(a,b-b/2,c);
		z = (x*y)%c;
		return z;
	} 
	
}

int main(){
	int n;
	cin >> n;
	for(int i=0; i<n; i++){
		long long a,b,c;
		cin >> a >> b >> c;
		long long z;
		z = getmod(a,b,c);
		cout << z << endl;
	}
	return 0;
	
}
