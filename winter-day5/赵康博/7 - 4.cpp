#include<bits/stdc++.h>
using namespace std;
#define N 100
int f[N];
int n,m;

int main()
{
    cin>>n;
    for(int i = 0; i < n; i++)cin>>f[i];
    cin>>m;
    int num = 0,x = -1;
    int l = 0;
    int r = n - 1;
    while (l <= r)
    {
        int mid = (l+r)/2;
        if(f[mid] == m)
        {
            num++;
            x = mid;
            break;
        }
        else if(f[mid] > m){
            r = mid - 1;
            num++;
        }
        else {
            l = mid + 1;
            num++;
        }
    }
    cout<<x<<endl<<num;
    return 0;
}
