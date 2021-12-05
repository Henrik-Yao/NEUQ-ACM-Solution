#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    string a[10001],b[10001],c[10001];
    cin>>n>>m;
    for(int i=0;i<n;i++)
	cin>>a[i]>>b[i];
	for(int i=0;i<m;i++){
		cin>>c[i];int p=1;
		for(int j=0;j<n;j++){
			if(c[i]==b[j]){cout<<a[j]<<endl;p=0;break;}
		}
		if(p) cout<<"eh"<<endl;
	}
	return 0;
}
