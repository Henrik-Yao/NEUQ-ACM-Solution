#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3;
char c;
int xu,fu,mu,xu1,xu2,flag,cun[100010],xing[100010],n,m;
vector<int>vec[100010];
vector<int>marry[100010];
int change(string s){
	int len=s.length(),le=0;
	for(int i=0;i<len;i++){
		if(s[i]!='0'){
			le=i;
			break;
		}
	}
	int ans=0;
	for(int i=le;i<=len-1;i++){
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
}
void dfs(int x,int ceng){
	if(flag==1)return;
	cun[x]++;
	//printf("%d\n",x);
	if(cun[x]==2){
		flag=1;
		//printf("gonggongzuxian %d\n",x);
		return;
	}
	if(ceng==5)return;
	for(int i=0;i<vec[x].size();i++){
		dfs(vec[x][i],ceng+1);
	}
}
bool pan(int x,int y){
	for(int i=0;i<marry[x].size();i++){
		if(marry[x][i]==y)return true;
	}
	return false;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		cin>>s1>>c>>s2>>s3;
		xu=change(s1);
		fu=change(s2);
		mu=change(s3);
		if(c=='M')xing[xu]=1;
		else xing[xu]=2;
		xing[fu]=1;
		xing[mu]=2;
		if(fu>=0)
		vec[xu].push_back(fu);
		if(mu>=0)
		vec[xu].push_back(mu);
		if(fu>=0&&mu>=0){
			marry[fu].push_back(mu);
			marry[mu].push_back(fu);
		}
	}
	scanf("%d",&m);
	while(m--){
		cin>>s1>>s2;
		xu1=change(s1);
		xu2=change(s2);
		if(pan(xu1,xu2)){
			printf("Yes");
			if(m!=0)printf("\n");
			continue;
		}
		if((xing[xu1]==1&&xing[xu2]==1)||(xing[xu1]==2&&xing[xu2]==2)){
			printf("Never Mind");
			if(m!=0)printf("\n");
			continue;
		}
		memset(cun,0,sizeof(cun));
		flag=-1;
		dfs(xu1,1);
		//puts("233");
		dfs(xu2,1);
		if(flag!=-1)printf("No");
		else printf("Yes");
		if(m!=0)printf("\n");
	}
	return 0;
}
