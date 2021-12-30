#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct people{
    string name;
    int score;
};
bool cmp(people p1,people p2){
    if(p1.score>p2.score) return true;
    else if(p1.score<p2.score) return false;
    else if(p1.name<p2.name) return true;
    else return false;
}
int main(){
    int n;
    cin >> n;
    people a[n];
    for(int i=0;i<n;i++) cin >> a[i].name >> a[i].score;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) cout << a[i].name << " " << a[i].score<< endl;
    return 0;
}