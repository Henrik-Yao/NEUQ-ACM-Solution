## Week 2 题解

### T1、汉诺塔问题

#### 解法：

可以把n-1个盘子看做一个整体，把（n-1)移动到b，第n个移动到c，然后把（n-1）移动到c。

递归结束的条件为（n==1）此时只要把第一个从a移动到c即可。

结尾无空行需要特判一下~~虽然不特判也能过~~，我用的移动的次数来判断。如果找规律可以发现移动的总次数为2^n-1;

注意是字符串，用字符的会wa。

```
void move(int n,string a,string b,string c)
{
		if(n==1)
		{
			if(ans!=tot-1)
			cout<<a<<"->"<<c<<endl,ans++;
			else cout<<a<<"->"<<c;
		}
		else 
		{
			move(n-1,a,c,b);
			cout<<a<<"->"<<c<<endl,ans++;
			move(n-1,b,a,c);
		}
}
```

### T2、分而治之

#### 解法：

用结构体来存储相连接的两个点。用vis数组来保存某一点是否被摧毁。

遍历每一条边，如果这条边的两个点都没有被摧毁则证明该方案不行。

遍历完全部的边如果成立则方案成立。

```
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		a[i].x=read();
		a[i].y=read();
	}
	k=read();
	while(k--)
	{
		int ks=0;
		memset(vis,1,sizeof(vis));
		R int z;
		z=read();
		for(int i=1;i<=z;i++)
		{
			R int s;
			s=read();
			vis[s]=0;
		}
		for(int i=1;i<=m;i++)
		{
			if(vis[a[i].x] && vis[a[i].y])
			{
				ks=1;
				break;
			}
		}
		if(ks==1)cout<<"NO";
		else cout<<"YES";
		if(k!=0)cout<<"\n";
	}
	return 0;
}
```

### T3、归并排序

#### 解法：

这是归并排序的板子题。归并排序的思想就是不断的二分，分成特别小的区间。在某个区间内，比较中间两边的点，将小的点放在左边。因为会被分成很小的区间，这样可以保证每一段都是有序的。

```
void sortpai(int l,int mid,int r)
{
	int m=mid-l+1;int n=r-mid;
	int a1[m+1],a2[n+1];
	for(int i=1;i<=m;i++)
	a1[i]=a[l+i-1];
	for(int i=1;i<=n;i++)
	a2[i]=a[mid+i];
	int i=1,j=1,k=l;
	while(i<=m && j<=n)
	{
		if(a1[i]<a2[j])a[k++]=a1[i++];
		else a[k++]=a2[j++];
	}
	while(i<=m)a[k++]=a1[i++];
	while(j<=n)a[k++]=a2[j++];
}
void sortfen(int l,int r)
{
	if(l<r)
	{
		int mid=(l+r)/2;
		sortfen(l,mid);
		sortfen(mid+1,r);
		sortpai(l,mid,r);
	}
}
```

