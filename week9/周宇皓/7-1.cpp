#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,s;
	while(cin>>n){
	long long a=1,b=2,c=4;
		if(n==1)
		cout<<1<<endl;
		else if(n==2)
		cout<<2<<endl;
		else if(n==3)
		cout<<4<<endl;
		else{
		for(int i=4;i<=n;i++){
		s=a+b+c;
		a=b;
		b=c;
		c=s;	
		}
		cout<<s<<endl;
	}
	}
}
