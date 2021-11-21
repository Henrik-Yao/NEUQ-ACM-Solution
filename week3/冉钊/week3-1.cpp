#include<bits/stdc++.h>
using namespace std;
int m;
int a[101]={0};//city是否安全的数组
queue<int> brother[101];//记录公路连接的city；
int bfs(int s,int d){
    if(brother[s].empty()) return 0;
    while(!brother[s].empty()){
        int temp=brother[s].front();
        brother[s].pop();
        if( (a[temp]==1)&&(temp==d) ) return 1;

        if(a[temp]==1&&temp!=d){
            if(bfs(temp,d)) return 1;
            else return 0;
        }
        if(a[temp]==0) continue;
    }
    return 0;
}
int main(){
    int n,k,s,d;
    cin>>m>>n>>k;
    while(n--){
        int i;
       cin>>i;
       a[i]=1;//记录安全city；
    }
    while(k--){
    int city1,city2;
    cin>>city1>>city2;
    brother[city1].push(city2);
    brother[city2].push(city1);
    }
    cin>>s>>d;//当前city s与目标city d；
    if(a[d]==0)
    cout<<"The city "<<d<<" is not safe!";
    else{
       if(bfs(s,d)==1)
       cout<<"The city "<<d<<" can arrive safely!";
       else
       cout<<"The city "<<d<<" can not arrive safely!";

    }
    

    return 0;
}