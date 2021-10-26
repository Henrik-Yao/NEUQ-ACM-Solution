#include<bits/stdc++.h>
using namespace std;

int f[1005];
int main()
{
    int n = 0;
    cin >> n;
    f[1] = 1;
    f[2] = 2;
    f[3] = 2;
    
    for(int i = 4;i <= n; i++)
    {
        int sum = 1;
        for(int j = 1; j < n;j++)
        {
            if(i % j == 0) 
                sum += f[j];
        }
        f[i] = sum;
    }
    cout<<f[n]<<endl;
}
