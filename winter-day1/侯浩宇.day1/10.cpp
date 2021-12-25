#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100],minn=100,ans=0,b[100][100],b1=0;
	bool p[100],p1=1;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i],p[i]=1;
	while(p1){
		minn=100;
		for(int i=0;i<n;i++){
			if(p[i])
			if(minn>a[i]){
			minn=a[i],p[i]=0;
			b[ans][i]=a[i];
			if(a[i]==1) b1=ans;
			}
		}
		ans++;
		for(int i=0;i<n;i++){
			if(p[i]){p1=1;break;}
			else p1=0;
		}
	}
	int i=0;
	while(b[b1][i])
	cout<<b[b1][i++]<<" ";
	cout<<1<<endl;
	cout<<ans;
	return 0;
}
