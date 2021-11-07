#include <bits/stdc++.h>
using namespace std;
const int maxn=1e7+20;
bool is_prime[maxn];
int prime[maxn]={0};
int q=0;
void f(int b){
	int k=0;
	memset(is_prime,true,sizeof(is_prime));
	for(int i=2;i<=b;i++){
		if(is_prime[i]){
			prime[q++]=i;
			}
			while(1){
				if(i*prime[k]>b){
					break;
				}
				is_prime[i*prime[k]]=false;
				if(i%prime[k]==0){
					break;
				}
				k++;
			}
			k=0;
		}
	}

int main(){
int b;
cin>>b;
f(b);
cout<<q<<endl;




return 0;

}
