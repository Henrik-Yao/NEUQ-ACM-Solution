### **求解区间覆盖问题**

将区间按最右端大小排序，再把从第一个开始，每个与前一个不重合的区间计数，得出答案

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,space1[10001],space2[10001],ans;
	cin>>n>>m;
    if(n==1){cout<<1;return 0;}
	for(int i=0;i<n;i++)
	cin>>space1[i];
	sort(space1,space1+n);
	ans=space1[n-1]-space1[0]+1;
	for(int i=1;i<n;i++)
	space2[i-1]=space1[i]-space1[i-1]-1;
	sort(space2,space2+n-1);
	for(int i=1;i<=m;i++)
	ans-=space2[n-i];
	cout<<ans;
	return 0;
}
```

### **铺满方格**

递推算法，一个长方形可以看做末尾由一个，两个，三个方块组成。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n,p[51],ans;
	p[1]=1;
	p[2]=2;
	p[3]=4;
	for(int i=4;i<=50;i++)
	p[i] = p[i-1]+p[i-2]+p[i-3];
	while(cin>>n)
	ans=p[n],cout<<ans<<endl;
	return 0;
}
```

