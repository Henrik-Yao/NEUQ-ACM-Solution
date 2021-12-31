#include<bits/stdc++.h>
using namespace std;
struct person{
    char ab;//性别
    int father;
    int mother;
};
bool vst[100001]={0};
struct person id[100001];
int n,k,flag=1,ren;
void dfs(int one,int now){
       if(now>5||one==0||one==-1) return;
       if(vst[one]){
	   flag=0;return;}
       vst[one]=1;
       dfs(id[one].father,now+1);
       dfs(id[one].mother,now+1);
       return;
}//打标记函数
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
       cin>>ren;
       cin>>id[ren].ab;
       cin>>id[ren].father;
       id[id[ren].father].ab='M';//给父母标记性别，不然父母结婚就会被识别为同性！吐了；没想到； 
       cin>>id[ren].mother;
       id[id[ren].mother].ab='F'; 
    }
    cin>>k;
    int one,tow;
    while(k--){
       cin>>one>>tow;
       if(id[one].ab==id[tow].ab){
	    cout<<"Never Mind";}
	    else{
       memset(vst,0,100001);
       flag=1;
       dfs(one,1);
       dfs(tow,1);
       if(flag==1) cout<<"Yes";
       if(flag==0) cout<<"No";
    }
    if(k>=1) cout<<endl;
	}

    return 0;
}