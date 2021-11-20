#include<bits/stdc++.h>
#define N (int)1e8
using namespace std;
int p(int n){
    for (int i = 2; i <= sqrt(n); i++)
    {
        if(n%i==0)return 1;
    }
    return 0;
}

void f(int n){
    if(n%2==0)cout<<"2"<<endl;
    else if(!p(n))cout<<"1"<<endl;
    else if(!p(n-2))cout<<"2"<<endl;
    else cout<<"3"<<endl;
}

int main(){
    int count;
    cin>>count;
    for (int i = 0; i < count; i++)
    {
        int t;
        cin>>t;
        f(t);
    }
    system("pause");
    return 0;
}