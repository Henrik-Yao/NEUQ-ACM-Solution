#include<iostream>
#include<vector> 
using namespace std;
const int N = 1e4 + 1;
vector<vector<int > >cp;
int n,m;
int num[N] = {0}; 
int tem[N];
void print();
int main(){
    int a,b;
    cin>>n>>m;
    cp.resize(n + 1);
    while(m--){
	
        cin >> a >> b;
        cp[a].push_back(b);
        cp[b].push_back(a);
        num[a]++;
        num[b]++;
    }
    int _ = 0,cnt;
    cin>>_;
    while(_--){
        for(int i = 1; i <= n; i++) tem[i] = num[i];
        cin >> cnt;
