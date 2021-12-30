#include<iostream>
using namespace std;
const int inf = 0x3f3f3ff3;
const int maxn = 110;
int minpath[maxn][maxn],road[maxn][maxn], n, m, t;
void init() {
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			if(i ==j)	minpath[i][j] = 0, road[i][j] = j;
			else	minpath[i][j] = inf, road[i][j] = j;
}
void Floyed(int s,int e)
{
	for(int k = 0; k < n; k++) {//中间转折点。
		for(int i = 0; i < n; i++) {//起始点。
			for(int j = 0; j < n; j++) {//终点。
				if(minpath[i][j] > minpath[i][k] + minpath[k][j]) {//当前的路是否更好，
					minpath[i][j] = minpath[i][k] + minpath[k][j];
					road[i][j] = road[i][k];
				}
			}
		}
	}

    if(minpath[s][e]==inf)
    {
        cout<<"connection impossible"<<endl;
    }
    else
    {
        cout <<minpath[s][e] <<endl;//s->t的花费。
    }
}

int main() {
    //输入表示n个点，m条边，求s为起始点，求其到 n 个点的距离。
	while(cin>>n>>m)
    {
        init();//初始化
	    int x, y;
        for(int i = 0; i < n; i++)
       {
		cin >> x >>y;
		for(int j = 0;j < y;j++)
        {
            int poi;
            cin>>poi;
            minpath[x][poi]=1;
        }
	   }
	    for(int i=0;i<m;i++)
        {
            int s,e;
            cin>>s>>e;
            Floyed(s,e);//算法本体
        }
    }

	return 0;
}
