#include <bits/stdc++.h>
using namespace std;
const int _=2e5+7;
int read() {
    int x=0,f=1;char s=getchar();
    for(;s>'9'||s<'0';s=getchar()) if(s=='-') f=-1;
    for(;s>='0'&&s<='9';s=getchar()) x=x*10+s-'0';
    return x*f;
}
map<string, int> mp;
int p[_],cnt[_],dx[_],dy[_],male_famale[_]; 
string ming[_], name[_];
bool pd(int x, int y) {
    memset(cnt,0,sizeof(cnt));
    memset(dx,0,sizeof(dx));
    memset(dy,0,sizeof(dy)); 
    cnt[x]=1,cnt[y]=1;
    while(p[x] != -1){ 
        cnt[p[x]]++;
        dx[p[x]] = dx[x] + 1; 
        if(p[x] == y) return 0; 
        x = p[x];
    }
    while(p[y] != -1){
        cnt[p[y]]++;
        dy[p[y]] = dy[y] + 1;
        if(cnt[p[y]] > 1){ 
            if(dy[p[y]]>=4 && dx[p[y]] >= 4) return 1;
            else return 0;
        }
        y = p[y];
    }
    return 1;
}
int main(){
    int n,m;
    cin>>n;
    getchar();
    for(int i=1; i<=n; i++){
        cin>>ming[i]>>name[i];
        mp[ming[i]]=i;
        int t=name[i].size()-1;
        if(name[i][t]=='m'||name[i][t]=='n') male_famale[i]=1;
        else male_famale[i]=-1;  
        
        string s;
        if(name[i][t]=='n'){
            for(int j=0; j<t-3; j++) s+=name[i][j];
        }else if(name[i][t]=='r'){
            for(int j=0; j<t-6; j++) s+=name[i][j];
        }
        name[i]=s;  
    }   
    memset(p,-1,sizeof(p));
    for(int i=1; i<=n; i++)
        if(mp[name[i]]>0) p[i]=mp[name[i]];
    cin>>m;
    string s1,s2,s3,s4;
    while(m--){
        cin>>s1>>s2>>s3>>s4;
        int x=mp[s1],y=mp[s3];  
        if(!male_famale[x]||!male_famale[y]) cout<<"NA"<<"\n";
        else if(male_famale[x]==male_famale[y])cout<<"Whatever"<<"\n";
        else{
            if(pd(x, y)) cout<<"Yes"<<"\n";
            else cout<<"No"<<"\n";          
        }           
    } 
    return 0;
} 