#include<bits/stdc++.h>
using namespace std;
int n,m;
void read(int &x){
	int f=1; x=0; char c=getchar();
	for(;c<'0'||c>'9';c=getchar()) if(c=='-') f=-1;
	for(;c>='0'&&c<='9';c=getchar())	x=x*10+c-'0';
	x*=f;
}

struct node{
    string sex;
    string s;
};
map<string,node> up;

int check(string a,string b){
    int fa=1,ok=0;
    for(string sa=a;sa.size();sa=up[sa].s,fa++){
        int fb=1;
        for(string sb=b;sb.size();sb=up[sb].s,fb++){
            if(fa>=5&&fb>=5) return 1;
            if(sa==sb&&(fa<5||fb<5)) return 0;
        }
    }
    return 1;
}

int main(){
    read(n);
    for(int i=1;i<=n;i++){
        string a,b;
        cin>>a>>b;
        int len=b.size()-1;
        if(b[len]=='f') up[a]=(node){"f",""};
        else if(b[len]=='m') up[a]=(node){"m",""};
        else if(b[len]=='n') up[a]=(node){"m",b.substr(0,len-3)};
        else up[a]=(node){"f",b.substr(0,len-6)};
    }
    read(m);
    for(int i=1;i<=m;++i){
        string a,b,c,d;
        cin>>a>>b>>c>>d;
        if(up.find(a)==up.end()||up.find(c)==up.end()) cout<<"NA\n";
        else if(up[a].sex==up[c].sex) cout<<"Whatever\n";
        else if(check(a,c)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
