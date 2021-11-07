#include <iostream>
using namespace std;
bool num[10000001];
int f[10000001];
int main()
{
    int n;
    int total = 0;
    cin>>n;
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if(num[i]==0)
        {
            f[total]=i;
            total++;
        }
        for(int j=0;i*f[j]<=n && j<total;j++)
        {
            num[i*f[j]]=1;
            if(i%f[j]==0) 
            {
                break;
            }
        }
    }
    cout << total;
    return 0;
}