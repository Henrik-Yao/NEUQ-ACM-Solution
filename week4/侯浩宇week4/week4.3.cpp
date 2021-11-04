#include<bits/stdc++.h>
using namespace std;
int visit[10000000];  
void Prime(int n){
    for(int i=2;i<=n;i++)
	visit[i]=0;         
    visit[0] = visit[1] = 1;  
    for (int i=2;i<=sqrt(n);i++) {
        if (!visit[i]) {         
            for (int j=i*i;j<=n;j+=i) { 
                visit[j] = 1;
            }
        }
    }
}
int main(){
	int n,ans=0;
	cin>>n;
	Prime(n);
	for(int i=2;i<=n;i++){
		if(!visit[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
