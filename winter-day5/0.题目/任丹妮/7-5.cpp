#include <bits/stdc++.h>
using namespace std;
struct person{
    char sex;
    string father;
};
map<string,person>people;
bool coancestor(string a,string b){
    int i=1,j;
    for(string A=a;!A.empty();A=people[A].father,i++){
        j=1;
        for(string B=b;!B.empty();B=people[B].father,j++)
            if(i>4&&j>4) break;
            else if(A==B&&(i<5||j<5)) return false;
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        string a,b;
        cin>>a>>b;
        if(b.back()=='n') people[a]={'m',b.substr(0,b.size()-4)};
        else if(b.back()=='r') people[a]={'f',b.substr(0,b.size()-7)};
        else people[a].sex=b.back();
    }
    int m;
    cin>>m;
    while(m--){
        string a,str,b;
        cin>>a>>str>>b>>str;
        if(people.find(a)==people.end()||people.find(b)==people.end()) cout<<"NA"<<endl;
        else if(people[a].sex==people[b].sex) cout<<"Whatever"<<endl;
        else cout<<(coancestor(a,b) ? "Yes":"No")<<endl;
    }
}
