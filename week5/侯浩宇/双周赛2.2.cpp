#include<bits/stdc++.h>
using namespace std;
bool p=0;
int main (){
	int n;
	int num;
	cin>>n;
	for(int i=0;i<n;i++){
			p=0;
			cin>>num;
			if(num%2==0){cout<<2<<endl;continue;}
			for(int j=2;j<=sqrt(num);j++)
			if(num%j==0){p=1;break;}
			if(!p){cout<<1<<endl;continue;}
        p=0;
			for(int j=2;j<=sqrt(num-2);j++)
			if((num-2)%j==0){p=1;break;}
			if(p){cout<<3<<endl;continue;}
			else {cout<<2<<endl;continue;}
		}
    return 0;
}
