#include<bits/stdc++.h>
using namespace std;
int cnt=0,a[1010],n,flag,cun;
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		a[0]=0;
		for(int i=2;i<=n;i++){
			flag=0;
			cun=a[i];
			for(int j=i;j>=0;j--){
				if(a[i]>a[j]){
					flag=1;
					for(int k=i-1;k>=j+1;k--){
						a[k+1]=a[k];
					}
					a[j+1]=cun;
				}
				if(flag==1)break;
			}
			for(int j=1;j<=n;j++){
				if(j==1)cout<<a[j];
				else cout<<' '<<a[j];
			}
			cout<<endl;
		}	
	}
	return 0;
}
