 #include<bits/stdc++.h>
using namespace std;
queue<int>q;
int main(){
	 int m,n,k,i,s,ss;
	 int yn=0;
	 cin>>m>>n>>k;
	 int aq[m];
	 int visited[m];
	 for(i=0;i<m;i++){
	 	visited[i]=0;
         aq[i]=0;
	 }
	 vector<int>a[m];
	 for(i=0;i<n;i++){
	 	cin>>s;
	 	aq[s]=1;
	 }
	 for(i=0;i<k;i++){
	 	cin>>s>>ss;
	 	a[s].push_back(ss);
	 	a[ss].push_back(s);
	 }
	 int sz,md;
	 cin>>sz>>md;
	 q.push(sz);
	 visited[sz]=1;
	 //if(aq[sz]==0)cout<<"The city "<<md<<" can not arrive safely!";
	 if(aq[md]==0)cout<<"The city "<<md<<" is not safe!";
	 else {
	 while(!q.empty()){
	 	if(yn==1){
	 		break;
		 }
	    int	u=q.front();
	 	q.pop();
         int sizee=a[u].size();
	 	for(i=0;i<sizee;i++){
	 		if(a[u][i]==md){
	 			yn=1;
	 			break;
			 }
	 		if(visited[a[u][i]]==0&&aq[a[u][i]]==1){
	 			q.push(a[u][i]);
	 			visited[a[u][i]]=1;
			 }
		 }
	 }
	 if(yn==0)cout<<"The city "<<md<<" can not arrive safely!";
	 else cout<<"The city "<<md<<" can arrive safely!";
}
	return 0;
}
