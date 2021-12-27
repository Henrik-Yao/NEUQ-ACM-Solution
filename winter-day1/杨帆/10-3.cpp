#include<bits/stdc++.h>
using namespace std;
const int N = 1000+10;
int a[N];
int vis[N];

int main(){
    int n,m,k;
    cin >> n >> m >> k;
    int flag = 1,s = 1,cnt = 0;
    for(int j=1; j<=n ;j++){
    	int i = 0;
        if(flag){
            while(i < m){
            	while(vis[s]){
            		if(--s < 1)     s = n;
				}
				i++;
				if(i == m){
					flag = 0;
					cout << s << " ";
					vis[s] = 1,cnt++;
					do{
						if(--s < 1)     s = n;
					}
					while(vis[s] && cnt < n);
					break;
				}
				if(--s < 1)     s = n;
			}	
        }
        else{
            while(i < k){
            	while(vis[s]){
            		if(++s > n)     s = 1;
				}
				i++;
				if(i == k){
					flag = 1;
					cout << s << " ";
					vis[s] = 1,cnt++;
					do{
						if(++s > n)     s = 1;
					}
					while(vis[s] && cnt < n);
					break;
				}
				if(++s > n)     s = 1;
			}
			
        }
    }
    return 0;
}
