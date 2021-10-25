#### 1.汉诺塔

1->2上一个倒过来2->3上一个

用递归方法解

```c++
#include<bits/stdc++.h>
using namespace std;
int countt=0; 
void move(char a,int n,char c){
  	countt++;
  	cout<<a<<"->"<<c<<endl;
} 
void hanoi(int n,char a,char b,char c){
  	
  	if(n==1)
  	move(a,1,c);
  	else
  	{
  		hanoi(n-1,a,c,b);
  		move(a,n,c);
  		hanoi(n-1,b,a,c); 
	  }
}
int main(void){
  	int n;
  	cin>>n;
	hanoi(n,'a','b','c');
	cout<<countt<<endl;
	return 0;
}
```

#### 2.分而治之

大问题转小问题

```c++
#include<bits/stdc++.h>
using namespace std;
const int N=100001;
int num[N]= {0},temp[N];
int main() {
	int n,m,k,goal,cdn;
	cin>>n>>m;
	vector<vector<int> >cp;
	int a,b;
	cp.resize(n + 1);
	while(m--) {
		cin>>a>>b;
		cp[a].push_back(b);
		cp[b].push_back(a);
		num[a]++;
		num[b]++;
	}
	cin>>k;
	while(k--) {
		int v=n;
		while(v--){
			temp[v+1]=num[v+1];
            
		}
		cin>>cdn;
		while(cdn--) {
			cin>>goal;
			temp[goal]=0;
			for(int i=0; i<cp[goal].size(); i++) {

				temp[cp[goal][i]]--;
			}
		}
		int flag=1;
		for(int i=1; i<=n; i++) {
			if(temp[i]>0)flag=0;
		}
		if(flag==1)cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
```

#### 3.归并排序

排序，在合并，在排序

```c++
#include<bits/stdc++.h>
using namespace std;
int n;
int merge(int c[],int s[],int left,int mid,int right){
	int i,j,k;
	i=left;
	j=mid+1;
	k=left;
	while((i<=mid)&&(j<=right)){
		if(c[i]<=c[j]){
			s[k]=c[i];
			k++;
			i++;		
		}
		else{	
			s[k]=c[j];
			k++;
			j++;
		}
	}
	while(i<=mid){
		s[k++]=c[i++];
	} 
	while(j<=right){
		s[k++]=c[j++];
	}	
	return 0;
}
int merge_sort(int a[],int b[],int left,int right){
	int c[n];
	if(left==right){
		b[left]=a[right];
	}
	else{
	int mid=(left+right)/2;
	merge_sort(a,c,left,mid);
	merge_sort(a,c,mid+1,right);
	merge(c,b,left,mid,right);
}
     return 0;
}
int main(){
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	merge_sort(a,b,0,n-1);
	for(int i=0;i<n;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
```

