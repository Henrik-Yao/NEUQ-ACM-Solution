#include<bits/stdc++.h>
using namespace std;
int main(){
	int a[11000];
	memset(a,0,sizeof(a));
	int i,j,k;
	for(i=2;i<=100;i++){
		if(a[i]==1)continue;
		else for(j=i*i;j<=10000;j+=i){
			a[j]=1;
		}
	}
	while(~scanf("%d%d",&j,&k)){
		int flag;
		for(flag=1;j<=k;j++){
			if(!a[j]&&flag==1){
				flag=0;
				cout<<j;
			}
			else if(!a[j]&&flag==0){
				cout<<" "<<j;
			}
		}
		cout<<endl;
	}
    return 0;
}
