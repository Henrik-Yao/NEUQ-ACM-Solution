# solution

### **求解区间覆盖问题**

首先每个区间都用一条线段覆盖，然后合并

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    int a[n];
    for(int i=0;i<n;i++)
    cin>>a[i];
    sort(a,a+n);
    int b[n];
    for(int i=0;i<n/1;i++)
    b[i]=a[i+1]-a[i]-1;
    int s;
    s=a[n-1]-a[0]+1;
    sort(b,b+n-1);
    for(int i=0;i<m-1;i++)
    s-=b[n-2-i];
    cout<<s;
    return 0;
}
```

### 铺满方格

找规律的题，long long ！

```c++
#include<bits/stdc++.h>
using namespace std;
long long a[55];
long long shu(int n)
{
    if(a[n])return a[n];
    if(n==1)return 1;
    else if(n==2)return 2;
    else if(n==3)return 4;
    else return a[n]=shu(n-1)+shu(n-2)+shu(n-3);
}
int main()
{
    int n;
    while(cin>>n)
    cout<<shu(n)<<"\n";
    //puts("%lld",shu(n));
    return 0;
}
```

