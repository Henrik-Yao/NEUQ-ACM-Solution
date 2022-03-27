#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#define N 10001
using namespace std;
map<string,int>q;
string a[N];
int n,m;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		string b;
		cin>>a[i]>>b;
		q[b]=i;
	}
	for(int i=1;i<=m;i++){
		string b;
		cin>>b;
		if(q[b]==0) printf("eh");
		else{
			int len=a[q[b]].size();
			for(int j=0;j<len;j++)
				printf("%c",a[q[b]][j]);
		}
		printf("\n");
	}
	return 0;
}
