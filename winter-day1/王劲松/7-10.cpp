#include<bits/stdc++.h>
using namespace std;
int a[100][100];
int c[100];
int check(int j,int k);
int main(){
	int n,i,cnt=0,flag;
	cin>>n;
	int b[100];
	for(i=0;i<n;i++){
		scanf("%d",&b[i]);
	}
	a[cnt][c[cnt]++]=b[0];
	for(i=1;i<n;i++){
		int mm=check(b[i],cnt);
		if(mm==-1)a[++cnt][c[cnt]++]=b[i];
		else a[mm][c[mm]++]=b[i];
		if(b[i]==1)flag=mm;
	}
	for(i=0;i<c[flag];i++){
		cout<<a[flag][i];
		if(i!=c[flag]-1)cout<<" ";
		else cout<<endl;
	}
	
	cout<<cnt+1<<endl;
	return 0;
}
int check(int j,int k){
	int min=100,fa=-1;
	for(int t=0;t<=k;t++){
		if(a[t][c[t]-1]<j)continue;
		if(a[t][c[t]-1]<min){
			min=a[t][c[t]-1];
			fa=t;
		//	cout<<"j="<<j<<"min="<<min<<endl;
		}
	}//cout<<"fa="<<fa<<endl;
	return fa;
}
