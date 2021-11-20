#include<bits/stdc++.h>
using namespace std;
#define file_in freopen("in.txt","r",stdin)
#define file_out freopen("out.txt","w",stdout)
int n,location;
int a[50001];
bool flag,visited[50001];
void solution(int x){
    visited[x]=1;
    if(!a[x]){
		flag=1;
		return;
	}
    if(x-a[x]>=1 && !visited[x-a[x]])
		solution(x-a[x]);
    if(x+a[x]<=n && !visited[x+a[x]])
		solution(x+a[x]);
}
int main(){
	ios::sync_with_stdio(false);
	file_in;
	file_out;
    cin>>n;
    for(int i=1;i<=n;i++)
		cin>>a[i];
	cin>>location;
	location++;
    solution(location);
    if(flag) cout<<"True";
    else cout<<"False";
    return 0;
}
