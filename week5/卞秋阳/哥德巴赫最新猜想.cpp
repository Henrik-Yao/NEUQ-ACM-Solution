#include<bits/stdc++.h>
using namespace std;
	long long n,m;
int sushu(int k){
	for(int j=2;j<=sqrt(k);j++){
			if(k%j==0){
			return 1;}
		}
	
	return 0;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)
	{   cin>>m;
		if(sushu(m)==0){cout<<"1"<<endl;}
		else if(m%2==0){
		cout<<"2"<<endl;
		}
		
		else if(sushu(m-2)==0){
		
		cout<<"2"<<endl;
		}
		else{
			cout<<"3"<<endl;
		}
	}
	

	
	
}



