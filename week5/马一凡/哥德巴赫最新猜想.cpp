#include<iostream>
#include<cmath>
using namespace std;

long long a[10010]={0};


int flag(long long n){
    long long bb = sqrt(n)+1;
    for(long long i=2; i<=bb; i++){
		if(n%i == 0) return 0;
		}
	
    return 1;
}

int main(){
	long long max = 0;
	int n;
	cin >> n;
	for(int i=1; i<=n; i++){
		int sum;
		long long k;
		cin >> k;
		if(flag(k) == 1) sum =1;
		else if(k%2 == 0){
			sum = 2;
		}
		else if(flag((k-2)) == 1){
			sum = 2;
		}
		else sum = 3;
		cout << sum << endl;
	}
	
	
	return 0;
} 
