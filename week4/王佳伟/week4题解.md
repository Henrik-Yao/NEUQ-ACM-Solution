## 1.素数

分析：有多组区间，因此先将用欧拉筛将所欲素数记录，将区间内的素数输出即可

```c++
#include<bits/stdc++.h>
using namespace std;
#define maxn 100005
int prime[maxn];
int visit[maxn];
int main() {
	
	memset(prime, 0, sizeof(prime));
	memset(visit, 0, sizeof(visit));
	int cnt = 1;//素数的个数 
	for(int i = 2; i <= 100001; i++){
		if(!visit[i]){//如果是素数 
			prime[cnt++] = i;//记录此素数 
		}
		for(int j = 1; j <= cnt && i * prime[j] <= 100001; j++){//枚举所有素数与i相乘 
			visit[i * prime[j]] = 1;
			if(i % prime[j] == 0) break;//减少冗余计算 
		}
	}
	
    int a, b;
    while(cin >> a >> b){
        for(int i = 1; i <= 100001; i++){
		    if(prime[i] >= a && prime[i] <= b){
                cout << prime[i];
                if(prime[i+1] > b){
                    cout << endl;
                    break;
                }
                else{
                    cout << " ";
                }
            }
        }
	}
}
```



## 2.炒鸡楼梯

分析：由题意分析第n阶阶梯可由n-2和n-1走来，即A(n) = A(n-2) + A(n-1)



## 3.求素数个数

思路：欧拉筛法求素数个数



## 4.幂次取余

分析：A^B mod C，因为a，b，c最大为1000000，所以先求A^B不行，因为求pow可以用分治法，所以每次分治的结果都取余，即可避免超过范围

```C++
#include<bits/stdc++.h>
using namespace std;

long long my_pow(long x,int n, int c)
{
    if(n==0)
    {
        return 1;
    }
    long long p=1;
    while(n>0)
    {
        if(n&1)//偶数                   
        {
            p = p * x % c;
        }
        x = (x % c) * (x % c) %c;
        n/=2;
    }
    return p % c;
}

int main() {
	int t;
	int a,b,c;
	cin >> t;
	while(t--){
		cin >> a >> b >> c;
		cout << my_pow(a%c, b, c) << endl;
	}	 
}
```

