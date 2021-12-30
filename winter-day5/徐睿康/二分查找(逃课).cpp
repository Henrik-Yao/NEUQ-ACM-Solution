#include<bits/stdc++.h>
using namespace std;
int n,a[110],m,q;
int main(){
	while(cin>>n){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		if(i==1)cout<<a[i];
		else cout<<' '<<a[i];
		cout<<endl;
		cin>>m;
		for(int i=1;i<=m;i++){
			cin>>q;
			int pos=lower_bound(a+1,a+n+1,q)-a;
			if(pos>n){
				cout<<0;
			}
			else if(a[pos]==q){
				cout<<pos;
			}
			else cout<<0;
			if(i!=m)cout<<' ';
		}
		cout<<endl;
	}
	return 0;
}
