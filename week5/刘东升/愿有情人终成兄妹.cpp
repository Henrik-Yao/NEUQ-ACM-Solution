#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,1};
const int dy[]={1,0,1,0};
const int M=100001;
int fm[M][3];//0,1�ֱ�����л�Ů��2������±��
char xy[M];//�����Ա� 
int s,n,k,man,women,t;;
void dfs(int man,int women,int sum);
void f(int man,int women);
int main()
{
	memset(xy,'0',sizeof(xy));
	memset(fm,-1,sizeof(fm));//�ȶ�������Ա��� 
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&t);//����ID
		scanf("%c %d %d",&xy[t],&fm[t][0],&fm[t][1]);//��¼��Ů�͸�ĸ 
		man=fm[t][0];//���ױ��
		women=fm[t][1];//ĸ�ױ�� 
		xy[man]='M';
		xy[women]='F';
		fm[man][2]=women;//���׵İ���Ϊĸ��
		fm[women][2]=man;//ͬ;
	}
	cin>>k;
	while(k--)
	{
		scanf("%d %d",&man,&women);
		f(man,women);
		if(k)
		{
			cout<<endl;
		}
	}
}
void dfs(int man,int women,int sum)
{
	if(sum>5) return;//���������򷵻� 
	if( (fm[man][0]==fm[women][0]&&fm[man][0]!=-1) || (fm[man][1]==fm[women][1]&&fm[man][1]!=-1))//ͬ������ĸ��ͬ
	{
		s=sum;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int fx=dx[i];
		int fy=dy[i];
		if(fm[man][fx]==-1||fm[women][fy]==-1) continue;
		dfs(fm[man][fx],fm[women][fy],sum+1);
	}
}
void f(int man,int women)
{
	s=6;//sĬ�ϴ���5
	if(fm[man][2]==women||fm[women][2]==man)//��Ϊ����
	{
		printf("Yes");
		return;
	}
	if(xy[man]==xy[women])//ͬ��
	{
		printf("Never Mind");
		return;
	}
	dfs(man,women,2);
	if(s>5) printf("Yes");
	else printf("No");
}
