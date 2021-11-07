week4

一

加速算法运行：欧拉筛法或者素数开方法

欧拉筛法：设两个组，一个数组，一个bool组。数组的下标表示数，bool来标记是否为素数。首先判断一个数有没有被标记过，如2，未被标记，则为素数，将所有2的倍数标记，

欧拉筛法效率高的一个重要原因是，它不会重复标记一个数是不是素数的倍数，例如：6是素数2的倍数，同时也是素数3的倍数，欧拉算法能做到只标记一次6。

我们先看一下代码

#include <stdio.h>
#include <string.h>
using namespace std;

int main()
{
	int n, cnt = 0; // n是你要找的素数范围，cnt代表在这个范围内素数的个数

    int prime[100001];// 用来保存素数，注意，是用数组的值而不是用下标保存哦！
    
    bool visited[100001];// 就是这个数组！用来记录一个数是否是某个素数的倍数，标记它
    
    scanf("%d", &n); // 输入你想查找的范围
    
    memset(visited, false, sizeof(visited));// 初始化 
    
    memset(prime, 0, sizeof(prime));// 初始化
    
    for(int i = 2; i <= n; i++)
    
    {
    
        if(!visited[i])// 如果没有被标记过
    
        {
        	prime[cnt++] = i;// 那么它就是素数啦~，存起来存起来，cnt记得+1 
        }
    
        for(int j = 0; j<cnt && i*prime[j]<=n; j++) // 这个循环是最难理解的部分，我将在下文详细解释
    
        {
    
            visited[i*prime[j]] = true;// 标记素数倍数
    
            if(i % prime[j] == 0) break;// 这一步跳出循环是欧拉筛法高效率的关键，也是同一个合数只被标记一次的关键
    
        }
    
    }
    return 0;
}
现在来详细分解一下那个for循环代码此处我们暂时抛开 if(i % prime[j] == 0) break; 这句代码来讨论
for循环的循环变量 j 每次都从 0 开始跑，而这个 j 是从 prime[] 数组中取数据的，我们就可以这样等价，for循环每次都从已经找到的素数中从头开始取值。
例如 prime[] 中已经判断出了 2,3,5,7 那么for循环第一次取值2，如果没有跳出的话，第二次取值3，然后没有跳出的话就一直循环到已经找出的素数末尾。

然后visited[i*prime[j]] = true;

这个代码段，是用来标记素数倍数的，例如，当 i 等于2的时候，素数数组里只存在一个素数 2 ，然后进入 for 循环，for 循环会将 2 取出来与 i 相乘，得到 2 的倍数 4 ，标记它，然后结束 for 循环。跑过 i = 3，执行到 i = 4 的时候，千万不要以为这个时候 for 循环不执行了！ 这个时候 for 循环依旧会尽职地把 2 取出来和 4 相乘，将 2 的倍数 8 标记！然后 不会取到第二个素数 3 ，因为 4 % 2 == 0 -------

纵观之，如果我们不把

if(i % prime[j] == 0) break;

这段代码放在内的话， for 循环的作用就是将素数的倍数都标记上。讨论关键性代码段 if(i % prime[j] == 0) break;
然后我们开始讨论上面那一小段代码的关键性作用：

18 是素数 3 的倍数，但是我们并不会用 3 的倍数来标记掉 18 , 因为假如我们用 3 来标记 18 ，那么 i 势必要跑到 6 这样 i * 3 才会标记掉18， 但是在这之前 i 就已经被 3 之前的一个素数 2 弄死了，退出循环了。
那么为什么要这么做？因为 6 既然能被 2 整除， 那么 18 迟早会被 2 标记，所以这里就不要再用 3 来重复标记 18。有个规律，凡是 i 跑到偶数位的时候，它永远只能与素数 2 相乘一次来标记掉一个数，然后因为能整除 2 而退出循环。 从这个规律，这个筛法的时间复杂度就可见一斑了。
外层 i 循环用来选出素数和作为标记素数倍数的倍数因子，内层 j 循环用来从素数中最小的开始遍历作为标记素数倍数的素数因子。然后通过 i % 素数 == 0 来退出标记避免重复标记。
二

经过找规律可以发现是一个斐波那契数列，值得注意的是本来就在第一阶，所以1时步数为0；2为1，3为2，从四时开始递归。

#include<iostream>
using namespace std;
int main()
{
	int y;
	cin >> y;
	int fei(int n);
	for (int i = 1; i <= y; i++)
	{
		int u;
		cin >> u;
		cout << fei(u) << endl;
	}




}
int fei(int n)
{
	int sum = 0;
	if (n == 1)
		sum = 0;
	else if (n == 2)
		sum = 1;
	else if (n == 3)
		sum = 2;
	else
	{
		sum = fei(n - 1) + fei(n - 2);
	}

	return sum;

}

3.与题意解法一致，可以用欧拉筛法或者直接

#include<iostream>
using namespace std;

const int Max = 10000001;
int group[Max];
long long int n;

int main() {
    cin >> n;

    for (int i = 3; i <= n; i++)
    {
        if (i % 2)//如果为奇数标记为0下面继续筛选
        {
            group[i] = 0; 
        }
        else //如果为偶数，标记为1
        {
            group[i] = 1;   
        }
    }
    for (int i = 3; i * i <= n; i++)
    {
        if (!group[i])//如果为奇数
        {
            for (int j = i + i; j <= n; j += i)//奇数的倍数不是素数
            {
                group[j] = 1;  //标记
            }
        }
    }
    
    int result = 0;
    
    for (int i = 2; i <= n; i++)
    {
        if (!group[i]) {
            result++;
        }
    }
    cout <<result << endl;
    
    return 0;
}

i*i<=n的意思是，对于任何一个数，他如果能拆成相乘的形式，必定一个因子大一个因子小，所以且他们的分界线是对这个数开方得到的数，只需要在着两端的i、一段区间判断是否存在因子，即可判断这个数是不是素数。本题直接使用了i的方，有数据溢出的危险，也可以直接使用sqrt函数，提前做一步开方，更加保险。

4.

快速幂：

思想是，如果次方为偶数，则将次方除以二，同时a自乘a；若次方为奇数，则将次方减一，并用另一个数x存储这时的a，相当于等于a的一次方。

同时还有一个重要的公式

1. (a + b) % p = (a % p + b % p) % p 
2. (a - b) % p = (a % p - b % p ) % p 
3. (a \* b) % p = (a % p \* b % p) % p 

特别是第三个，可以每次运算时都对a和x取余，大大缩短时间。

#include<iostream>
using namespace std;
typedef long long ll;
ll ksm(ll a, ll b, ll c);
int main()
{

	long long int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		long long int x, y, z;
		cin >> x >> y >> z;
		cout << ksm(x, y, z) << endl;


	}



	return 0;
}
ll ksm(ll a, ll b, ll c)
{
	long long int s = 1;
	while (b > 1)
	{
		if (b % 2 == 1)
		{
			s = s * a;
			s = s % c;
			b = b - 1;

		}
		else
		{
			a = a * a;
			a = a % c;
			b = b / 2;
		}
		
	}



	return(s * a) % c;








}