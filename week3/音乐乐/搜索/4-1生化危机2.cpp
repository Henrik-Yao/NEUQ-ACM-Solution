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
	while(st.size())//��ջ��Ϊ��ʱ����ѭ�� 
	{
		//cout<<st.size()<<endl;
		int now=st.top();
		//cout<<now<<" now"<<endl;
		if(now==d)	
		{
			printf("The city %d can arrive safely!\n",d);
			return 0;
		}
		int flag2=0;//���ջ��Ԫ���Ƿ���δ�����ʹ���ֱ�������İ�ȫ���� 
		for(i=0;i<t[now].size();i++)//������ջ��Ԫ�������ĳ��� 
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
