#include<bits/stdc++.h>
using namespace std;
bool isprime[10005];
void F(){
    for(int i=2;i<=10000;i++){
        if(isprime[i]){
            for(int j=i*i;j<=10000;j+=i){
                isprime[j]=0;
            }
        }
    }
}
int main(){
    memset(isprime,1,sizeof(isprime));
    F();
    int n; 
    cin>>n;
	for(int i=4;i<=n;i+=2){
		for(int j=2;j<=n/2;j++){
			if(isprime[j]&&isprime[i-j]){
				printf("%d=%d+%d\n",i,j,i-j);
				break;
			}
		}
	}
    return 0;
}
