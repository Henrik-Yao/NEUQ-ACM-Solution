#include<bits/stdc++.h>
using namespace std;
unsigned long long n,mem[100],flag;
long long po(long long x,long long y){
	long long ans=1;
	for(long long i=1;i<=y;i++){
		ans*=x;
	}
	return ans;
}
long long hnt(long long x){
	if(mem[x]!=0)return mem[x];
	long long minn=1e9;
	for(long long i=1;i<x;i++){
		flag=hnt(i)+po(2,x-i)-1+hnt(i);
		if(flag<minn)
		minn=flag;
	}
	return mem[x]=minn;
}
int main(){
	mem[1]=1;
	mem[2]=3;
	mem[3]=5;
	while(cin>>n){
		cout<<hnt(n)<<endl;	
	}
	return 0;
}
