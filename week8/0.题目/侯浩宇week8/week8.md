### **7-1 最少失约**

将右端按大小排序，从左到右，相互隔离的计数。

```c++
#include<bits/stdc++.h>
using namespace std;
int t,n;
struct ss{
    int beginn;
    int endd;
}number[101];
bool px(ss a,ss b){
	return a.endd<b.endd;
}
void anss(){
	
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>number[i].beginn>>number[i].endd;
	sort(number,number+n,px);
	int ans=1;
	int j=0;
	for(int i=0;i<n;i++){
		if(number[i].beginn>=number[j].endd){
			j=i;
			ans++;
		}
	}
	cout<<n-ans<<endl;
} 
int main(){
	cin>>t;
	while(t--){
		anss();
	} 
	return 0;
}
```

### **7-2 跳一跳**

从终点开始，从左往右寻找可到达改点的点，再对该点进行上述运算。

```c++
#include<bits/stdc++.h>
using namespace std;
int n,a[1000001],minn=2147483646,ans=0;
void dt(int space){
	if(space==0){
		minn=min(minn,ans);
		return;
	}
	for(int i=0;i<space;i++){
		if(a[i]>=space-i){
		ans++;dt(i);break;	
		}
	}
	return;
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	dt(n-1);
	cout<<minn;
	return 0;
}
```

