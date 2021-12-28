#include<bits/stdc++.h>
using namespace std;
const int N=21451;
vector<int>Q[N];
int W[20001][20001];
int n,e;
int main(){
   cin>>n>>e;
   for(int i=0;i<e;i++){
   	int from,to,w;
   	cin>>from>>to>>w;
   	Q[from].push_back(to);
   	W[from][to]=w;
   }
   for(int i=0;i<n;i++){
   	sort(Q[i].begin(),Q[i].end());
   }
    int m;
    cin>>m;
    while(m--){
        int x,y;
        cin>>x>>y;
        for(int i=0;i<Q[x].size();i++){
            if(Q[x][i]==y)Q[x].erase(Q[x].begin()+i);
        }
    }
   for(int i=0;i<n;i++){
   	if(!Q[i].empty()){
   		cout<<i<<":";
   		for(int k=0;k<Q[i].size();k++){
   			cout<<"("<<i<<","<<Q[i][k]<<","<<W[i][Q[i][k]]<<")";
		   }
		   cout<<endl;
	   }
   }
   return 0;
}
