#include<iostream>
#include<set> 
using namespace std;
const int N = 1e6 + 10;
int	a[N],lQuan[N],rQuan[N],maxquan=0;		//左权数组右权数组最大权和
int main()
{	
	//输入数据 
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
	{
    	scanf("%d",&a[i]);
	}
	for(int i=0;i<n;++i)				//初始化 
	{
		lQuan[i]=0;
		rQuan[i]=0;
	}
	set<int> lSet,rSet;					//左集右集 
	
 	for(int i=0;i<n-1;++i)
	{
 		lSet.insert(a[i]);				//从最左依次入左集
		lQuan[i]=lSet.size();			//储存左权 
	}
	for(int i=n-1;i>0;--i)
	{
 		rSet.insert(a[i]);				//从最右依次入右集
		rQuan[i]=rSet.size();			//储存右权 
	}
	for(int i=0;i<n-1;++i)
	{
		if(maxquan<lQuan[i]+rQuan[i+1])
		{
			maxquan=lQuan[i]+rQuan[i+1];	//倒序相加 
		}
	}
	printf("%d",maxquan);
    return 0;
}
