## Week1题解

### 7-1

***

### 题目

> 给定一个只含有小写字母的文本串，给定*n*个模式串，求每个模式串在文本串中的出现次数。

### 输入格式

> 第一行输出模式串的个数*n*
>
> 接着从第二行开始读入一个文本串，文本串只包含小写字母，无空格和回车
>
> 再之后读入*n*行模式串，模式串之间用回车间隔
>
> 需要注意的是：
>
> *n*≤20
>
> 文本串的长度 ≤50000
>
> 模式串的长度≤20

### 输出格式

> 输出共包括*n*行，每一行按顺序输出每一个模式串的出现次数.

### input sample

``` 
3
abcabcabcabbb
abc
ab
b
```

### output sample

```
3
4
6
```

### Solution

```c++
这道题比较的适合刚刚接触STL大法的新人（比如我），主要使用了字符串里的find函数，核心代码如下：
for(int i=1;i<=n;i++){
        cin>>s[i];//s[i]是我定义的字符串数组，存放要对比的字符串
        int len=str.find(s[i]);//str是模板
        if(len!=string::npos){
            cnt[i]++;
            len=str.find(s[i],len+1);
            while(len!=string::npos){
                cnt[i]++;
                len=str.find(s[i],len+1);
            }
        }
    }
更多的在提交的文件中有源代码，就不多叙述了
```



### 7-2

***

### 题目

> 有一个长为n的序列，一个区间的权值定义为这个区间内不同数字的个数，请在这个序列中找出两段不相交的区间使它们的权值的和最大.

### input format

> 第一行读入数据组数*n*
>
> 第二行*n*个数(*n*<1*e*6,*ai<1*e*5)

### output form

> 输出一个整数表示最大的权值

### input sample

```
5
1 2 3 2 1
```

### output sample

```
5
```

### 题解

```c++
这道题的题意是找到两个不相交的区间，使得两个区间里不同的数的数量加起来最多
for(int i = 1;i <= n;i++){
        cin>>a[i];
        if(!book[a[i]])//标记数组，判断输入的数之前是否输入过
            pre[i]+=pre[i-1];//记录这个数往前（包含这个数）有多少个不同的数
        else
        		pre[i]=pre[i-1];
        book[a[i]]=1;
    }
    memset(book,0,sizeof(book));
    int max_=INT_MIN;
    suf[n]=1,book[a[n]]=1;
    for(int i = n-1;i > 0;i--){
        suf[i]=suf[i+1];//记录这个数往后（包含这个数）有多少个不同的数
        if(!book[a[i]])
            suf[i]++;
        book[a[i]]=1;
        max_=max(max_,suf[i+1]+pre[i]);//不能是同个下标的相加
    }
代码文件夹里有，就不多说了
```



### 7-3

***

### 题目

> 众所周知，校园跑使用小步点软件时需要依次经过5个点位，一天Phenix发明了一个范围增强器，当Phenix距离点位R米的时就算经过了该点位，现在Phenix公里数已经达到了2公里，但是还剩两个点位需要经过，现在将校园抽象为一个二维坐标系，假设Phenix在（0,0）点，剩下的第一个点位在（d,n）,第二个在(2d,0)，由于Phenix超过了两公里的部分是一点也不想多跑，所以你需要计算在拥有范围增强器的基础上依次经过这两个点位的最短距离。

### input form

> 三个整数R，d，n。（R>0,|d|，|n|，|R|<=1000）
>
> 保证4 * R * R <= d * d + n * n

### output form

> 一个两位小数，表示最短距离

### input sample

```
1 3 5
```

### output sample

```
9.00
```

### Solution

```c++
这就是一道数学题，没有什么好说的（毕竟我也没想出来），就是将X轴上的两个点视为椭圆的两个焦点，求最短路径，就是中轴线上，也就是另一个圆的最下面一点，核心代码如下：
	n=fabs(n),d=fabs(d);//坐标有正有负，记得取绝对值
    if(n<=r)
        printf("%.2f",2.0*d-r);//特判，加入另一个⚪与x轴有交点，那么就直接沿着x轴走过去								//就可以了
    else
        printf("%.2f",sqrt((n-r)*(n-r)+d*d)*2.0-r);//普通情况
```



### 7-4

***

### question

> 现在有n个糖果和一群小朋友，第一个小朋友拥有这n个糖果，他现在有两种选择①分给第二个小朋友x个，x必须是n的约数，且x<n②全部自己留着，第二个小朋友同样也是要么分自己拥有糖果数的约数个给下一个小朋友，要么全留着，以此类推。现在给出第一个小朋友的糖果数n，询问有多少种分法。

### input form

> 输入一个整数（n <= 1000）

### output form

> 方案数

### input sample

```
6
```

### output sample

```
6
```

### Solution

```c++
这是一道简化的动态规划加模拟，先思考分糖果
设一个数组f[n],表示n个糖果时的方案数
假如有7个糖果，可以分3个出去，也可以分2个，也可以分1个，还可以不分
那么7个糖果的方案数就是f[7]=f[3]+f[2]+f[1]+1（也就是不分，全留给自己）
再来思考约数
7的约数只有1和它本身，所以它的方案数只有俩个
由此可以推断出，假如一个数是质数，那么它的方案数只有2个
假如不是，就进行一次循环,找出糖果数的约数
所以得加上判断质数的函数，可以用模拟，埃式筛法以及欧拉筛法
该题答案文件夹里面有，就不多阐述了，主要贴一下判断质数的三种方法
下面的代码是我在不同时候写的，想必各位人中龙凤都可以直到这是什么意思
代码都是模板，通用的
//模拟的方法
bool isprime(int x){
    if(x==2)    return true;
    else if(x%2==0) return false;
    else
        for(int i=3;i<=sqrt(x);i+=2)
            if(x%i==0)
                return false;
    return true;
}
//埃式筛法
void isprime(int n){
    for(int i=2;i<=n;i++){
        //标记数组初始值都是0；
		if(book[i]==0){
			for(int j=2;j*i<=n;j++){
				book[i*j]=1;//质数标记为1
			}
		}
	}
}
//欧拉筛法
void isprime(int n){
    for(int i=2;i<=n;i++){
		if(book[i]==0)
			a[++s]=i;
		for(int j=1;j<=s&&i*a[j]<=n;j++){
			book[i*a[j]]=1;
			if(i%a[j]==0)
				break;
		}
	}
}
```



### 7-5

***

### Question

> 一天Phenix的眼镜被俱乐部某个成员拿了，然后所有的俱乐部成员围成了一个圈，每个人都有个编号，按逆时针递增，而且每个人都有朝向（面向圈内或者圈外），Phenix需要询问编号为1的同学是谁拿的眼镜，但是俱乐部成员很团结不会出卖队友，只会告诉他，例如“眼镜藏在我左数第3个人的右数第1个人的左数第2个人那里”这种形式。现在给出每个人的朝向和名字，和1号同学给出的提示，你需要帮他找出是谁拿的眼镜

### input form

> 第一行两个整数n，m表示有n个人，m个提示，接下来n行，每行一个数字0/1和一个字符串，按1到n的编号顺序依次给出每个人的朝向（0朝向圈内，1朝向圈外）和名字。 再接下来m行，每行同样两个数字0/1,x。表示眼镜往左/右数x个人那里
>
> (n,m<=100000)

### output form

> 输出拿了眼镜的同学的名字

### input sample

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
```

### output sample

```
hhj
```

### Solution

```c++
一道中规中矩的模拟题，洛谷有道很像的，核心代码如下：
	int k=1;
	for(int i=1;i<=n;i++){
		//fa[]与fe[]数组是用来记录他们的朝向以及向左向右
        //k表示过程经历的人以及最后的答案
        if(fa[k]==fe[i])
            //为了防止k变为负数
            k=(k+n-st[i])%n;
        else
            k=(k+st[i])%n;
    }
完整的代码在文件夹中有；
```



### 7-6

***

### Question

> Phenix今天又有早八，由于他喜欢卡点到，所以只给自己留了T分钟的时间吃饭。鹏远餐厅有n道菜，每道菜有一个快乐值v和用餐时间t，意为Phenix可以花t分钟吃掉这道菜，然后获得v的快乐值。但是如果吃早饭的时间太长了，导致他迟到了他也会感到不开心，具体的，如果t > T,他获得的快乐值就是v-(t-T)。现在请你计算Phenix吃掉某一道菜能获得的最大快乐值。

### input form

> 第一行两个整数n,T,接下来n行每行两个数表示每道菜的快乐值和用餐时间。n<=100000。

### output form

> 输出Phenix能获得的最大快乐值（注意可能是负数）

### input sample

```
2 5
3 3
4 5
```

### output sample

```
4
```

### Solution

```c++
这道题的关键点就是不要把她往难想
千万不要用动态规划的方法去做
这就是一道简单的模拟题，式子都列出来了
核心代码如下：
	for(int i=1;i<=n;i++){
        cin>>v[i]>>t[i];
        if(time>t[i])
            max_=max(max_,v[i]);
        else
            max_=max(max_,v[i]-(t[i]-time));
    }
具体的代码在文件夹
```

