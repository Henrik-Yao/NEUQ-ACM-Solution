/*#include <bits/stdc++.h>
using namespace std;
bool is[100000001];
vector<int>primes;
void sushu(int n){
    for(int i=2;i<=n;i++){
        if(!is[i])
            primes.push_back(i);
        for(int p:primes){
            if(p*i>n) break;
            is[p*i]=1;
            if(i%p==0) break;
        }
    }
}
int main(){
    int n;
    cin>>n;
    sushu(n);
    cout<<primes.size()<<endl;
}*/
#include <bits/stdc++.h>
using namespace std;
int sushu(int a){
    int i;
	if(a<2) return 0;
    for(i=2;i<=sqrt(a);i++){
        if(a%i==0) {
            return 0;
        }
    }
    if(i>sqrt(a)) return 1;
}
int main(){
	int n,sum=0;
	cin>>n;
	for(int i=2;i<=n;i++){
		if(sushu(i)) sum++;
	}
    cout<<sum<<endl;	
}
