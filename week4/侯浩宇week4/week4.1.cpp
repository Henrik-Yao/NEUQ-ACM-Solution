#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,p[10000],num,num1;
	while(cin>>a>>b){
		num=b-a+1;
		for(int i=a;i<=b;i++){
				for(int j=2;j<=sqrt(i);j++){
					p[i]=0;
	//				cout<<i<<"%"<<j<<"="<<i%j<<endl;
					if(i%j==0){
						p[i]=1;
						num--;
						break;
					}
				}
		}
		num1=0;
		for(int i=a;i<=b;i++){
		//	cout<<!p[i];
			if(!p[i]){
			cout<<i,num1++;	
			if(num1<num) cout<<" ";/**/
			}
			
		}
		cout<<endl;
	}
	return 0;
}
