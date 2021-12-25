#include <map>
#include <vector>
#include <cstdio>
#include <string>
#include <iostream>
#define N 10001
using namespace std;
int n,m,k,tot;
int com[N];
struct ss{
	string name;
	int arrtime;
	int contime;
}a[N];
map<string,int> friends;
map<string,int>::iterator Iter;
vector<ss> q;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d",&k);
		for(int j=1;j<=k;j++){
			string name;
			cin>>name;
			friends[name]=i;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].name>>a[i].arrtime>>a[i].contime;
		if(a[i].contime>60) a[i].contime=60;
	}
	int nowtime=0;
	for(int i=1;i<=n;i++)
		if(com[i]==0){
			if(a[i].arrtime>nowtime) nowtime=a[i].arrtime;
			tot+=nowtime-a[i].arrtime;
			nowtime+=a[i].contime;
			Iter=friends.find(a[i].name);
			q.push_back(a[i]);
			if(Iter==friends.end())
				com[i]=1;
			else{
				for(int j=i+1;j<=n;j++)
					if(com[j]==0&&friends[a[j].name]==Iter->second&&a[j].arrtime<=nowtime){
						tot+=nowtime-a[j].arrtime;
						nowtime+=a[j].contime;
						com[j]=1;
						q.push_back(a[j]);
					}
			}
		}
	for(int i=0;i<q.size();i++)
		cout<<q[i].name<<endl;
	printf("%.1f\n",(double)tot/(double)n);
	return 0;
}
