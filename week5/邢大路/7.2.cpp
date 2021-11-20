#include<bits/stdc++.h>
using namespace std;
int isprime(int a){
    for(int i=2;i<=sqrt(a);i++){
        if(a%i==0)return 0;
    }
    return 1;
}
int n;
int main(){
   
    cin>>n;
    while(n--){
    	int a;
    	cin>>a;
  
    	if(!(a&1))cout<<"2"<<endl;
    	else if(isprime(a))cout<<"1"<<endl;
    	else if(isprime(a-2))cout<<"2"<<endl;
    	else cout<<"3"<<endl;
    	
	}
    return 0;
}
