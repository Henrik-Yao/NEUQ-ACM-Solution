#include<bits/stdc++.h>
using namespace std;
#define N 100
int s[N];
int n;
void temp(int a,int b)
{
    int t;
    t = s[a];
    for (int i = a ; i > b; i--)
    {
        s[i] = s[i-1]; 
    }
    s[b] = t;
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        cout<<s[i];
        if(i!=n-1)cout<<" ";
    }
    cout<<endl;
}
int main(){
    while(cin>>n){
    for(int i = 0; i < n; i++)
    {
        cin>>s[i];
    }
    for (int i = 1; i < n; i++)
    {
        int k = i - 1;
        while(k>=0){
            if(s[i]>=s[k]){
                break;
            }
            else k--;
        }
        temp(i,k+1);
        print();
    }
    }
    return 0;
}

