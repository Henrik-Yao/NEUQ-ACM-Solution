#include<bits/stdc++.h>
using namespace std;

#define INF 9999

int m[200][200]={0};
int path[200][200]={0};

void travel(int x,int y){
    if(path[x][y] == path[200][200]) 
		return ;
    travel(x, path[x][y]);
    cout << path[x][y] << "->" ;
    travel(path[x][y], y);
}

void print(int a,int b)
{
    cout << a << "->";
    travel(a,b);
    cout << b << ":";
    if(m[a][b] < INF) 
		cout << m[a][b];
    else cout << "-1";
}

int main()
{
    int n,e,a,b,c;
    memset(m, 0x3f, sizeof(m));
    memset(path, 0x3f, sizeof(path));
    cin >> n >> e;
    for(int i=0; i<e; i++){
        cin >> a >> b >> c;
        m[a][b] = c;
    }
    
    for(int i=0; i<n; i++) m[i][i] = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<n; k++)
                if(m[i][j] > m[i][k]+m[k][j]){
                    m[i][j] = m[i][k]+m[k][j];
                    path[i][j] = k;
                }
    cin >> a >> b;
    print(a,b);
    cout << endl;
    cin >> a >> b;
    print(a,b);
    cout << endl;
    int max=0;
    a = 0;
	b = 0;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++)
            if(m[i][j] > max && m[i][j] < INF){
                max = m[i][j];
                a = i;
				b = j;
            }
    print(a,b);
    return 0;
}
