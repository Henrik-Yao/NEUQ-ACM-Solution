#include<bits/stdc++.h>
using namespace std;
const int M=20001;
bool judge[M];//���У��ʼ���ǿյ� 
vector<int>infer[M];//��vector����һ��������� 
void dfs(int n);
int main()
{
	int n,T,first,second;
	cin>>n>>T;
	while(T--)
	{
		scanf("%d %d",&first,&second);
		infer[first].push_back(second);//����һ��ָ��ڶ��� 
	}
	for(int i=0;i<n;i++)//��ÿһ����ͼ���� 
	{
		if(judge[i]==0)
		{
			dfs(i);//���û�б����� 
		}
	}
}
void dfs(int n)
{
	int k;
    cout<<n<<" ";
	judge[n]=1;//����Ѿ������� 
	sort(infer[n].begin(),infer[n].end());//��ͷ����β 
	for(auto k:infer[n])//��ֵ���� 
	{
		if(judge[k]==0)
		{
			dfs(k);
		} 
	}
}
