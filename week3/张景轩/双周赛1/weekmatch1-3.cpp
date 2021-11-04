#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    long long col[100];
    int n;
    col[0] = 1;
    for(int i=1;i<=35;i++)
    {
        col[i] = col[i-1] * 3;
    }
    while(cin>>n)
    {
        cout<<col[n] - 1<<"\n";
    }
    return 0;
}

//递归，与初等相比，需要多一层有b到c的过程