###  **直接插入排序**

两层循环

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(cin>>n){
		int a[101];
		for(int i=0;i<n;i++)
		cin>>a[i];

		for(int i=1;i<n;i++){
			for(int j=i-1;j>=0;j--){
				
				if(a[j]>a[j+1])swap(a[j],a[j+1]);
			}
			for(int j=0;j<n;j++){
				cout<<a[j];
				if(j<n-1)cout<<" ";
			}
			
			cout<<endl;
		}
	}
	return 0;
}
```

###  **成绩排序**

成绩和名字分别排序，不然会出错

```c++
#include<bits/stdc++.h>
using namespace std;
struct student{
	char name[10];
	int c;
}; 
int main(){
	struct student students[50];
	int n;
	cin>>n;
	for (int i=0;i<n;i++){
		cin>>students[i].name>>students[i].c;
	}
	int max;
	for (max=0;max<n-1;max++){
	for (int i=max+1;i<n;i++){
		if (students[max].c<students[i].c){
			swap(students[i],students[max]);
		}
		if(students[max].c==students[i].c){
			if(students[max].name<students[i].name)
			swap(students[i],students[max]);
		}
	}
	}
	for (int i=0;i<n;i++){
		printf("%s %d",students[i].name,students[i].c);
		if(i!=n-1){
			cout<<endl;
		}
	}
	return 0;
} 
```

### **统计工龄**

排序，计数

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a[100001],b[100001];
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i];
	sort(a,a+n);
	for(int i=0;i<n;i++)
	b[i]=0;
	for(int i=0;i<n;i++){
		b[a[i]]++;
	}
	for(int i=0;i<n;i++)
	if(a[i]!=a[i-1])cout<<a[i]<<":"<<b[a[i]]<<endl;
	return 0;
}
```

### **最接近神的人**

```c++
#include <bits/stdc++.h>
using namespace std;
long int ans=0,a[500001],b[500001];
void msort(int l,int r){
    if(l==r) return;
    int mid=(l+r)/2;
    msort(l,mid);
    msort(mid+1,r);
    int i=l,j=mid+1,k=l;
    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            b[k]=a[i];k++;i++;
        }
		else{
            b[k]=a[j];k++;j++;
            ans+=mid-i+1;
        }
    }
 
    while(i<=mid){
        b[k]=a[i];k++;i++;
    }
    while(j<=r){
        b[k]=a[j];k++;j++;
    }
    for(int i=l;i<=r;i++) a[i]=b[i];
}
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    msort(1,n);
    cout<<ans;
}
```

### **堆排序**

求最大堆，把最大值放在队尾，重复

```c++
#include<bits/stdc++.h>
using namespace std;
int n,N=1000;
int a[10000];
void f3(int a[],int s,int m){
 	int x=a[s];
 	for(int j=2*s;j<=m;j*=2){
  		if(j<m && a[j]<a[j+1]) j++;
  		if(x>=a[j])  break;
  		a[s]=a[j];
  		s=j;
 	}
 	a[s]=x;
}
void f2(int a[]){
 	for(int i=n/2;i>0;i--){
  		f3(a,i,n);
 	}
} 
void f1(int a[]){
 	f2(a);
 	for(int i=1;i<=n;i++)
  		cout<<a[i]<<" ";
 	cout<<endl;
 	for(int i=n;i>1;i--){
  		swap(a[1],a[i]);   
  		f3(a,1,i-1);
  		for(int i=1;i<=n;i++)
   			cout<<a[i]<<" ";
  		cout<<endl;
 	}
}
int main(){
 	cin>>n;
 	for(int i=1;i<=n;i++)
  		cin>>a[i];
 	f1(a);
 	return 0;
}
```

### **快速排序**

类似二分

```c++
#include<bits/stdc++.h>
using namespace std;
int n,a[1001],b[1001];
void f(int l,int r){
	if(l<r){
	int t=a[(l+r)/2];
	int m=l,p=l;
	b[l]=t;
	for(int i=l;i<=r;i++){
	if(a[i]<t){
		for(int j=r;j>p;j--)
		b[j]=b[j-1];
		b[p]=a[i];
        p++;m++;
	}
	if(a[i]>t){m++;b[m]=a[i];}
}
	for(int j=0;j<n;j++){
        a[j]=b[j];
        cout<<b[j]<<" "; 
    }
	cout<<endl;
	f(l,p-1);
	f(p+1,r);
	}
}
int main(){
	cin>>n;
	for(int i=0;i<n;i++)
	cin>>a[i],b[i]=a[i];
	f(0,n-1);
	return 0;
}
```

