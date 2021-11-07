### 7-3  **汉诺塔III** 

通过一一验证可得f(n)=3-f(n-1)+2的关系

代码如下：

```c++
#include<iostream>
using namespace std;
long long Hanio(int n)
{
	long long sum=2;
	if(n==1)
		return sum;
	else
	{
		sum=3*Hanio(n-1)+2;
		return sum;
	}
}
int main()
{
	int N;
	while(cin>>N)
	{
		long long s=Hanio(N);
		cout<<s<<endl;
	}
} 
```

