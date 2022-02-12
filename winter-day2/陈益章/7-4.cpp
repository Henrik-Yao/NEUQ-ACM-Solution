#include<iostream>
#include<vector>
using namespace std;
int n;
vector<int> th[1005];
bool visited[1005]; 
void fun(int c,int d){
	for(int i=0;i<th[c].size();i++)
	{
		if(th[c][i]==d)
		{
			cout<<"In the same gang"<<endl;
			return ;
		}
		if(visited[c]==0)
		fun(th[c][i],d);
		visited[c]=1;
	}
}
int main(){
	int m,q,a,b,c,d;
	cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		cin>>a>>b;
		th[a].push_back(b);
		th[b].push_back(a);
	}
	for(int i=0;i<q;i++){
		cin>>c>>d;
		fun(c,d);
	}
}
