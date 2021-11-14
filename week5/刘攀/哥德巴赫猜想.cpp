#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	long long x;
	long long sum=0;
	cin>>n;
	while(n--){
	sum=0;
	int flag=0;
	int cou=0;
	cin>>x;
	int m=sqrt(x);
	if(x%2==0) cout<<"2"<<endl;
	else {
		for(int i=3;i<=m;i++){
			if(x%i==0) flag=1;
		}
		if(flag==0) cout<<"1"<<endl;
		else{
			long long len=x-2;
			for(int i=2;i<=sqrt(len);i++){
				if(len%i==0) cou=1;
			}
			if(cou==1) cout<<"3"<<endl;
			else cout<<"2"<<endl;
			
	}
	}
	}
}
