#include <bits/stdc++.h>
using namespace std;
const int N = 210, INF = 1e9;
int n, m,x,y,z;
int d[N][N];
int pass[205][205];
int sum;
void floyd()
{
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(d[i][j]>d[i][k]+d[k][j]){
					d[i][j]=d[i][k]+d[k][j];
					pass[i][j]=k;
				}
}

void print(int i,int j){
	if(i==j)return;
	if(pass[i][j]==-1)cout<<i<<"->",sum+=d[i][j];
	else{
		print(i,pass[i][j]);
		print(pass[i][j],j);
	}
}
int main() {
	memset(pass,-1,sizeof(pass));
    cin>>n>>m;
    for(int i = 0; i <n; i++){
        for(int j =0; j<n; j++){
            if(i == j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while(m--) {
        cin >> x >> y >> z;
        d[x][y] =z;
    }
    floyd();
    int num=2;
    while(num--){
        sum=0;
    int a,b;
    cin>>a>>b;
    if(d[a][b]>1000000){
    	printf("%d->%d:-1\n",a,b);
    	continue;
	}
    if(a==b){printf("%d->%d:0\n",a,a);continue;}
    print(a,b);
   cout<<b<<":";
   cout<<sum<<endl;
    }
  	int maxx=0;
    int X,Y;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
		{
			if(d[i][j]>maxx && d[i][j]<1000000)
			{
				if(maxx!=d[i][j]){
				
				maxx=d[i][j];
				X=i,Y=j;
			}
			}
		}
    print(X,Y);
    cout<<Y<<":";
    if(maxx>10000000)
    cout<<"-1"<<endl;
    else cout<<maxx<<endl;
    
    
    return 0;

}

