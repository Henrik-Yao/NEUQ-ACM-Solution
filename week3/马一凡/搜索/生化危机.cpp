#include <iostream>
using namespace std;

typedef struct 
{
	int arcs[1000][1000];
	int v,a; 
}graph;

int main()
{
	int n;
	int now,d,flag=0;
	int x,y;
	graph G;
	int s[1000];
	
	cin >> G.v >> n >> G.a ;

	for(int i=0; i<n; i++)
	{
		cin >> s[i];
	}
	for(int i=0; i<G.v; i++)
	{
		for(int j=0; j<G.v; j++)
		{
			G.arcs[i][j] = 0;
		}
	}
	for(int i=0; i<G.a; i++)
	{
		cin >> x >> y;
		G.arcs[x][y] = 1;
		G.arcs[y][x] = 1;
	}
	
	cin >> now >> d;
	
	for(int i=0; i<n; i++){
		if(d == s[i]){
			flag = 1;
			break;
		}
	}
	if(G.arcs[now][d] == 1){
		if(flag == 1)
			cout << "The city " << d << " can arrive safely!" << endl;
		else 
		{
			cout << "The city " << d << " is not safe!" << endl;
			
		}
	}
	else
	{
		if(flag == 1)
		cout << "The city " << d << " can not arrive safely!" << endl;
		else cout << "The city " << d << " is not safe!" << endl;
	}
	return 0;
}

