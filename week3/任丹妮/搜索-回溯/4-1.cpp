#include <bits/stdc++.h>
using namespace std;
queue<int> q[101];
int safe[101]={0};
int bfs(int start,int end){
    if(q[start].empty()) return 0;
    while(!q[start].empty()) {
        int p=q[start].front();
        q[start].pop();
        if(safe[p]==1&&p==end) return 1;
        else if(safe[p]==1) {
			while(!q[p].empty())
            {
                q[start].push(q[p].front());
				q[p].pop();
            }
        }
        else if(safe[p]==0&&p!=end) continue;
    }
    return 0;
}
int main(){
    int m,n,k;
    cin>>m>>n>>k;
    while(n--){
        int a;
        cin>>a;
        safe[a]=1;
    }
    while(k--){
        int b,c;
        cin>>b>>c;
        q[b].push(c);
        q[c].push(b);
    }
    int start,end;
    cin>>start>>end;
    if(safe[end]==0) cout<<"The city "<<end<<" is not safe!";
    else {
        if(bfs(start,end)==1) cout<<"The city "<<end<<" can arrive safely!";
        else cout<<"The city "<<end<<" can not arrive safely!";
    }
    return 0;
}
