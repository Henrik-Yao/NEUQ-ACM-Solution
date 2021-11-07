#include <bits/stdc++.h>
using namespace std;
int main(){
	long long a,b,c;
	int t;
	cin>>t;
	while(t--){
		cin>>a>>b>>c;
		int sum=1;
		while(b>0){
			if(b%2==0){
				b=b/2;
				a=a*a;
			}
			else{
				b-=1;
				sum=sum*a%c;
			}
		}
		sum%=c;
		cout<<sum<<endl;
	}
    return 0;
}




