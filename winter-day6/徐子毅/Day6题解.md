***

# **7-1 直接插入排序**

> 给定一个整数序列，请按非递减序输出采用直接插入排序的各趟排序后的结果。
>
> ### 输入格式:
>
> 测试数据有多组，处理到文件尾。每组测试数据第一行输入一个整数n（1≤n≤100），第二行输入n个整数。
>
> ### 输出格式:
>
> 对于每组测试，输出若干行，每行是一趟排序后的结果，每行的每两个数据之间留一个空格。
>
> ### 输入样例:
>
> ```in
> 4
> 8 7 2 1
> ```
>
> ### 输出样例:
>
> ```out
> 7 8 2 1
> 2 7 8 1
> 1 2 7 8
> ```

直接插入排序可以形象地解释为抓扑克牌，放扑克牌的方法。将后面的数字插入到前面已经排好了的数组即可。

```C++
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int n;
    while(cin >> n){
        if(n==1){
            int num;
            cin >> num;
            cout << num << endl;
            continue;
        }
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=2;i<=n;i++){
        sort(a,a+i);
        cout << a[0];
        for(int i=1;i<n;i++) cout << " " << a[i];
        cout << endl;
    }
    }
    return 0;
}
```

***

# **7-2 成绩排序**

> ### 描述
>
> 给出班里某门课程的成绩单，请你按成绩从高到低对成绩单排序输出，如果有相同分数则名字字典序小的在前。
>
> ### 输入
>
> 第一行为n (0 < n < 20)，表示班里的学生数目； 接下来的n行，每行为每个学生的名字和他的成绩, 中间用单个空格隔开。名字只包含字母且长度不超过20，成绩为一个不大于100的非负整数。
>
> ### 输出
>
> 把成绩单按分数从高到低的顺序进行排序并输出，每行包含名字和分数两项，之间有一个空格。
>
> ### 样例输入
>
> ```in
> 4
> Kitty 80
> Hanmeimei 90
> Joey 92
> Tim 28
> ```
>
> ### 样例输出
>
> ```out
> Joey 92
> Hanmeimei 90
> Kitty 80
> Tim 28
> ```

这里我就直接用了sort,值的注意的是sort的自定义排序。

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
struct people{
    string name;
    int score;
};
bool cmp(people p1,people p2){
    if(p1.score>p2.score) return true;
    else if(p1.score<p2.score) return false;
    else if(p1.name<p2.name) return true;
    else return false;
}
int main(){
    int n;
    cin >> n;
    people a[n];
    for(int i=0;i<n;i++) cin >> a[i].name >> a[i].score;
    sort(a,a+n,cmp);
    for(int i=0;i<n;i++) cout << a[i].name << " " << a[i].score<< endl;
    return 0;
}
```

***

# **7-3 统计工龄**

> 给定公司*N*名员工的工龄，要求按工龄增序输出每个工龄段有多少员工。
>
> ### 输入格式:
>
> 输入首先给出正整数*N*（≤105），即员工总人数；随后给出*N*个整数，即每个员工的工龄，范围在[0, 50]。
>
> ### 输出格式:
>
> 按工龄的递增顺序输出每个工龄的员工个数，格式为：“工龄:人数”。每项占一行。如果人数为0则不输出该项。
>
> ### 输入样例:
>
> ```in
> 8
> 10 2 0 5 7 2 5 2
> ```
>
> ### 输出样例:
>
> ```out
> 0:1
> 2:3
> 5:2
> 7:1
> 10:1
> ```

~~这哪是排序啊你这排序有问题啊~~

这道题直接把对应的工人个数直接放到以年龄为底的数组然后再按顺序输出就好了啊。

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[55];
int main(){
    int N;
    cin >> N;
    memset(a,0,sizeof a);
    for(int i=0;i<N;i++){
        int num;
        cin >> num;
        a[num]++;
    }
    for(int i=0;i<=50;i++){
        if(a[i]!=0) cout << i << ":" << a[i] << endl;
    }
    return 0;
}
```

***

# **7-4 最接近神的人**

> 解了符文之语，小FF开启了通往地下的道路。当他走到最底层时，发现正前方有一扇巨石门，门上雕刻着一幅古代人进行某种活动的图案。而石门上方用古代文写着“神的殿堂”。小FF猜想里面应该就有王室的遗产了。但现在的问题是如何打开这扇门……
>
> 仔细研究后，他发现门上的图案大概是说：古代人认为只有智者才是最容易接近神明的。而最聪明的人往往通过一种仪式选拔出来。仪式大概是指，即将隐退的智者为他的候选人写下一串无序的数字，并让他们进行一种操作，即交换序列中相邻的两个元素。而用最少的交换次数使原序列变成不下降序列的人即是下一任智者。
>
> 小FF发现门上同样有着*n*个数字。于是他认为打开这扇门的秘诀就是找到让这个序列变成不下降序列所需要的最小次数。但小FF不会……只好又找到了你，并答应事成之后与你三七分……
>
> ### 输入格式:
>
> 第一行为一个整数*n*，表示序列长度
>
> 第二行为*n*个整数，表示序列中每个元素。
>
> ### 输出格式:
>
> 一个整数*an**s*，即最少操作次数。
>
> ### 输入样例:
>
> ```in
> 4
> 2 8 0 3
> ```
>
> ### 输出样例:
>
> ```out
> 3
> ```
>
> ### 说明/提示:
>
> 对于30的数据1≤*n*≤104。
>
> 对于100的数据1≤*n*≤5∗105；
>
> 样例说明：开始序列为2803，目标序列为0238，可进行三次操作的目标序列：
>
> ```
> 1．Swap (8,0):2  0  8  3
> 
> 2．Swap (2,0):0  2  8  3
> 
> 3．Swap (8,3):0  2  3  8
> ```

这就是求逆序数对啊，直接归并排序就好了。

```C++
#include <iostream>
using namespace std;
long long a[1000005],S[1000005];
long long ans=0;
void Merge(long long a[],long long S[],long long Front,long long End){
	if(Front==End) return;
	else{
		long long mid=(Front+End)/2;
		Merge(a,S,Front,mid);
		Merge(a,S,mid+1,End);
		long long i=Front,j=mid+1,k=Front;
		while(i<=mid&&j<=End){
			if(a[i]<=a[j]){
				S[k]=a[i];
				k++;
				i++;
			}else{
				S[k]=a[j];
				k++;
				j++;
				ans=ans+mid-i+1;
			}
		}
		while(i<=mid){S[k]=a[i];k++;i++;}
		while(j<=End){S[k]=a[j];k++;j++;}
		for(long long i=Front;i<=End;i++) a[i]=S[i];
	}
}
int main(){
	long long n;
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	Merge(a,S,1,n);
	printf("%lld",ans);
	return 0;
}
```

***

# 7-5 堆排序

> 对n个数，要求用堆排序（最大堆）对其进行排序。
>
> ### 输入格式:
>
> 第一行一个n（n<1000）。第二行给出n个数。
>
> ### 输出格式:
>
> 输出n行，每行n个数。第一行表示将n个数(将n个数看成一棵树)变成最大堆后的结果，第二行表示将上次结果的根节点交换到现有节点的最后一个节点（然后将除最后一个节点的数看成一颗树），然后将该剩余节点树从新变成最大堆后的结果输出（包括交换到最后的节点），依次类推。
>
> ### 输入样例:
>
> ```in
> 6
> 7 1 6 4 3 5
> ```
>
> ### 输出样例:
>
> ```out
> 7 4 6 1 3 5 
> 6 4 5 1 3 7 
> 5 4 3 1 6 7 
> 4 1 3 5 6 7 
> 3 1 4 5 6 7 
> 1 3 4 5 6 7 
> ```

堆排序的核心就是构建树然后再从树中一点一点抽出想要的数字。

见[BiliBili](https://www.bilibili.com/video/BV1K4411X7fq?from=search&seid=6622235890636242921&spm_id_from=333.337.0.0)。

```C++
#include<iostream>
using namespace std;
int n;
void sort(int a[], int n,int point)
{
    int left = 2*point+1;
    int right = 2*point+2;
    int maxp=point;
    if(left<n && a[left] > a[maxp]) maxp = left;
    if(right<n && a[right] > a[maxp]) maxp = right;
    if(maxp!=point){
        swap(a[maxp],a[point]);
        sort(a,n,maxp);
    }
}
int main(){
    cin >> n;
    int a[n];
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=n/2-1;i>= 0;i--) sort(a,n,i);
    for(int i=n-1;i>=1;i--){
        for(int i=0;i<n;i++) cout << a[i] << " ";
        cout << endl;
        swap(a[0],a[i]);
        sort(a,i,0);
    }
    for(int i=0;i<n;i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
```

