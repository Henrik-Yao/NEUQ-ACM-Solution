#include<bits/stdc++.h>
using namespace std;
int flag,len,maxx,dep[1010];
string s1,s2;
char c;
struct node{
	char l,r;
}a[1010];
bool hefa(int l1,int r1,int l2,int r2){
	int pan[210]={0};
	for(int i=l1;i<=r1;i++){
		pan[s1[i]]=1;
	}
	for(int i=l2;i<=r2;i++){
		if(pan[s2[i]]!=1)return false;
	}
	return true;
}
void print(char c){
	cout<<c;
	if(a[c].l!='0')print(a[c].l);
	if(a[c].r!='0')print(a[c].r);
}
char dfs(int l1,int r1,int l2,int r2){
	//printf("%d %d %d %d\n",l1,r1,l2,r2);
	if(!hefa(l1,r1,l2,r2)){
		flag=1;
		return '0';
	}
	//puts("233");
	if(l1==r1&&l2==r2){
		a[s1[l1]].l='0';
		a[s1[l1]].r='0';
		return s1[l1];
	}
	char root=s1[r1];
	int mid;
	for(int i=l2;i<=r2;i++){
		if(s2[i]==root){
			mid=i;
			break;
		}
	}
	if(mid-1+l1-l2<l1||mid-1<l2)a[root].l='0';
	else a[root].l=dfs(l1,mid-1+l1-l2,l2,mid-1);
	if(r1-1<mid+r1-r2||r2<mid+1)a[root].r='0';
	else a[root].r=dfs(mid+r1-r2,r1-1,mid+1,r2);
	return root;
}
void depdfs(char c){
	maxx=max(maxx,dep[c]);
	dep[a[c].l]=dep[c]+1;
	dep[a[c].r]=dep[c]+1;
	if(a[c].l!='0'){
		depdfs(a[c].l);
	}
	if(a[c].r!='0'){
		depdfs(a[c].r);
	}
}
int main(){
	while(cin>>s1>>s2){
		memset(dep,0,sizeof(dep));
		maxx=-1;
		//cout<<s1<<s2;
		flag=0;
		len=s1.length();
		dfs(0,len-1,0,len-1);
		if(flag==1){
			cout<<"INVALID"<<endl;
		}
		else{
			dep[s1[len-1]]=0;
			depdfs(s1[len-1]);
			cout<<maxx<<endl;
			print(s1[len-1]);
			cout<<endl;
		}
		/*while(cin>>c)
		cout<<a[c].l<<' '<<a[c].r<<endl;*/
	}
	return 0;
}
