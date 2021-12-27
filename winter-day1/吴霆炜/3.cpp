#include <bits/stdc++.h>
using namespace std;

deque<int>q;
int n,m,k,x;
int a[2];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    a[0] = m;a[1] = k;
    bool odd = true,first = false;
    int cnt = 0;
    for(int i = 2;i <= n;i++)q.push_back(i);
    q.push_back(1);
    while(!q.empty()){
        if(odd){
            if(!first){
            x = q.back();
            q.pop_back();
            }
            cnt++;
            if(cnt == a[0]){
                cnt = 0;
                printf("%d ",x);
                odd = false;
                x = q.back();
                first = true;
            }
            else{
                if(first){
                    first = false;
                } 
                else
                q.push_front(x);
            }
        }
        else{
            if(!first){
            x = q.front();
            q.pop_front();
            }
            cnt++;
            if(cnt == a[1]){
                cnt = 0;
                printf("%d ",x);
                odd = true;
                x = q.front();
                first = true;
            }
            else{
                if(first){
                    first = false;
                }
                else 
                q.push_back(x);
            }
        }
    }
    puts("");
    return 0;
}