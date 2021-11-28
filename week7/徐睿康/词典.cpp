#include<bits/stdc++.h>
using namespace std;
int n,m,flag;
string a[10010],b[10010],s;
int main(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>s;
		flag=0;
		for(int j=1;j<=n;j++){
			if(s==b[j]){
				cout<<a[j]<<endl;
				flag=1;
				break;
			}
		}
		if(flag==0)printf("eh\n");
	}
	return 0;
}
