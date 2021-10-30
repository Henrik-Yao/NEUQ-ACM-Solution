# WEEK1 周报
## 7-1 string
### 题面

给定一个只含有小写字母的文本串，给定n个模式串，求每个模式串在文本串中的出现次数

**输入格式:**
第一行输出模式串的个数n，接着从第二行开始读入一个文本串，文本串只包含小写字母，无空格和回车，

再之后读入n行模式串，模式串之间用回车间隔，需要注意的是：n≤20,文本串的长度 ≤50000,模式串的长度≤20

**输出格式:**
输出共包括n行，每一行按顺序输出每一个模式串的出现次数

**输入样例:**

```
3
abcabcabcabbb
abc
ab
b
结尾无空行
```
**输出样例:**

```
3
4
6
结尾无空行
```
### 思路
粗暴截取字符串然后比较(s1.compare(s2))
最开始竟没想起来这个↑，疯狂超时

### 代码
```c++
#include<iostream>
using namespace std;

int main()
{
	//输入数据 
	int n;
	string s;
	scanf("%d",&n);
	cin>>s;
	 
	for(int i=0;i<n;++i)		 
	{
		string shortString;		//定义短string 
		int cnt=0;				//计数变量 
		cin>>shortString;		//输入短string 
		int a=s.length()-shortString.length()+1;
		for(int j=0;j<a;++j)
		{
			string cutString = s.substr(j,shortString.length());
			if(!shortString.compare(cutString))
			{
				cnt++;
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
} 

```

## 7-2 区间
### 题面

有一个长为n的序列，一个区间的权值定义为这个区间内不同数字的个数，请在这个序列中找出两段不相交的区间使它们的权值的和最大

**输入格式:**
第一行读入数据组数n​，第二行n个数(n<1e6,a i <1e5)

**输出格式:**
输出一个整数表示最大的权值

**输入样例:**
```
5
1 2 3 2 1
结尾无空行
```
**输出样例:**
```
5
结尾无空行
```

### 思路
没整明白桶是啥，于是用了set，计算重复元素很方便，从左到右算一遍左权，从右向左算一遍右权，倒序相加就好了
最开始一直段错误，把数组定义提到main函数外面就好了，不知道为什么~~（能跑起来就算大功一件）（魔法勿动）~~

### 代码
```c++
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
```

## 7-3 小步点
### 题面

众所周知，校园跑使用小步点软件时需要依次经过5个点位，一天Phenix发明了一个范围增强器，当Phenix距离点位R米的时就算经过了该点位，现在Phenix公里数已经达到了2公里，但是还剩两个点位需要经过，现在将校园抽象为一个二维坐标系，假设Phenix在（0,0）点，剩下的第一个点位在（d,n）,第二个在(2d,0)，由于Phenix超过了两公里的部分是一点也不想多跑，所以你需要计算在拥有范围增强器的基础上依次经过这两个点位的最短距离

**输入格式:**
三个整数R，d，n。（R>0,|d|，|n|，|R|<=1000）,保证4 * R * R <= d * d + n * n

**输出格式:**
一个两位小数，表示最短距离

**输入样例:**
```
1 3 5
结尾无空行
```
**输出样例:**
```
9.00
结尾无空行
```

### 思路
用了hhjgg讲的公式

### 代码
```c++
#include<iostream>
#include<cmath>
using namespace std;
int main(){
	int r,d,n;
	scanf("%d %d %d",&r,&d,&n);
	d=fabs(d);
	n=fabs(n);
	double re;
	if(n>r) re=2.0*sqrt(pow(d,2)+pow(n-r,2))-r;
	else re=2*d-r;
	printf("%.2lf",re);
	return 0;
}
```
## 7-4 分糖果
### 题面

现在有n个糖果和一群小朋友，第一个小朋友拥有这n个糖果，他现在有两种选择①分给第二个小朋友x个，x必须是n的约数，且x<n②全部自己留着，第二个小朋友同样也是要么分自己拥有糖果数的约数个给下一个小朋友，要么全留着，以此类推。现在给出第一个小朋友的糖果数n，询问有多少种分法。

**输入格式:**
输入一个整数（n <= 1000）

**输出格式:**
方案数

**输入样例:**
```
6
结尾无空行
```
**输出样例:**
```
6
结尾无空行
```

### 思路
一个普通递龟

### 代码
```c++
#include<iostream>
using namespace std;
int fent(int x);
int main(){
	int n,c=0;
	scanf("%d",&n);
	c=fent(n);
	printf("%d",c+1);
	return 0;
} 
int fent(int x){
	int cnt=0;
	for(int i=1;i<x;i++){
		if(x%i==0){
			cnt++;
			cnt+=fent(i);
		}
	}
	return cnt;
}
```

## 7-5 找眼镜
### 题面

一天Phenix的眼镜被俱乐部某个成员拿了，然后所有的俱乐部成员围成了一个圈，每个人都有个编号，按逆时针递增，而且每个人都有朝向（面向圈内或者圈外），Phenix需要询问编号为1的同学是谁拿的眼镜，但是俱乐部成员很团结不会出卖队友，只会告诉他，例如“眼镜藏在我左数第3个人的右数第1个人的左数第2个人那里”这种形式。现在给出每个人的朝向和名字，和1号同学给出的提示，你需要帮他找出是谁拿的眼镜

**输入格式:**
第一行两个整数n，m表示有n个人，m个提示，接下来n行，每行一个数字0/1和一个字符串，按1到n的编号顺序依次给出每个人的朝向（0朝向圈内，1朝向圈外）和名字。 再接下来m行，每行同样两个数字0/1,x。表示眼镜往左/右数x个人那里(n,m<=100000)

**输出格式:**
输出拿了眼镜的同学的名字

**输入样例:**

```
7 3
0 ymh
0 lc
0 zx 
1 wjq
1 ld
0 hhj
1 yh 
0 3
1 1
0 2
结尾无空行
```
**输出样例:**

```
hhj
结尾无空行
```

### 思路
一个模拟，面向圈内左手边和面向圈外右手边是顺时针，面向圈内右手边和面向圈外左手边是逆时针，顺时针减逆时针加

### 代码
```c++
#include<iostream>
using namespace std;
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int io[n],lr[m],ins[m];
	string s[n];
	for(int i=0;i<n;i++)
	{
		cin>>io[i]>>s[i];
	}
	for(int i=0;i<m;i++)
	{
		scanf("%d %d",&lr[i],&ins[i]);
	}
	int t=0;
	for(int i=0;i<m;i++)
	{
		if((!io[t]&&!lr[i])||(io[t]&&lr[i]))
		{
			t-=ins[i];
		}
		else
		{
			t+=ins[i];
		}
		while(t>n-1||t<0)
		{
			if(t>n-1)
			{
				t-=n;
			}
			else
			{
				t+=n;
			}
		}
	}
	cout<<s[t];
	return 0;
}
```

## 7-6 恰早饭
### 题面

Phenix今天又有早八，由于他喜欢卡点到，所以只给自己留了T分钟的时间吃饭。鹏远餐厅有n道菜，每道菜有一个快乐值v和用餐时间t，意为Phenix可以花t分钟吃掉这道菜，然后获得v的快乐值。但是如果吃早饭的时间太长了，导致他迟到了他也会感到不开心，具体的，如果t > T,他获得的快乐值就是v-(t-T)。现在请你计算Phenix吃掉某一道菜能获得的最大快乐值

**输入格式:**
第一行两个整数n,T,接下来n行每行两个数表示每道菜的快乐值和用餐时间。n<=100000

**输出格式:**
输出Phenix能获得的最大快乐值（注意可能是负数）

**输入样例:**

```
2 5
3 3
4 5
结尾无空行
```
**输出样例:**
```
4
结尾无空行
```
### 思路
一个普通模拟，思路忘记了，详见代码~~(是自己写的代码自己都不乐意看的屑)~~

### 代码
```c++
#include<iostream>
using namespace std;
int main()
{
	int n,T,happy=0,temp;
	scanf("%d %d",&n,&T);
	int a[n],b[n];
	for(int i=0;i<n;++i)
	{
		scanf("%d %d",&a[i],&b[i]);
		if(b[i]<=T)
		{
			if(happy<=b[i])
			{
				happy=a[i];
			}
		}
		else
		{
			temp=a[i]-(b[i]-T);
			if(happy==0||happy<temp)
			{
				happy=temp;
			}
		}
	}
	printf("%d",happy);
	return 0;
}
```
