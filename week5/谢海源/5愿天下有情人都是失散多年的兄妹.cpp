#include<bits/stdc++.h>
using namespace std;
const int dx[]={0,0,1,1};
const int dy[]={1,0,1,0};
int fm[100005][3];//0,1代表男或女，2代表伴侣编号
char xy[100005];
int s;
void dfs(int a,int b,int sum)
{
	if(sum>5) return;
	if( (fm[a][0]==fm[b][0]&&fm[a][0]!=-1) || (fm[a][1]==fm[b][1]&&fm[a][1]!=-1))//同辈父或母相同
	{
		s=sum;
		return;
	}
	for(int i=0;i<4;i++)
	{
		int fx=dx[i];
		int fy=dy[i];
		if(fm[a][fx]==-1||fm[b][fy]==-1) continue;
		dfs(fm[a][fx],fm[b][fy],sum+1);
	}
}
void f(int a,int b)
{
	s=6;//s默认大于5
	if(fm[a][2]==b||fm[b][2]==a)//互为伴侣
	{
		printf("Yes");
		return;
	}
	if(xy[a]==xy[b])//同性
	{
		printf("Never Mind");
		return;
	}
	dfs(a,b,2);
	//cout<<s<<endl;
	if(s>5) printf("Yes");
	else printf("No");
}
int main()
{
	memset(xy,'0',sizeof(xy));
	memset(fm,-1,sizeof(fm));
	int n,k,a,b,t;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d ",&t);//个人ID
		scanf("%c %d %d",&xy[t],&fm[t][0],&fm[t][1]);
		a=fm[t][0];//父亲编号
		b=fm[t][1];
		xy[a]='M';
		xy[b]='F';
		fm[a][2]=b;//父亲的伴侣为母亲
		fm[b][2]=a;
	}
	cin>>k;
	while(k--)
	{
		scanf("%d %d",&a,&b);
		f(a,b);
		if(k)cout<<endl;
	}
	return 0;
}