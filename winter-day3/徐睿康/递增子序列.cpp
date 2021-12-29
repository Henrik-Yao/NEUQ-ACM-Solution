#include<bits/stdc++.h>
using namespace std;
int cnt=0,n,a[20],len[100010],cun[100010][20],sta[20],flag,flagg,top=0;
void dfs(int x,int sum,int geshu){
	//printf("%d %d %d\n",x,sum,geshu);
	if(x!=0){
		sta[++top]=a[x];
	}
	if(geshu>=2){
		flagg=0;
		for(int i=1;i<=cnt;i++){
			flag=0;
			for(int j=1;j<=max(top,len[i]);j++){
				if(cun[i][j]!=sta[j]){
					flag=1;
					break;
				}
			}
			if(flag==0){
				flagg=1;
				break;
			}
		}
		if(flagg==0){
			cnt++;
			len[cnt]=top;
			for(int i=1;i<=top;i++){
				cun[cnt][i]=sta[i];
				//cout<<sta[i]<<' ';
			}
			//cout<<endl;
		}
	}
	for(int i=x+1;i<=n;i++){
		if(a[i]>=sum)
		dfs(i,a[i],geshu+1);
	}
	if(x!=0)top--;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=1;j<=n;j++)cun[i][j]=-1e9;
	}
	dfs(0,-1e9,0);
	cout<<cnt;
	return 0;
}
