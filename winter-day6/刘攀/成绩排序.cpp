#include<bits/stdc++.h>
using namespace std;
int n;
struct node{
	string name;
	int score;
};
node s[100];
bool cmp(node a,node b){
	if(a.score!=b.score) return a.score>b.score;
	return a.name<b.name;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>s[i].name>>s[i].score;
	}
	sort(s,s+n,cmp);
	for(int i=0;i<n;i++){
		cout<<s[i].name<<" "<<s[i].score<<endl;
	}
}
