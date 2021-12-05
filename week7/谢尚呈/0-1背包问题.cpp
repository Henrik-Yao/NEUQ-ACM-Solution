#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;

int n_thing, v_bag;
int weight[403], value[403];
int max_v[403][1503];
int solve(int now, int bag_left)
{
	if(max_v[now][bag_left]!=-1) return max_v[now][bag_left];
	if(now>=n_thing)
		return max_v[now][bag_left]=0;
	int va1, va2=-999;
	va1=solve(now+1, bag_left);
	if(bag_left>=weight[now])
		va2=solve(now+1, bag_left-weight[now])+value[now];
	return max_v[now][bag_left]=max(va1, va2);
}
int main(){
	while(cin>>n_thing)
	{
		memset(max_v, -1, sizeof(max_v));
		cin>>v_bag;
		for(int i=0; i<n_thing; i++)
			cin>>weight[i];
		for(int i=0; i<n_thing; i++)
			cin>>value[i];
		cout<<solve(0, v_bag)<<endl;
	}
	return 0;
}
