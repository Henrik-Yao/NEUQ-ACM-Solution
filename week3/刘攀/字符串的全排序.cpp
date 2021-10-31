#include<bits/stdc++.h>
using namespace std;
char a[10];
int b[10];
char c[10];
int sum;
void dfs(int step){
	if(step==sum){
		for(int i=0;i<sum;i++){
			cout<<c[i];
		}
		cout<<endl;
	}
	else{
		for(int i=0;i<sum;i++){
			if(b[i]) continue;
			b[i]=1;
			c[step]=a[i];
			dfs(step+1);
			b[i]=0;
		}
	}
}
int main(){
	gets(a);
	sum=strlen(a);
	sort(a,a+sum);
	dfs(0);
}
