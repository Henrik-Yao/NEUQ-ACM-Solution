#include<bits/stdc++.h>
using namespace std;
int a[100010];
typedef long long ll;
int main(){
	int m,n;
	cin>>m>>n;
	for(int i = 1; i <= m; i++)
	cin>>a[i];
	while(n--){
		int s,i,x,l,r;
		ll sum = 0;
		cin>>s;
		if(s==1)
		{
			cin>>i>>x;
			a[i]+=x;
		}
		else if(s==2){
			cin>>l>>r;
			for(int i = l;i <= r; i++)
			
			sum+=a[i];
			cout<<sum<<endl;
		}
	}
	return 0;
}
