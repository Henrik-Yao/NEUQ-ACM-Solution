#include<iostream>
#include<deque>
using namespace std;
deque<int>q;
int n,m,k,x;
int a[2];
int main(){
    scanf("%d%d%d",&n,&m,&k);
    a[0] = m;
	a[1] = k;
    bool single = true,first = false;
    int sum = 0;
    for(int i = 2;i <= n;i++)
	q.push_back(i);
    q.push_back(1);
    while(!q.empty()){
        if(single){
            if(!first){
            x = q.back();
            q.pop_back();
            }
            sum++;
            if(sum == a[0]){
                sum = 0;
                printf("%d ",x);
                single = false;
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
            sum++;
            if(sum == a[1]){
                sum = 0;
                printf("%d ",x);
                single = true;
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
    cout<<endl;
    return 0;
}

