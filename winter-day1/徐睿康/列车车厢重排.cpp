#include<bits/stdc++.h>
using namespace std;
int n,a[110],top[110],sta[110][110],minn,flag,flagg,cun=0,biaoji;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		minn=1e9;
		flag=-1;
		for(int j=1;j<=cun;j++){
			if(a[i]<sta[j][top[j]]){
				flag=1;
				if(sta[j][top[j]]-a[i]<minn){
					minn=sta[j][top[j]]-a[i];
					biaoji=j;
				}
			}
		}
		if(flag==-1){
			cun++;
			top[cun]++;
			sta[cun][top[cun]]=a[i];
		}
		else{
			top[biaoji]++;
			sta[biaoji][top[biaoji]]=a[i];
			if(a[i]==1)flagg=biaoji;
		}
		if(a[i]==1){
			if(flag==-1)flagg=cun;
		}
	}
	for(int i=1;i<=top[flagg];i++){
		if(i==1)cout<<sta[flagg][i];
		else cout<<' '<<sta[flagg][i];
	}
	cout<<endl;
	cout<<cun<<endl;
	return 0;
}
