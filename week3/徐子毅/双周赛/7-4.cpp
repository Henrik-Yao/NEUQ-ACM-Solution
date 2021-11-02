#include <iostream>
#include <cmath>
using namespace std;
int Hanoi(int n){
	return pow(2,n)-1;
}
int main(){
	int N;
	int Hanoi121[65]={0,1,3,5};
	int mi=999999;
	for(int i=3;i<=64;i++){
		mi=999999;
		for(int r=1;r<i;r++)
			if(2*Hanoi121[r]+pow(2,i-r)-1<mi)
				mi=2*Hanoi121[r]+pow(2,i-r)-1;
		Hanoi121[i]=mi;
	}
	while(cin >> N) cout << Hanoi121[N] << endl;
	return 0;
}
