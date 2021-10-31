#include<bits/stdc++.h>
using namespace std;
const int k=105;
int s,d,flag;
vector <int> road[k];
int safe[k],n,m,p,book[k];
void dfs(int x){
		if(flag==1)	return;
    if(x==d){
    		flag = 1;
        printf("The city %d can arrive safely!",d);
        return;
    }
    for(int i = 0;i < road[x].size();i++){
        if(!book[i]){
            book[i]=1;
            dfs(road[x][i]);
            book[i]=0;
        }
    }
}

int main(){
    cin >> n >> m >> p;
    for(int i = 1;i <= m;i++){
        int a;
        cin >> a;
        safe[a] = 1;
    }
    for(int i = 1;i <= p;i++){
        int a,b;
        cin >> a >> b;
        road[a].push_back(b);
        road[b].push_back(a);
    }
    cin>>s>>d;
    if(!safe[d]){
        printf("The city %d is not safe!",d);
        return 0;
    }
    else{
        dfs(s);
        if(flag==0)
        	printf("The city %d can not arrive safely!",d);
    }
    return 0;
}
