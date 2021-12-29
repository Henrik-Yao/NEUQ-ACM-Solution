/*
7-5 �Թ�����-���·��
����ͼʾ��ʾһ���Թ�������Ϊ-1��ʾΧǽ,�ڲ�Ϊ-1��ʾ�ϰ�,
Ȩ ֵ1��2��5��9��ʾ������Ҫ���ĵ��������ۡ����ҳ������(3,6)������(8,8),
��������������С��·��(ע�Ȿ�����ĸ�������Թ�)
�����ʽ:
��һ�У��Թ��Ĵ�Сm n ���ֱ��ʾ�Թ��ĳ��͸� �ڶ��У���ںͳ��� �����У�
�Թ��ľ����ʾ ��ʾ����65535Ϊ�����
�����ʽ:
���Ϊ��������������С��·�������������
��������:
10 10
3 6 8 8
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
-1  2  1  1  1  1  1  5  1 -1
-1  1  9  9  9  1  1 -1  1 -1
-1  1  1  1  1  1  1 -1  1 -1
-1  1 -1 -1 -1 -1 -1 -1  1 -1
-1  1  9  9  9  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  1 -1
-1  1  1  1  1  1  1  1  2 -1
-1 -1 -1 -1 -1 -1 -1 -1 -1 -1
�������:
(8 8)(7 8)(6 8)(5 8)(4 8)(3 8)(2 8)(1 8)(1 7)(1 6)(2 6)(3 6)
*/
#include <bits/stdc++.h>
#define INF 65535
using namespace std;
int point[1000010][2],path[1000010][2],g[1001][1001],ans[1001][1001];
int walk[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
int m,n,startx,starty,endx,endy,cnt,sum;
void dfs(int x,int y){
	if(x==endx && y==endy){
			for(int i=0;i<cnt;i++){
				path[i][0]=point[i][0];
				path[i][1]=point[i][1];
				sum=cnt;
		}
		return;
	}
	for(int i=0;i<4;i++){
		int xx=x+walk[i][0];
		int yy=y+walk[i][1];
		if(xx<1 || xx>m || yy<1 || yy>n || g[xx][yy]==-1 || ans[xx][yy]<=ans[x][y]+g[xx][yy]) continue;
		point[cnt][0]=xx,point[cnt][1]=yy;
		ans[xx][yy]=ans[x][y]+g[xx][yy];
		cnt++;
		dfs(xx,yy);
		cnt--;
	}
}
int main(){
	freopen("in5.txt","r",stdin);
	cin>>m>>n>>startx>>starty>>endx>>endy;
	for(int i=0;i<m;i++)
		for(int j=0;j<n;j++){
			int data;
			cin>>data;
			g[i][j]=data;
		}
	for(int i=1;i<=m-2;i++)
		for(int j=1;j<=n-2;j++) ans[i][j]=INF;
	ans[startx][starty]=g[startx][starty];
	point[cnt][0]=startx,point[cnt][1]=starty;
	cnt++;
	dfs(startx,starty);
	for(int i=sum-1;i>=0;i--) cout<<"("<<path[i][0]<<" "<<path[i][1]<<")";
	cout<<endl;
}

