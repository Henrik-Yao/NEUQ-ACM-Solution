#include<bits/stdc++.h>
using namespace std;
//void f(int a,int b,int c);
int main(){
   	int n,i;
   	cin>>n;
   	for(i=0;i<n;i++){
   		long long a,b,c;
   		cin>>a>>b>>c;
		int num=1;
		while(b){
			if(b%2==1){
				num=(num*a)%c;
			}
			b/=2;
			a=(a*a)%c;
		}
		cout<<num<<endl;
	}
	return 0;
}
