#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int k;
string s;
int gen[100050],ba[100050],ma[100050];
int vis[100050],flag=0;
void bfs(int a,int b,int step)
{
	if(flag==1) return;
    if(step>=4)
    {
    	return;
	}
	if((ma[a]!=-1&&ma[b]!=-1&&ma[a]==ma[b])||(ba[a]!=-1&&ba[b]!=-1&&ba[a]==ba[b]))
	{
//		cout<<a<<b<<endl;
	//	cout<<"No"<<endl;
		flag=1;
		return;
	}
	if(ma[a]!=-1&&ba[b]!=-1)
	bfs(ma[a],ba[b],step+1);
	
	if(ma[a]!=-1&&ma[b]!=-1)
	bfs(ma[a],ma[b],step+1);
	
	if(ba[a]!=-1&&ba[b]!=-1)
	bfs(ba[a],ba[b],step+1);
	
	if(ba[a]!=-1&&ma[b]!=-1)
	bfs(ba[a],ma[b],step+1);
	return;
}
int main()
{
  memset(ba,-1,sizeof(ba));
  memset(ma,-1,sizeof(ma));
  cin>>n;
  for(int i=0;i<n;i++)
  {
    cin>>a>>s>>b>>c;
    if(s=="M")
	gen[a]=1;
    else 
	gen[a]=0;
	ba[a]=b;
	gen[b]=1;
    ma[a]=c;
	gen[c]=0;
  }
	cin>>k;
	for(int i=1;i<=k;i++)
	{	
		int a,b;
    	cin>>a>>b;
   		if(gen[a]==gen[b])
      	{
     		cout<<"Never Mind"<<endl;
			continue;
     	}
     	else
      	{
		  	flag=0;
		 	bfs(a,b,0);
//		 	cout<<flag<<endl;
			if(flag==0) cout<<"Yes"<<endl;
			else cout<<"No"<<endl;
		}
		
  	}
    return 0;
}
