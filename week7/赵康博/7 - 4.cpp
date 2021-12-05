#include <bits/stdc++.h>

using namespace std;
int main()
{
    int n;
    cin>>n;
    for(int k = 0; k < n; k++)
    {
        int m;
        cin>>m;
        int f[m];
        for(int i = 0; i < m; i++)cin>>f[i];
        int s[m];
        int max1 = 0;
        for(int i = 0; i < m; i++)s[i] = 1;
        for(int i =0; i < m; i++){
            for(int j = 0; j < i; j++){
                if(f[i]>f[j])s[i] = max(s[i],s[j]+1);
            }
            max1 = max(max1,s[i]);
        }
        cout<<max1<<endl;
    }
    system("pause");
    return 0;
}