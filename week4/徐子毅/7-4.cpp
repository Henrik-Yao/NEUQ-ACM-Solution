#include <iostream>
using namespace std;
long long c;
long long calc(long long a, long long b){
	long long ans = 1;
	while(b>0){
		if (b%2==1) ans = (ans * a) % c;
		b/=2;
		a=(a*a)%c;
	}
	return ans;
}
int main(){
    long long a,b;
    long long n;
    cin >> n;
    for(long long i=1;i<=n;i++){
        cin >> a >> b >> c;
        cout << calc(a,b) << endl;
    }
    return 0;
}