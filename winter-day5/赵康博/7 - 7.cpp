#include<bits/stdc++.h>
using namespace std;
#define N 1000000
int f[N];
int n,m;
bool judge(int x)
{
    int num = 1;
    int left = 0,right;
    for(int i = 1; i < n; i++)
    {
        right = i;
        if(f[right] - f[left] >= x){
            left = right;
            num++;
        }
    }
    if(num >= m)return true;
    else return false;
}

int main()
{
    cin>>n>>m;
    int max;
    for(int i = 0; i < n; i++)cin>>f[i];
    sort(f,f + n);
    int l = 1;
    int r = f[n-1] - f[0];
    while (l <= r)
    {
        int mid = (l+r)/2;
        if(judge(mid))
        {
            max = mid;
            l = mid + 1;
        } else
        {
            r = mid - 1;
        }
    }
    cout<<max;
    return 0;
}
