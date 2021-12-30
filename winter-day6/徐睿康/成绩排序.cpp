#include<bits/stdc++.h>
using namespace std;
int cnt=0,n;
struct node{
	int score;
	string name;
}a[30];
bool cmp(node x,node y){
	if(x.score==y.score)return x.name<y.name;
	else return x.score>y.score;
}
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].score;
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		cout<<a[i].name<<' '<<a[i].score<<endl;
	}
	return 0;
}
