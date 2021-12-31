#include <iostream>
using namespace std;
unsigned long long a[36];
unsigned long long Hanoi(int n){
	if(a[n]!=0) return a[n];
    if(n==1) return 2;
    else{
        return Hanoi(n-1)+1+Hanoi(n-1)+1+Hanoi(n-1);
    }
}
int main(){
    int n;
    for(int i=0;i<=35;i++) a[i]=Hanoi(i);
    while(cin >> n) {
    	cout << a[n] << endl;
	}
    return 0;
}
