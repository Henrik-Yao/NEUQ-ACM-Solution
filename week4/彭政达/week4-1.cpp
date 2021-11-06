#include<bits/stdc++.h>
using namespace std;
const int MAX=10001;
int m,n;
int p,prime[MAX];
bool jud[MAX];
void isprime(int n){
	int i,j;
	p=0,no[1]=1;
	for(i=2;i<=m;i++){
		if(!jud[i]) prime[++p]=i;
		for(j=1;j<=p;j++){
			if(i*prime[j]>n) break;
			no[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
}
int main(){
    ios::sync_with_stdio(false);
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    memset(prime,0,sizeof(prime));
    memset(no,0,sizeof(jud));
	while(cin>>n>>m){
		isprime(m);
		for(int i=1;i<=p;i++) 
			if(prime[i]>=n){
			if(i!=p)
				cout<<prime[i]<<' ';
			else
				cout<<prime[i]<<endl;
		}
	}
}
