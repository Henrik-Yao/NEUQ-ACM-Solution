#include<bits/stdc++.h>
using namespace std;
int sum[10001];
int len=0;
int main(){
	int a,b;
	int flag=0;
	while(cin>>a>>b){
		memset(sum,0,sizeof(sum));
		len=0;
		for(int i=a;i<=b;i++){
			for(int j=2;j<=i/2;j++){
				if(i%j==0){
					flag=1;
				}
			}
			if(flag==0) sum[len++]=i;
			flag=0;
		}
		for(int i=0;i<len;i++){
			cout<<sum[i];
			if(i!=len-1) cout<<" ";
		}
		cout<<endl;
	}
}
