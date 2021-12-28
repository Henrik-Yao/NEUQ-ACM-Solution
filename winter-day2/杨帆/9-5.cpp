#include<bits/stdc++.h>
using namespace std;

int c[100],f[100],n,m;
string code[100];
char ch[100];
map<char,int> mp;

bool check(int WPL){
	int x,y,temp = 0;
	for(int i = 0;i<n;++i){
		for(int j = i+1;j<n;++j){
			x = code[i].find(code[j]);
			y = code[j].find(code[i]);
			if((x==0) || (y==0)){
				return false;
			}
		}
		temp+=mp[ch[i]]*code[i].length();
	}
	if(temp==WPL) return true;
	else return false;
}

int main(){
	cin>>n;
	priority_queue<int,vector<int>,greater<int> > que;
	for(int i = 0;i<n;++i){
		scanf(" %c %d",&c[i],&f[i]);
		que.push(f[i]);
		mp[c[i]] = f[i];
	}
	int WPL= 0,temp = 0;
	while(que.size()>1){
		temp = que.top();
		que.pop();
		temp+=que.top();
		que.pop();
		WPL+=temp;
		que.push(temp);
	}
	cin >> m;
	for(int i = 0;i<m;++i){
		for(int j = 0;j<n;++j){
			cin >> ch[j];
			cin >>code[j];
		}
		if(check(WPL))
			cout <<"Yes"<<endl;
		else
			cout <<"No"<<endl;
	}
	return 0;
}

