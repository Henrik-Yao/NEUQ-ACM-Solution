#include<bits/stdc++.h> 
using namespace std;
int safe[55];
vector<int>t[110];
int visited[110];
stack<int>st;

int main()
{
	int n,m,k,i,j;
	cin>>n>>m>>k;
	for(i=0;i<110;i++)
	visited[i]=1;
	for(i=0;i<m;i++)
	{
		cin>>safe[i];
		visited[safe[i]]=0;
	}
	for(i=0;i<k;i++)
	{
		int a,b;
		cin>>a>>b;
		t[a].push_back(b);
		t[b].push_back(a);
	}
	int s,d;
	cin>>s>>d;
	bool flag=0;
	for(i=0;i<m;i++)
	{
		if(d==safe[i])
		{
			flag=1;
			break;
		}
	}
	if(!flag)
	{
		printf("The city %d is not safe!\n",d);
		return 0;
	}
	st.push(s);
	while(st.size())//当栈不为空时持续循环 
	{
		//cout<<st.size()<<endl;
		int now=st.top();
		//cout<<now<<" now"<<endl;
		if(now==d)	
		{
			printf("The city %d can arrive safely!\n",d);
			return 0;
		}
		int flag2=0;//标记栈顶元素是否有未被访问过的直接相连的安全城市 
		for(i=0;i<t[now].size();i++)//遍历与栈顶元素相连的城市 
		{
			if(visited[t[now][i]]==0)
			{
				st.push(t[now][i]);
				visited[t[now][i]]=1;
				flag2=1;
				break;
			}
		}
		//cout<<flag2<<" flag"<<endl;
		if(flag2==0)
		st.pop();
	}
	printf("The city %d can not arrive safely!\n",d);
	return 0;
}
