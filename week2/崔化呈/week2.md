# week2 题解
## 汉诺塔问题
*题意：典型递归问题*          

    拆解步骤，就会发现有两个步骤在不断重复：1.把上面的所有层都移至中转柱。2.把最底下一层从它原来的位置移动至目标柱。
	只有一层是递归的终止，一定是直接从开始柱转移至目标柱。	
	所以把函数中的a作为开始柱，b作为中转柱，c作为目标柱开始递归。
void hnt(int n,string a,string b,string c)
{
	if(n==1){cout<<a<<"->"<<c<<endl;}
	else
	{
		hnt(n-1,a,c,b);
		cout<<a<<"->"<<c<<endl;
		hnt(n-1,b,a,c);
	}
}

## 分而治之
*题意：，使每个城市实现孤立，即使桥的两头不能出现都未被攻占的情况，那些没桥连接的城市本身就处于孤立（不考虑）*

		由题义可知，我们应关注桥的开始与结尾的城市编号，即struct
struct r
{
	int s;
	int e;
};
	
	然后根据桥的情况逐一判断

## 归并排序
*题意：分治思想的典型体现*

	先分再治
	分：把大数组分成一个个数
void mergegui(int arr[],int l,int r)
{
	if(l==r){return;}
	int mid=(l+r)/2;
	mergegui(arr,l,mid);
	mergegui(arr,mid+1,r);  //在这都是分
	mergesort(arr,l,mid,r);	
}

	治：让每两个数组（在函数中只是和成了一个数组样，但本质上在中间已经断开算作两个数组）从头到尾开始读取，把数按顺序依次排好形成一个大数组
void mergesort(int arr[],int l,int mid,int r)
{
	int h[r-l+1];
	int li=l,ri=mid+1;
	int i=0;
	while(li<=mid&&ri<=r)
	{
		h[i++]=arr[li]<arr[ri]?arr[li++]:arr[ri++];
	}
//不可能左半侧数组与右半侧数组同时到头
	while(li<=mid)
	{
		h[i++]=arr[li++];
	}
	while(ri<=r)
	{
		h[i++]=arr[ri++];
	}
	for(int j=0;j<r-l+1;j++)
	{
		arr[l+j]=h[j];
	}
	
}




