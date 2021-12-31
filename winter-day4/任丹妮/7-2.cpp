#include <bits/stdc++.h>
using namespace std;
int mp[220][220];
typedef long long ll;
int main(){
    int n,m;
    while(cin>>n>>m){
    	memset(mp,0x3f,sizeof(mp));
    	for(int i=0;i<n;i++)
    		mp[i][i]=0;
    	for(int e=0;e<n;e++){
    		int i,k;
    		cin>>i>>k;
    		while(k--){
    			int v;
    			cin>>v;
    			mp[i][v]=1;
			}
		} 
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(mp[i][j]>mp[i][k]+mp[k][j])
                        mp[i][j]=mp[i][k]+mp[k][j];
        }
        while(m--){
        	int a,b;
        	cin>>a>>b;
        	if(mp[a][b]<1000000) cout<<mp[a][b]<<endl;
        	else cout<<"connection impossible"<<endl;
            
		}
    }
    return 0;
}
