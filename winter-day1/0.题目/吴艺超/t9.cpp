#include<bits/stdc++.h>
using namespace std;
struct ax{
	char name[4];
	int t,p;
}a[10005];
bool vis[10005];
int f[10005],ans[10005];//f[i]表示序号为i的人所属圈子，ans记录排名 
int n,m,l,num,ptime,c;//ptime为表示上一个人完成时当前的时间，c统计排名当前个数 
char name[4];
double w;
map<string,int> mp;//将姓名与序号连接 
int main()
{
	cin>>n>>m;
	while(m--)
	{
		cin>>l;
		for(int i=0;i<l;i++){
			cin>>name;
			f[mp[name]=++num]=m+1;//记录圈子 
		}
	}
	for(int i=0;i<n;i++)
	{
		cin>>a[i].name>>a[i].t>>a[i].p;
		if(a[i].p>60)a[i].p=60;//t>60按60算 
	}
	int i=0;
	while(i<n)
	{
		while(i<n && vis[i])i++;//排过了往下走 
		int d=f[mp[a[i].name]],j=i;//d为圈子，j是枚举后面的人 
		if(i>=n)break;//都排完了 
		do{
			if(vis[j] || f[mp[a[j].name]]!=d){//找没排过并且属于圈子的 
				j++;
				continue;
			}
			w+=max(0,ptime-a[j].t);//w记录等待时间，即当前时间与到达时间差值（<0赋值为0） 
			ans[c++]=j;//统计答案 
			ptime=max(ptime,a[j].t)+a[j].p;//更新时间 
			vis[j++]=1;//更新人 
		}
		while(d && j<n && a[j].t<=ptime);//必须有圈子并且后面的人的到达时间比当前时间小 
	}
	for(int i=0;i<n;i++)
	{
		cout<<a[ans[i]].name<<endl;
	}
	printf("%.1f",w/n);
	return 0;
}
