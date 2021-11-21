#include <iostream>
#include <cstring>
using namespace std;
int prime[11005];
int main(){
	int a,b;
	memset(prime,0,11000);
	int flag[11005];
	memset(flag,0,11000);
	int p=0;
	for(int i=2;i<=11000;i++){
		if(flag[i]==0){
			prime[p++]=i;
		}
		for(int j=i;j<=11000;j=j+i){
			flag[j]=1;
		}
	}
	while(cin>>a>>b){
		int start,end,startfind=0,endfind=0;
		for(int i=0;i<p-1;i++){
			if(prime[i]>=a&&startfind==0) {start=i;startfind=1;}
			if(prime[i]>b) {end=i-1;break;}
		}
		if(startfind!=endfind){
			cout << prime[start];
			for(int abc=start+1;abc<=end;abc++){
				cout << " " << prime[abc];		
			}
			cout << endl;
		}		
	}	
	return 0;
}