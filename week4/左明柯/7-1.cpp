#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+20;
bool is_prime[maxn];
int prime[maxn]={0};
int q=0;
void f(int n){
	memset(is_prime,true,sizeof(is_prime));
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[q++]=i;
			for(int j=i*i;j<=n;j+=i){
				is_prime[j]=false;
             
			}
		}
	}
}
int main(){
int a,b;
while(cin>>a>>b){
    int cnt=0;
f(b);
for(int i=a;i<=b;i++){
	if(is_prime[i]) cnt++;
}
    for(int i=a;i<=b;i++){
        if(is_prime[i]) {cout<<i;if(--cnt) cout<<' ';}
        
    }
    cout<<endl;
}


return 0;

}
