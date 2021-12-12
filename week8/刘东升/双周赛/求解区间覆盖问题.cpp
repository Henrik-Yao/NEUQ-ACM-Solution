#include  <stdio.h>
#define N 200                  // 区间数目的上限
void sort1(int value[],int n)  // 排序函数（非递增）
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(value[j]<value[j+1])
			{
				t=value[j];
				value[j]=value[j+1];
				value[j+1]=t;
			}
}
int main()
{
	int m,i,n;         // m是要覆盖的区间数，n是可用于覆盖的线段数
	int position[N];  // 各个要覆盖的区间
	int distance[N-1];  // 存放相邻区间的距离
	printf("请输入要覆盖的区间数m= ");
	scanf("%d",&m);   // 输入要覆盖的区间数
	printf("请输入 %d 个要覆盖的区间： ",m);
	for(i=0;i<m;i++)
		scanf("%d",&position[i]);  // 输入m个区间
	sort1(position,m);   // m个区间降序排列
	for(i=0;i<m-1;i++)
		distance[i]=position[i]-position[i+1]-1;//计算相邻区间距离
	sort1(distance,m-1);  // m-1个区间距离降序排序
	printf("请输入可使用的线段的总数n= ");
	scanf("%d",&n);  // 输入用于覆盖的线段数
	if(n>=m)
	     {
		printf("最小的线段总长为：%d\n",m);
		return 0;
	     }
	int nline=1;  // 当前情况下所用线段总数
	int totallength=position[0]-position[m-1]+1;
                    // 当前情况下所用线段总长
	int devide=0;  // 当前最大的未断开的区间距离
	while((nline<n)&&  //  还未达到可用线段总数
                 (distance[devide]>0))  // 还有不相邻的区间

	     {
		nline++;           // 再用一条线段
		totallength -= distance[devide]; // 总长减少
		devide++;     // 覆盖该区间的线段断开，指向下一最大间隔
	     }
	printf("最小线段总长为：%d\n",totallength);
	return 0;
}
