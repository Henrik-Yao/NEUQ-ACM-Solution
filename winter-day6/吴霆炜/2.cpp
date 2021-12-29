#include <bits/stdc++.h>
using namespace std;
#define maxn 21

struct people{
    string name;
    int grade;
}p[maxn];

bool cmp(people a,people b){
    if(a.grade == b.grade)
    return a.name < b.name;
    return a.grade > b.grade;
}

int main(){
    int n;
    cin>>n;
    for(int i = 0;i < n;i++){
        cin>>p[i].name>>p[i].grade;
    }
    sort(p,p + n,cmp);
    for(int i = 0;i < n;i++){
        cout<<p[i].name<<' '<<p[i].grade<<endl;
    }
    return 0;
}