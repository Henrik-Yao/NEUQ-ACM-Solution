#include <iostream>
using namespace std;
bool num[10000001];
int flag[10000001];
int main()
{
    int n, count = 0;
    cin>>n;
    num[0] = 1;
    num[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if(num[i]==0)
        {
            flag[count]=i;
            count++;
        }
        for(int j=0;i*flag[j]<=n && j<count;j++)
        {
            num[i*flag[j]]=1;
            if(i%flag[j]==0) break;
        }
    }
    cout << count;
    return 0;
}