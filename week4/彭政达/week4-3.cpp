#include <bits/stdc++.h>
using namespace std;
#define MAX 10000001
int num=0,a[MAX];
bool jud[MAX];
void f(int n){
	memset(jud,1,sizeof(jud));
	jud[0]=0,jud[1]=0;
	for(int i=2;i<n;i++){
		if(jud[i])
			a[num++]=i;
		for(int j=0;j<num && i*a[j]<=n;j++){
			jud[i*a[j]]=0;
			if(i%a[j]==0) break;
		}
	}
}
void g(int n){
	memset(jud,1,sizeof(jud));
	jud[0]=0,jud[1]=0;
	for(int i=2;i<=sqrt(n);i++){
		for(int j=2;i*j<n;j++)
			jud[i*j]=0;
		if(jud[i]) a[num++]=i;
	}
}
int main(){
	int n,flag=0;
	cin>>n;
	f(n);
	for(int i=1;i<=n;i++)
		if(jud[i]) flag++;
	cout<<flag<<endl;
}
