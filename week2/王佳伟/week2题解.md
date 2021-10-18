# week2题解



## 1.汉诺塔问题

思路：1、用函数move代表将n-1个盘从now移到3-now-to（即除now和to的一根桩）

​	2、随后将最后一个移到to

​	3、将n-1个盘从3-now-to移到to

```c++
#include<bits/stdc++.h>
using namespace std;

string a[3];
void move(int n, int now, int to){
	if(n == 0) return;
	move(n-1, now, 3-now-to);
	cout << a[now] << "->" << a[to] << endl;
	move(n-1, 3-now-to, to);
}

int main() {
	int n; 
	cin >> n;
	
	for(int i = 0; i < 3; i++){
		cin >> a[i];
	} 
	move(n, 0, 2);
}
```



## 2.分而治之

题意为判断方案是否能将城市分开，能YES，不能NO

**关键在于判断所有连接是否被断开（至少有一方已经被击破）**

```C++
#include<bits/stdc++.h>
using namespace std;

struct connect{ //连接 
	int city1;
	int city2;
}con[10001];;


int main() {
	int n, m; 
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		cin >> con[i].city1 >> con[i].city2;
	}
	int t;//方案数 
	int k; 
	int c;//除去编号为c的城市 
	int insist[10001] = {0};//第i编号的城市是否存在 ,0代表存在，1代表不存在 
	cin >> t;
	for(int i = 0; i < t; i++){
		memset(insist, 0, sizeof(insist));
		cin >> k;
		for(int i = 0; i < k; i++){
			cin >> c;
			insist[c] = 1;
		}
		//判断是否可行
		bool judge = true;
		for(int j = 0; j < m; j++){ //看还有哪个连接不满足要求 
			if(!insist[con[j].city1] && !insist[con[j].city2]) {//都存在 
				judge = false;
			}
		} 
		if(judge){
			cout << "YES" << endl; 
		}
		else cout << "NO" << endl;
	}
}
```



## 3.归并排序

利用递归将数组逐渐二分，最后合并

**注意：需要与数组等大的额外空间保存每次合并后的数组，并复制回原数组，否则，白排序了**

```C++
#include<bits/stdc++.h>
using namespace std;

int a[100001] ;
int b[100001] ;

void msort(int l, int r){
	if(l == r) return;
	int mid = (l+r)/2;
	msort(l, mid);
	msort(mid+1, r);
	//合并 
	int left = l, right = mid+1;
	int node = l;
	while(left <= mid && right <= r){
		if(a[left] <= a[right]){
			b[node++] = a[left++];
		}
		else{
			b[node++] = a[right++];
		}
	}
	while(left <= mid){
		b[node++] = a[left++];
	}
	while(right <= r){
		b[node++] = a[right++];
	}
	for(int i = l; i < node; i++){
		a[i] = b[i];
	}
}

int main() {
	int n; 
	cin >> n;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	//排序
	msort(0, n-1) ;
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
}
```

