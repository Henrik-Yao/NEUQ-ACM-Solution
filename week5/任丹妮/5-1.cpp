#include <bits/stdc++.h>
#define max 10001
using namespace std;
typedef struct {
    char gender;
    string father,mother;
}ID;
map<string,ID>id;
map<string,int>vis1,vis2;
bool coancestor(string a,int count){
    if(!vis1[a]) return false;
    if(count==5) return false;
    int flag1=0,flag2=0;
    if(!vis2[id[a].mother]){
        if(id[a].mother!="-1") vis2[id[a].mother]=1;
        if(vis1[id[a].mother])
            if(coancestor(id[a].mother,count+1)) return true;
            else flag1=1;
        else flag1=1;
    }
    else return true;
    if(!vis2[id[a].father]){
        if(id[a].father!="-1") vis2[id[a].father]=1;
        if(vis1[id[a].father])
            if(coancestor(id[a].father,count+1)) return true;
            else flag2=1;
        else flag2=1;
    }
    else return true;
    if(flag1&&flag2) return false;
}
int main(){
    int N;
    cin>>N;
    while(N--){
        string i;
        cin>>i;
        cin>>id[i].gender>>id[i].mother>>id[i].father;
        vis1[i]=1;
        id[id[i].father].gender='F';
        id[id[i].mother].gender='M';
    }
    int k;
    cin>>k;
    while(k--){
        string p1,p2;
        int level=1;
        cin>>p1;
        cin>>p2;
        if(id[p1].gender==id[p2].gender) {
            cout<<"Never Mind";
        }
        else {
            vis2[p1]=1;
            coancestor(p1,level);
            vis2[p2]=1;
            if(coancestor(p2,level)) cout<<"No";
            else cout<<"Yes";
        }
        if(k!=0) cout<<endl;
        vis2.erase(vis2.begin(),vis2.end());
    }
    return 0;
}
