## week 2

### 7-1 汉诺塔问题

运用递归思想，将最后一个移出，剩下的视为整体从起始地移动到目标地

当只有一个圆盘时，为递归终止条件

代码如下:

```c++
#include<bits/stdc++.h>
using namespace std; 
void Hanoi (int n,char a[],char b[],char c[])
{
	if (n==1)   
	cout<<a<<"->"<<c<<endl;                                     
    else
		{
        Hanoi(n-1,a,c,b);                  
    	cout<<a<<"->"<<c<<endl;               
        Hanoi(n-1,b,a,c) ;                  
        }
} 
int main ()
   {  
    int n ;
    cin>>n;
    char a[20],b[20],c[20];
    cin>>a>>b>>c;
    Hanoi(n,a,b,c);
    return 0;
   } 
 

```

### 7-2 分而治之

先对每一条路的两端做标记，攻下的城市的所有相关的标记都之0，遍历m条道路，如果存在一条路的两个端点都是0，则至少有两个城市之间是有通路的，则该方案不可行。

代码如下：

```c++
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N,M;  
    cin>>N>>M;
    vector<int> v[N+1];
    for(int i=0;i<M;i++)
    {
        int x,y;
        cin>>x>>y;
        v[x].push_back(y);  
    }
    int K;   
    cin>>K;
    while(K--)
    {
        bool city=true; 
        int Np;  
        cin>>Np;
        set<int> s;  
        for(int i=0;i<Np;i++)
        {
            int t;
            cin>>t;
            s.insert(t);
        }
        for(int i=1; i<=N;i++)
        {
            if(s.find(i) == s.end()) 
            {
                for(int j=0; j<v[i].size();j++)
                {
                    if(s.find(v[i][j]) == s.end()) 
                        city=false;
                }
            }
        }
        if(city!=0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}
```

## 7-3 归并排序

 先二分再归并，先将区间不断一分为二，直到满足递归终止条件（不可再分，即区间只有一个元素），然后将区间两两归并合二为一。 

基本步骤
（1）二分：将数列从中间一分为二
（2）递归：递归排序左右两边
（3）归并：把拆分后的区间归并到辅助数组

```c++
#include<iostream>
using namespace std;
const int N=1000000;
int n;
int q[N],tmp[N];
void merge_sort(int q[],int l,int r)
{
    if(l>=r) return;
    //区间里的元素一个或者没有就return
    int mid = l+r>>1;
    //确定分界点
    merge_sort(q,l,mid),merge_sort(q,mid+1,r);
    //递归排左边和右边
    int k=0,i=l,j=mid+1;
    //k表示已经合并了几个数
    //i指向左边的起点
    //j指向右边的起点
    while(i<=mid&&j<=r)
    //i小于等于左边界并且j小于右边的边界
        if(q[i]<=q[j]) tmp[k++]=q[i++];
        //如果q[i]<=q[j],就把q[i++];
        else tmp[k++] =q[j++];
        //否则就把q[j++];
    while(i<=mid) tmp[k++]=q[i++];
    //左半边没有循环完，把余下的拿过来
    while(j<=r) tmp[k++]=q[j++];
    //右半边没有循环完，把余下的拿过来
    for(i=l,j=0;i<=r;i++,j++) q[i]=tmp[j];
    //最后需要把结果从tmp复制到q[i];
}   
int main()
{
    cin>>n;
    for(int i=0;i<n;i++) 
	cin>>q[i];
    merge_sort(q,0,n-1); //从0到n-1;
    for(int i=0;i<n;i++)
	cout<<q[i]<<" ";

}

```

