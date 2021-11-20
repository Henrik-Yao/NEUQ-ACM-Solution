#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
int n,e,a[51],b[51];
bool number[20005];
vector<int>xiang[20005];
void sr(){
	cin>>n>>e;
	for(int i=0;i<n;i++)
	number[i]=1;
	for(int i=0;i<e;i++){
		cin>>a[i]>>b[i];
		xiang[a[i]].push_back(b[i]);	
	}
	for(int i=0;i<e;i++)
	sort(xiang[a[i]].begin(),xiang[a[i]].end());
}
void dfs(int begin){
    cout<<begin<<" ";number[begin]=0;
	for(int i=0;i<xiang[begin].size();i++){
		if(number[xiang[begin][i]])dfs(xiang[begin][i]);
	}
    return;
}
int main(){
	sr();
    for(int i=0;i<n;i++){
        if(number[i]) dfs(i);
    }    
	return 0;
}
