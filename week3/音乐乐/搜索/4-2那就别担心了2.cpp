#include<bits/stdc++.h>
using namespace std;

int N,M,A,B;
vector<int>t[520];
int v[520],f[520];//f��ǴӴ˴���B�����·������v����Ƿ񱻷��ʹ� 

int dfs(int x)
{
    v[x]=1;
    if(f[x]) return f[x];//�Ѿ����յ㣬�ݹ���� 
    for(auto y:t[x])
    {
    	f[x]+=dfs(y);
	}//������ǰ�㴦�ķ�֧������֧�ɵ���B���·�������ӵ���ǰ���� 
    return f[x];
}
int main()
{
	cin>>N>>M;
	int i;
	while(M--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		t[a].push_back(b);//bΪa�ķ�֧ 
	}
	cin>>A>>B;
	f[B]=1;//����յ㣬Ϊdfs�еݹ麯����ֹ���� 
	cout<<dfs(A)<<" ";
    int flag=1;
    for(i=1;i<=N;++i)
        if(!f[i]&&v[i])//���ĳ���A�����Է��ʵ�����û��·������B �������߼���Ǣ�� 
			flag=0;
	if(flag)
	cout<<"Yes";
	else
	cout<<"No";
	return 0;
}
