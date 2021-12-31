#include<bits/stdc++.h>
using namespace std;
int n,m;
struct edge{
  int v,w;
}; 
vector <edge>p[20005]; 
int main()
{
  cin>>n>>m;
  for(int i =1;i<=m;i++)
  {
    int u,v,w;
    cin>>u>>v>>w;
    p[u].push_back(edge{v,w});
  }
  int k;
  cin>>k;
  for(int i=1;i<=k;i++)
  { int u,v,w;
  	cin>>u>>v;
  	p[u].erase(edge(v,w));
  }
  for(int i=1;i<=n;i++){
    cout<<i<<": ";
  for(int j=0;j<p[i].size();j++)
    cout<<"  "<<i<<"¡ú"<<p[i][j].v<<": "<<p[i][j].w<<" ";
  cout<<endl;
  }
  return 0;
}
