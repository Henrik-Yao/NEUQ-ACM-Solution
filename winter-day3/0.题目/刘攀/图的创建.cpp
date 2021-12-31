#include<bits/stdc++.h>
using namespace std;
struct node{
	int from;
	int to;
	int w;
};
node s[21000];
int s1[21000];
int cnt=0;
bool cmp(node a,node b){
	if(a.from!=b.from) return a.from<b.from;
	return a.to<b.to;
}
int main(){
	int n;
	int m;
	cin>>n>>m;
	for(int i=0;i<m;i++){
		cin>>s[i].from>>s[i].to>>s[i].w;
		s1[s[i].from]++;
	}
	sort(s,s+m,cmp);
	for(int i=0;i<n;i++){
		if(s1[i]==0) continue;
		int sum=s1[i];
		cout<<s[cnt].from<<":";
		for(int j=0;j<sum;j++){
			cout<<'('<<s[cnt].from<<","<<s[cnt].to<<","<<s[cnt].w<<')';
			cnt++;
		}
		cout<<endl;
	}
}
