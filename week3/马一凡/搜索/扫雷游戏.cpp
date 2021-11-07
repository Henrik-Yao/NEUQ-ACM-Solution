#include<iostream>
using namespace std; 

int flag,xp;
int n,m,k,l,t;
int a[25][25];
bool c[25][25];

void F(int x,int y)
{
	if(c[x][y] == 1) 
		return;
	c[x][y] = 1;
	if(a[x][y] == 0){
	if(x-1 > 0)
		F(x-1,y);
	if(x+1 <= n)
		F(x+1,y);
	if(y-1 > 0)
		F(x,y-1);
	if(y+1 <= m)
		F(x,y+1);
	if(x-1 > 0 && y-1 > 0)
		F(x-1,y-1);
	if(x-1 > 0 && y+1 <= m)
		F(x-1,y+1);
	if(x+1 <= n && y-1 > 0)
		F(x+1,y-1);
	if(x+1 <= n && y+1 <= m)
		F(x+1,y+1);
	}
}


void fion(int x,int y)
{
	if(x-1>0 && a[x-1][y]!=-1)
		a[x-1][y]++;
	if(x+1<=n && a[x+1][y]!=-1)
		a[x+1][y]++;
	if(y-1>0 && a[x][y-1]!=-1)
		a[x][y-1]++;
	if(y+1<=m && a[x][y+1]!=-1)
		a[x][y+1]++;
	if(x-1>0 && y-1>0 && a[x-1][y-1]!=-1)
		a[x-1][y-1]++;
	if(x-1>0 && y+1<=m && a[x-1][y+1]!=-1)
		a[x-1][y+1]++;
	if(x+1<=n && y-1>0 && a[x+1][y-1]!=-1)
		a[x+1][y-1]++;
	if(x+1<=n && y+1<=m && a[x+1][y+1]!=-1)
		a[x+1][y+1]++;
}

inline int read()
{
	char ch = getchar();
	int x=0,f=1;
	while(ch<'0' || ch>'9')
	{
		if(ch == '-')
			f=-1;
		ch = getchar();
	}
	while(ch>='0' && ch<='9')
	{
		x = x*10+(ch^48);
		ch = getchar();
	}
	return x*f;
}

int main()
{
	int x,y;
	cin >> n >> m >> k >> l;
	for(int i=1; i<=k; i++)
	{
		
		cin >> x >> y;
		x++;
		y++;
		a[x][y]=-1;
		fion(x,y);
	}

	while(l--)
	{
		cin >> x >> y;
		x++;
		y++;
		if(a[x][y]==-1)
		{
			flag=1;
			break;
		}
		if(c[x][y]==1)
			continue;
		if(c[x][y]==0)
		{
			F(x,y);
		for(int i=1; i<=n; i++)
		{
			for(int j=1; j<=m; j++)
			{
				if(c[i][j]==1)
					cout << a[i][j] << " ";
				else
				{
					cout<<-1<<" ";
					if((a[i][j]!=-1))
						xp=1;
				}
			}
		if(i!=0)
			cout<<endl;
		}
		if(xp==0)
		{
			cout<<"You win"<<endl;
			return 0;
		}
		else{
			xp=0;
			cout<<endl;
		}
		}
	}
	if(flag==1)
	{
		cout<<"You lose"<<endl;
		return 0;
	}
	
	
	return 0;
}
