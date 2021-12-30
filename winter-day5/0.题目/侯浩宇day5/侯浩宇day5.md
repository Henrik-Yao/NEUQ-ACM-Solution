### **相邻数对**

双重循环

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m=0,a[1001];
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=0;i<n;i++)
	for(int j=i+1;j<n;j++)
	if(a[j]-a[i]==1)m++;
	cout<<m<<endl;
	return 0;
}

```

### **两个有序序列的中位数**

合并，第（1+n）/2个

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[200001],b[200001],m=0;
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	for(int i=0;i<n;i++)
	cin>>a[n+i];
	sort(a,a+2*n);

	cout<<a[n-1];
	return 0;
}
```

### **二分查找**

小了向右，大了向左

```c++
#include<bits/stdc++.h>
using namespace std;
int n,a[1001],x,ans1=-1,ans2=0;
void f(int l,int r){
	if(l<=r){
	ans2++;
	if(x==a[(l+r)/2]){
		ans1=(l+r)/2;
		return ;
	}
	else if(x>a[(l+r)/2])
	f((l+r)/2+1,r);
	else 	f(l,(l+r)/2-1);	
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	cin>>x;
	f(0,n-1);
	cout<<ans1<<endl<<ans2<<endl;
	return 0;
}
```

### **7-6 二分查找**

查询次数赋处值0

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1001],x,ans1;
void f(int l,int r){
	if(l<=r){
	if(x==a[(l+r)/2]){
		ans1=(l+r)/2;
		return ;
	}
	else if(x>a[(l+r)/2])
	f((l+r)/2+1,r);
	else 	f(l,(l+r)/2-1);	
	}
}
int main(){
	while(cin>>n){
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a,a+n+1);
	for(int i=1;i<=n;i++){
		cout<<a[i];
		if(i<n)cout<<" ";
	}
	
	cout<<endl;
	cin>>m;
	for(int i=0;i<m;i++){
	cin>>x;
	ans1=0;
	f(1,n);	
	cout<<ans1;
	if(i<m-1)cout<<" ";
	}
	cout<<endl;	
	}
	return 0;
}
```

### **愤怒的牛**

从最小的距离找起，若该距离满足条件，则增大距离，再次尝试，直到找到最大的最小距离

```c++
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000001],mid;
int check(int d){
	int s=d+a[0];
	int sum=1;
	for(int i=1;i<n;i++){
		if(a[i]<s)continue;
		s=d+a[i];
		sum++;
	}
	return sum>=m;
}
int main(){
	cin>>n>>m;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	int l=0,r=a[n-1]-a[0];
	while(l<=r){
		mid=(r+l)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<r;
	return 0;
}
```

