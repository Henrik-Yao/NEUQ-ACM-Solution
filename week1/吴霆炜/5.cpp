#include <bits/stdc++.h>
using namespace std;

const int max_N = 1e5 + 5;
struct people{
   int dir;
   string name; 
}p[max_N];


int main()
{
    int n,m,temp = 1;
    cin>>n>>m;
    int i;
    for(i = 1;i <= n;i++){
        cin>>p[i].dir>>p[i].name;
    }
    while(m--){
        int num,pos;
        cin>>pos>>num;
        if(pos == p[temp].dir){
            temp = (temp - num + n) % n;
        }
        else{
            temp = (temp + num) % n;
        }
    }
    cout<<p[temp].name;
    return 0;
}
