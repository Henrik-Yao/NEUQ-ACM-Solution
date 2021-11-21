#include<bits/stdc++.h>
using namespace std;

int a[10005]={0,0,1,1},cnt;

inline int prime(int x){
	if(x%6!=1&&x%6!=5)return 0;
	for(register int i=5;i*i<=x;i+=6)
		if(x%i==0||x%(i+2)==0)
			return 0;
	return 1; 
}

int main(){
	int aa,bb;
	for(int i=4;i<=10000;i++)a[i]=prime(i);
	while(cin>>aa>>bb){
		if(cnt)cout<<endl;
		cnt=0;
		for(register int i=aa;i<=bb;i++){
			if(a[i]){
				if(cnt)cout<<" ";
				cnt=1;
				cout<<i;
			}
		}
		cnt=1;
	}
	return 0;
}
