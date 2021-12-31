#include<bits/stdc++.h>

using namespace std;

int Map[55][55],a[55][55],vis[55][55],Map1[55][55];
int n,m,k,l,cnt;
int x_vis[10]={0,0,1,1,1,-1,-1,-1};
int y_vis[10]={-1,1,-1,0,1,-1,0,1};

bool pdfs(int x,int y)
{
	int t=0;
	for(int i=0;i<8;i++)
	{
		int xi,yi;
		xi=x+x_vis[i];
		yi=y+y_vis[i];
		if(xi<0||xi>=n||yi<0||yi>=m)
            continue;
		if(a[xi][yi]==1) t=1;
	}
	if(t==1)
	{
		return 0;
	}
	else
        return 1;
}
int put(int x,int y)
{
	int r=0;
	for(int i=0;i<8;i++)
	{
		int xi,yi;
		xi=x+x_vis[i];
		yi=y+y_vis[i];

		if(xi<0||xi>=n||yi<0||yi>=m)
            continue;
		if(a[xi][yi]==1) r++;
	}
	return r;
}
void f(int x,int y)
{
	vis[x][y]=1;
	cnt++;
	if(pdfs(x,y)==1)
	{

		Map[x][y]=Map1[x][y];
		for(int i=0;i<8;i++)
		{
			int xi,yi;
			xi=x+x_vis[i];
			yi=y+y_vis[i];
			if(xi<0||xi>=n||yi<0||yi>=m||vis[xi][yi])
                continue;
			f(xi,yi);
		}
		return;
	}
	else
	{
		Map[x][y]=Map1[x][y];
		return;
	}

}
int main()
{
	cin>>n>>m>>k>>l;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			Map[i][j]=-1;

	for(int i=1;i<=k;i++)
	{
		int xi,yi;
		cin>>xi>>yi;
		a[xi][yi]=1;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			Map1[i][j]=put(i,j);

		}

	}
	for(int t=1;t<=l;t++)
	{
		int xi,yi;
		cin>>xi>>yi;
		if(a[xi][yi]==1)
		{
			cout<<"You lose";
			break;
		}
		if(Map[xi][yi]!=-1)
            continue;
		if(Map[xi][yi]==-1)
		{
			f(xi,yi);
			for(int i=0;i<n;i++)
			{
				for(int j=0;j<m;j++)
				{
					cout<<Map[i][j]<<" ";
				}
				cout<<endl;
			}
		}

		if(n*m-k == cnt)
		{
			cout<<"You win";
			return 0;
		}
		cout<<endl;
	}


	return 0;
}
