***

# 7-1 汉诺塔问题

> 给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

经典递归题目。

可以参考：[bilibili视频](https://www.bilibili.com/video/BV1Hk4y1k7KL?from=search&seid=14212635478384989118&spm_id_from=333.337.0.0)。

```C++
#include <iostream>
#include <cstring>
using namespace std;
void Hanoi(int n,string a,string b,string c){//将n个塔从a经过b移动到c，中间这个b看起来没啥用，其实是传入了中间柱这个概念www
    if(n==1) {cout << a << "->" << c << endl;return;}//只有一个盘时很好移动
    else{
        Hanoi(n-1,a,c,b);//将n-1个盘子从a移动到b
        cout << a << "->" << c << endl;//再把第n个盘子从a移动到c处
        Hanoi(n-1,b,a,c);//n-1个盘子归位，从b移动到c
    }
}
int main(){
    int m;
    cin >> m;
    string a,b,c;
    cin >> a >> b >> c;
    Hanoi(m,a,b,c);
    return 0;
}
```

***

# 7-2  分而治之

<font color=grey>~~不是啊这道题我没用分治啊这~~</font>

> 分而治之，各个击破是兵家常用的策略之一。在战争中，我们希望首先攻下敌方的部分城市，使其剩余的城市变成孤立无援，然后再分头各个击破。为此参谋部提供了若干打击方案。本题就请你编写程序，判断每个方案的可行性。

这道题我一开始用了二维数组然后段错误了我&^#*。

因为二维数组a\[10005\]\[10005\]容易内存损耗太大。

```C++
#include <iostream>
using namespace std;
int city[10005][10005],citytest[10005][10005];//爆了啦
int survive[10005];
int main(){
	int N,M,r1,r2,K,Np,bc,flag;
	cin >> N >> M;
	for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) city[i][j]=0;
	for(int i=0;i<=N;i++) survive[i]=1;
	for(int abc=1;abc<=M;abc++){
		cin >> r1 >> r2;
		city[r1][r2]=1;
		city[r2][r1]=1;
	}
	cin >> K;
//	cout << "This is K " << K << endl;
	for(int abc=1;abc<=K;abc++){
        for(int i=0;i<=N;i++) for(int j=0;j<=N;j++) citytest[i][j]=city[i][j];
        for(int i=0;i<=N;i++) survive[i]=1;
//        cout << "This is the " << abc << " Time to attack!" << endl;
		cin>>Np;
		for(int defg=1;defg<=Np;defg++){
			cin >> bc;
			survive[bc]=0;
			for(int i=1;i<=N;i++) citytest[i][bc]=0;
		}
		flag=1;
		for(int i=1;i<=N;i++){
			if(survive[i]!=0){
				for(int j=1;j<=N;j++){
					if(citytest[i][j]!=0) {flag=0;break;} 
				}
				if(flag==0) {cout << "NO" << endl;break;}
			}
		}
		if(flag==1) cout << "YES" << endl;
	}
	return 0;
}
```



我的想法是bool a\[城市编号]\[连接的城市]这个想法，然后我要去优化它，我觉得用二维数组存储两个城市之间的路耗费内存太大，于是我用vector来储存连接的城市。~~暴力破解是不可能优化的。~~

第二是我用了citytest和city两个数组，因为我不想改变city数组。同样占据太大内存，于是我使用了检测而不是改变来进行操作。于是就有：

```C++
#include <iostream>
#include <vector>
using namespace std;
int survive[10005];//城市状态
vector<int> city[10005];//一个vector的二维数组
int main(){
	int N,M,r1,r2,K,Np,bc,flag;
	cin >> N >> M;
	for(int i=0;i<=N;i++) survive[i]=1;
	for(int abc=1;abc<=M;abc++){
		cin >> r1 >> r2;
		city[r1].push_back(r2);//同之前，一个存编号一个存连接的编号
		city[r2].push_back(r1);	
	}
	cin >> K;
	for(int abc=1;abc<=K;abc++){
		for(int i=0;i<=N;i++) survive[i]=1;
		cin>>Np;
		for(int defg=1;defg<=Np;defg++){
			cin >> bc;
			survive[bc]=0;
		}
		flag=1;
		for(int i=1;i<=N;i++){
			if(survive[i]!=0){
				for(int j=0;j<city[i].size();j++){
					if(survive[city[i][j]]==1){//检测连接的城市是否炸了
						flag=0;//没炸就NO
						break;
					}
				}
			}
			if(flag==0) {cout << "NO" << endl; break;}
		}
		if(flag==1) cout << "YES" << endl;
	}
	return 0;
}
```

当时用gdb来debug：

```shell
gdb example
b 29
b 35
display flag
display city[i][j]
display survive[i]
run
```

***

# 7-3 归并排序

就是归并排序。

可以参考：[Youtube视频](https://www.youtube.com/watch?v=COk73cpQbFQ)、[Bilibili视频](https://www.bilibili.com/video/BV1Ax411U7Xx)。

<font color=grey>~~这玩意儿太难了要递归要分治wsl~~</font>

不多说：

倘若有俩数组 2 4 6 8和1 3 9 10

设为a0 a1 a2 a3和b0 b1 b2 b3

将这两个数组按照顺序合并为一个数组，就是分治中的合。

比较a0和b0，发现b0更小，使得ma0<--b0，同时b的下标和ma的下标增加一。

比较a0和b1，发现a0更小，使得ma1<--a0，同时a的下标和ma的下表增加一。

以此类推。

最终a3被输入进ma数组，此时b还剩下两个数字，将b输入到ma里即可。

```C++
#include <iostream>
using namespace std;
void Merge(int ma[],int L,int M,int R){//将两个数组ma(L-M)和ma(M-R)数组按顺序合并
	int leftsize=M-L;//左边数组的长度
	int rightsize=R-M+1;//右边数组的长度
	int leftarray[leftsize],rightarray[rightsize];//这是定义的两个数组原来是ma(L-M)和ma(M-R)
	int i;
	for(i=L;i<M;i++) {
		leftarray[i-L]=ma[i];//将数字输入两个数组
	}
	for(i=M;i<=R;i++) {
		rightarray[i-M]=ma[i];//通上
	}
	int k=L,j=0;i=0;
	while(i<leftsize&&j<rightsize){//开始按顺序写入新的ma数组
		if(leftarray[i]<rightarray[j]) {
			ma[k]=leftarray[i];k++;i++;
		}else {
			ma[k]=rightarray[j];k++;j++;
		}
	}
	while(i<leftsize){ma[k]=leftarray[i];i++;k++;}//写入剩下的
	while(j<rightsize){ma[k]=rightarray[j];j++;k++;}
}
void Mergesort(int m[],int L,int R){//体现分治和归并的函数
	if(L==R) return;//返回条件，数组中仅有1个数
	else{
		int mid=(R+L)/2;//拆分两个数组
		Mergesort(m,L,mid);//拆分左侧，计算左侧，合并左侧
		Mergesort(m,mid+1,R);//拆分右侧，计算右侧，合并右侧
		Merge(m,L,mid+1,R);//合并左右侧
	}
}
int main(){
	int T,nu;
	cin >> T;
	int a[T];
	for(int abc=0;abc<T;abc++){cin >> nu;a[abc]=nu;}
	Mergesort(a,0,T-1);//耶,楽しい。
	for(int abc=0;abc<T;abc++){cout << a[abc] << " ";}
	cout << endl;
	return 0;
}
```

~~最好玩的就是那个Mergesort函数了。~~

