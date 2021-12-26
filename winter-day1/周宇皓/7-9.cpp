#include<bits/stdc++.h>
using namespace std;
const int N = 10010;
struct P{
	string name;
	int s;
	int e;
	int pos;
}p[N];
int m,n;
map<string,int> group;
string name;
queue<P> q;
int main(){
	cin>>n>>m;
	int num;
	for(int i = 0;i < m; i++){
		cin>>num;
		for(int j = 0; j < num; j++){
			cin>>name;
			group[name]=i;
		}
	}
	for(int i = 0; i < n; i++){
		cin>>p[i].name>>p[i].s>>p[i].e;
		if(p[i].e>60)
		p[i].e = 60;
		p[i].pos=i;
		q.push(p[i]);
	}
	int last = 0;
	int ans = 0;
	bool flag[N];
	memset(flag,false,sizeof(flag));
	while(!q.empty()){
		P temp = q.front();
		q.pop();
		if(!flag[temp.pos]){
			flag[temp.pos] = true;
			if(temp.s<=last){
				ans+=last-temp.s;
				last+=temp.e;
			}
			else
			last = temp.s+temp.e;
			cout<<temp.name<<endl;
			for(int i = temp.pos+1;i<n;i++){
				if(p[i].s>last)
				break;
			 if(temp.name != p[i].name &&!flag[i]&&group.count(temp.name)&&group.count(p[i].name)&&group[temp.name] == group[p[i].name]){
			 	flag[i]=true;
			 	cout<<p[i].name<<endl;
			 	ans+=(last - p[i].s);
				last+=p[i].e;
			 }
			}
		}
	}
	printf("%.1f",1.0*ans/n);
}
