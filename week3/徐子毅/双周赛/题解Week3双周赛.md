***

# 7-1 最大子段和

>给定n个整数（可能为负数）组成的序列a[1],a[2],a[3],…,a[n]，求该序列如a[i]+a[i+1]+…+a[j]的子段和的最大值。当所给的整数均为负数时，定义子段和为0。
>
>要求算法的时间复杂度为O(n)。

这里在中间切一刀，使得其变为左右两部分。

利用递归算出左边部分的最小值和右边部分的最小值，返回条件是区间大小为1或0。

算出了左边和右边的所有最小值，接下来应该计算**中间那部分被切开来的一段**。

中间切开来的一段可以通过计算切开处往两边延伸的最大值，具体来说就是延向左边的最大值+延向右边的最大值，这样计算。

```C++
#include <iostream>
using namespace std;
int Find(int a[],int front,int end){
    if(front==end) return a[front];
    else{
        int mid=(front+end)/2;
        int leftnnumax=Find(a,front,mid);
        int rightnnumax=Find(a,mid+1,end);
        int ma=max(leftnnumax,rightnnumax);
        //Middle
        int leftnumber=0;int leftmax=0;int rightnumber=0;int rightmax=0;
        for(int i=mid;i>=front;i--){
            leftnumber+=a[i];
            leftmax=max(leftmax,leftnumber);
        }
        for(int i=mid+1;i<=end;i++){
            rightnumber+=a[i];
            rightmax=max(rightmax,rightnumber);
        }
        ma=max(ma,leftmax+rightmax);
        return ma;
    }
}
int main(){
    int T;
    cin >> T;
    int a[T];
    for(int i=0;i<T;i++){
        cin >> a[i];
    }
    cout << Find(a,0,T-1) << endl;
    return 0;
}
```

***

# 7-2 汉诺塔问题

> 给定一个由n个圆盘组成的塔，这些圆盘按照大小递减的方式套在第一根桩柱上。现要将整个塔移动到另一根桩柱上，每次只能移动一个圆盘，且较大的圆盘在移动过程中不能放置在较小的圆盘上面。

<font size="10"><b>?</b></font>

```C++
#include <iostream>
#include <cstring>
using namespace std;
void Hanoi(int n,string a,string b,string c){
    if(n==1) {cout << a << "->" << c << endl;return;}
    else {
        Hanoi(n-1,a,c,b);
        cout << a << "->" << c << endl;
        Hanoi(n-1,b,a,c);
    }
}
int main(){
    int n;string a,b,c;
    cin >> n >> a >> b >> c;
    Hanoi(n,a,b,c);
    return 0;
}
```

***

# 7-3 汉诺塔问题III<font size="1"> 为啥先是3？</font>

> ~~约19世纪末，在欧州的商店中出售一种智力玩具，在一块铜板上有三根杆，最左边的杆上自上而下、由小到大顺序串着由64个圆盘构成的塔。目的是将最左边杆上的盘全部移到右边的杆上，条件是一次只能移动一个盘，且不允许大盘放在小盘的上面。~~<font size="1">(以上废话)</font> 现在我们改变游戏的玩法，不允许直接从最左(右)边移到最右(左)边(每次移动一定是移到中间杆或从中间移出)，也不允许大盘放到下盘的上面。 Daisy已经做过原来的汉诺塔问题和汉诺塔II，但碰到这个问题时，她想了很久都不能解决，现在请你帮助她。现在有N个圆盘，她至少多少次移动才能把这些圆盘从最左边移到最右边？

这里要准确一点，从7-2延伸，其实就是移动一个盘子比原来多了一步而已。

值得一提的是，利用递归将所有结果算出来比原来更简单。

```C++
#include <iostream>
using namespace std;
unsigned long long a[36];
unsigned long long Hanoi(int n){
	if(a[n]!=0) return a[n];
    if(n==1) return 2;
    else{
        return Hanoi(n-1)+1+Hanoi(n-1)+1+Hanoi(n-1);
    }
}
int main(){
    int n;
    for(int i=0;i<=35;i++) a[i]=Hanoi(i);
    while(cin >> n) {
    	cout << a[n] << endl;
	}
    return 0;
}
```

***

# 7-4 汉诺塔问题II

> ~~经典的汉诺塔问题经常作为一个递归的经典例题存在。可能有人并不知道汉诺塔问题的典故。汉诺塔来源于印度传说的一个故事，上帝创造世界时作了三根金刚石柱子，在一根柱子上从下往上按大小顺序摞着64片黄金圆盘。上帝命令婆罗门把圆盘从下面开始按大小顺序重新摆放在另一根柱子上。并且规定，在小圆盘上不能放大圆盘，在三根柱子之间一回只能移动一个圆盘。有预言说，这件事完成时宇宙会在一瞬间闪电式毁灭。也有人相信婆罗门至今仍在一刻不停地搬动着圆盘。恩，当然这个传说并不可信，如今汉诺塔更多的是作为一个玩具存在。Gardon就收到了一个汉诺塔玩具作为生日礼物。~~ <font size="1">（以上废话）</font> Gardon是个怕麻烦的人（恩，就是爱偷懒的人），很显然将64个圆盘逐一搬动直到所有的盘子都到达第三个柱子上很困难，所以Gardon决定作个小弊，他又找来了一根一模一样的柱子，通过这个柱子来更快的把所有的盘子移到第三个柱子上。下面的问题就是：当Gardon在一次游戏中使用了N个盘子时，他需要多少次移动才能把他们都移到第三个柱子上？很显然，在没有第四个柱子时，问题的解是2^N-1，但现在有了这个柱子的帮助，又该是多少呢？

第四根柱子很好的提高了难度（雾

咋整我也8大会，就是把盘子拆成两部分，一部分先搬运，一部分后搬运。找到最佳的拆分点。

具体来说：

+ N个可爱的盘子
+ 被拆成了R个和N-R个盘子（R拥有最优解（应该（好像有数学dalao证出来了
+ 先搬走N-R个盘子到2柱（通过3,4柱）
+ 搬R个盘子到4柱（通过3柱，此时解法如同经典汉诺塔）
+ 把N-R个盘子搬到4柱
```C++
#include <iostream>
#include <cmath>
using namespace std;
int Hanoi(int n){
	return pow(2,n)-1;
}
int main(){
	int N;
	int Hanoi121[65]={0,1,3,5};
	int mi=999999;
	for(int i=3;i<=64;i++){
		mi=999999;
		for(int r=1;r<i;r++)
			if(2*Hanoi121[r]+pow(2,i-r)-1<mi)
				mi=2*Hanoi121[r]+pow(2,i-r)-1;
		Hanoi121[i]=mi;
	}
	while(cin >> N) cout << Hanoi121[N] << endl;
	return 0;
}
```

***

# 7-5 《简单》的归并

> 已知数组A和B各有m、n个元素，且元素按值非递减排列，现要求把A和B归并为一个新的数组C，且C中的数据元素仍然按值非递减排列。 例如，若A=(3，5，8，11)，B=(2，6，8，9，11，15，20)， 则C=(2，3，5，6，8，8，9，11，11，15，20)

归并。

```C++
#include <iostream>
using namespace std;
int main(){
    int T,n1,n2;
    cin >> T;
    for(int abc=1;abc<=T;abc++){
        cin >> n1;
        int a[n1];
        for(int i=0;i<n1;i++) cin >> a[i];
        cin >> n2;
        int b[n2];
        for(int i=0;i<n2;i++) cin >> b[i];
        int sum[n1+n2];
        int i=0,j=0,k=0;
        while(i<n1&&j<n2){
            if(a[i]<b[j]){
                sum[k]=a[i];
                k++;
                i++;
            }
            else{
                sum[k]=b[j];
                k++;
                j++;
            }
        }
        while(i<n1) {sum[k]=a[i];k++;i++;}
        while(j<n2) {sum[k]=b[j];k++;j++;}
        cout << sum[0];
        for(int i=1;i<n1+n2;i++) cout << " " << sum[i];
        cout << endl;
    }
    return 0;
}
```

***

# 7-6 **字符串的全排列**

> 给定一个全由小写字母构成的字符串，求它的全排列，按照字典序从小到大输出。

<s> 为什么不用C++的algorithm库里的next_permutation呢？（雾 </s>

```C++
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int main(){
	string a;
	getline(cin,a);
	do{
		cout << a << endl;
	}while(next_permutation(a.begin(),a.end()));
	return 0;
}
```

~~以上算法还成功排除了重复字母。~~

不靠谱的解法：

```C++
#include <iostream>
#include <cstring>
using namespace std;
void TrueMerge(string str,int front,int end){
	for(int i=front;i<=end;i++){
		for(int j=front;j<end;j++){
			if(str[j]>str[j+1])swap(str[j],str[j+1]);
		}
	}
}
void Merge(string str,int front,int end){
	if(front>end) return;
	if(front==end) {cout << str << endl;}
	else{
		for(int i=front;i<=end;i++){//选择第一个数
			swap(str[front],str[i]);//同，选择第一个数
			Merge(str,front+1,end);	
			TrueMerge(str,front,end);
		}
	}
}
int main(){
	string str;
	getline(cin,str);
	for(int i=0;i<str.size();i++){
		for(int j=0;j<str.size()-1;j++){
			if(str[j]>str[j+1])swap(str[j],str[j+1]);
		}
	}
	Merge(str,0,str.size()-1);
	return 0;
}
```

# 7-7 **逆 序 对**

> 求逆序对。

~~写这道题我直接心态爆炸。~~

~~一道（换了思路的）归并排序我甚至都写不出来。~~

~~<font color="red" size="2">菜是原罪</font>~~
~~<font color="red" size="1">诶我就是菜了怎么滴？</font>~~

其实所谓的逆序数就是归并时候的交换。

```C++
#include <iostream>
using namespace std;
long long a[1000005],S[1000005];
long long ans=0;
void Merge(long long a[],long long S[],long long Front,long long End){
	if(Front==End) return;
//	if(Front+1==End&&a[Front]>a[End]){swap(a[Front],a[End]);return;}
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
				ans=ans+mid-i+1;//这里！
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
//	for(long long j=1;j<=n;j++){cout << a[j] << " ";}
//	cout << endl;
	printf("%lld",ans);
	return 0;
}
```

***

# 7-8 二分查找

>请实现有重复数字的有序数组的二分查找。
>
>输出在数组中第一个大于等于查找值的位置，如果数组中不存在这样的数，则输出数组长度加一。

二分查找，找到中间数。

判断中间数是不是比要找的数大

如果中间数再大就找前半段，否则查找后半段。

```C++
#include <iostream>
using namespace std;
int minnu;
void Find(int a[],int f,int front,int end){
    if(front==end) {
    	minnu=min(minnu,end);
	}
    else{
		int mid=(front+end)/2;
  	  if(a[mid]>=f) Find(a,f,front,mid);
  	  else if(a[mid]<f) Find(a,f,mid+1,end);
  }
}
int main(){
    int Nu,fi;
    scanf("%d %d",&Nu,&fi);
    int a[Nu];
    minnu=Nu;
    for(int i=0;i<Nu;i++) scanf("%d",&a[i]);
    if(a[Nu-1]<fi) {
    	printf("%d",minnu+1);
    	return 0;
	}
    Find(a,fi,0,Nu-1);
    printf("%d",minnu+1);
}
```

