#include <iostream>
#include <cstring>
using namespace std;
int prime[11000005];
int flag[11000005];
int main(){
	int b;
	cin >> b;
	int p=0;
	for(int i=2;i<=b;i++){
		if(flag[i]==0){
			prime[p++]=i;
		}
		for(int j=0;j<p&&i*prime[j]<=b;j++){
			flag[i*prime[j]]=1;
			if(i%prime[j]==0) break;
		}
	}
	cout << p << endl;
	return 0;
}