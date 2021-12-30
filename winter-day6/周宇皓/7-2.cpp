#include<bits/stdc++.h>
using namespace std;
struct person{
    string name;
    int score;
}a[10001];
bool cmp(person a,person b){
    if(a.score!=b.score)
    return a.score>b.score;
    else
    {
        for(int i = 0; i < a.name.size()|| i < b.name.size(); i++)
            if(a.name[i]!=b.name[i])
                return a.name[i]<b.name[i];
    }
}
int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i].name >> a[i].score;
    sort(a,a+n,cmp);
    for(int i = 0; i < n-1; i++) cout<<a[i].name<<" "<<a[i].score<<endl;
    cout<<a[n-1].name<<" "<<a[n-1].score;
}
