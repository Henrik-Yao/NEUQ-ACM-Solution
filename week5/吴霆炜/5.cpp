#include <bits/stdc++.h>
using namespace std;
#define maxn 500010

bool vis[maxn];
int k[maxn];
bool flag;
int n;
void dfs(int Floor){
    if(flag)
    return;
    if(k[Floor] == 0){
    flag = true;
    return;
    }
    for(int sign = -1;sign <= 1;sign += 2){
        int dist = sign * k[Floor] + Floor;
        if(dist >= 1 && dist <= n && !vis[dist]){
				vis[dist] = true;
                dfs(dist);
                vis[dist] = false;
			}
		}
}

int main(){
	int sta;
	cin>>n;
	for(int i = 1;i <= n;i++)cin>>k[i];
    cin>>sta;
    sta++;
    vis[sta] = true;
	dfs(sta);
    if(flag)
    cout<<"True";
    else
	cout<<"False";
	return 0;
}