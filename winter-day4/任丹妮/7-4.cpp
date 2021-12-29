#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f3f;
int mp[101][101];
int path[101][101];
typedef long long ll;
void output(int a,int b){
	if(path[a][b]==-1) return;
	output(a,path[a][b]);
	cout<<path[a][b]<<"->";
	output(path[a][b],b);
}
int main(){
    int n,e;
    cin>>n>>e;
    memset(path,-1,sizeof(path));
        for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i!=j)
                mp[i][j]=inf;
            else
                mp[i][j]=0;
        }
    }
        while(e--){
            int h,t,w;
            cin>>t>>h>>w;
            mp[t][h]=w;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++){
                    if(mp[i][j]>mp[i][k]+mp[k][j])
                    {
                        mp[i][j]=mp[i][k]+mp[k][j];
                        path[i][j]=k;
                    }
                }
                    
            
        }
            for(int k=0;k<2;k++){
                int u,v;
                cin>>u>>v;
                cout<<u<<"->";
                int s=u;//´òÓ¡Â·¾¶
            if(mp[s][v]>100000) {
            	cout<<v<<":"<<"-1"<<endl;
            	continue;
			}
			output(u,v);
            cout<<v<<":";
			cout<<mp[u][v]<<endl; 
            } 
			int max=-1,start,end;  
			for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				if(mp[i][j]!=inf&&mp[i][j]>max) {
					start=i;
					end=j;
					max=mp[i][j];
				}
			
			} 
			cout<<start<<"->";
			output(start,end);
            cout<<end<<":";
			cout<<max<<endl;    
    return 0;
}
