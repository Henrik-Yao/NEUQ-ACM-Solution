#include<iostream>
using namespace std;

long long fx[45];

int main()
{
    fx[1] = fx[2] = 1;
    for(int i = 3; i <= 40; ++i)
    {
       fx[i] = fx[i - 1] + fx[i - 2]; 
    }
        
    int T; 
    cin>>T;
    fx[1]=0;
    while(T--)
    {
        int n;
        cin>>n;
        cout<<fx[n]<<"\n";
    }
    return 0;
}