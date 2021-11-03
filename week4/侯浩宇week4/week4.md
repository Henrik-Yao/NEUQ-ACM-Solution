### 1.**素数**

两次循环求素数，注意的是外层循环从a到b。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	int a,b,p[10000],num,num1;
	while(cin>>a>>b){
		num=b-a+1;
		for(int i=a;i<=b;i++){
				for(int j=2;j<=sqrt(i);j++){
					p[i]=0;
	//				cout<<i<<"%"<<j<<"="<<i%j<<endl;
					if(i%j==0){
						p[i]=1;
						num--;
						break;
					}
				}
		}
		num1=0;
		for(int i=a;i<=b;i++){
		//	cout<<!p[i];
			if(!p[i]){
			cout<<i,num1++;	
			if(num1<num) cout<<" ";/**/
			}
			
		}
		cout<<endl;
	}
	return 0;
}
```

### 2.**炒鸡楼梯**

可化为斐波那契数列问题，注意的是从1阶开始，既f【1】=0。

```c++
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m;
	long long a[41];
	cin>>n;
	a[1]=0;a[2]=1;a[3]=2;
	for(int i=4;i<=40;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(int i=0;i<n;i++){
		cin>>m;
		cout<<a[m]<<endl;
	}
	return 0;
}
```

### 3.**求素数个数**

用埃氏筛法即可。

从2开始，将每个质数的倍数都标记成合数，以达到筛选素数的目的。

这里有一个小优化，j 从 i * i 而不是从 i + i开始，因为 i*(2~ i-1)在 2~i-1时都已经被筛去，所以从i * i开始。

```c++
#include<bits/stdc++.h>
using namespace std;
int visit[10000000];  
void Prime(int n){
    for(int i=2;i<=n;i++)
	visit[i]=0;         
    visit[0] = visit[1] = 1;  
    for (int i=2;i<=sqrt(n);i++) {
        if (!visit[i]) {         
            for (int j=i*i;j<=n;j+=i) { 
                visit[j] = 1;
            }
        }
    }
}
int main(){
	int n,ans=0;
	cin>>n;
	Prime(n);
	for(int i=2;i<=n;i++){
		if(!visit[i]) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
```

### 4.**幂次取余**

每次乘a时，使a对c取余，值不变，可避免溢出。

```c++
#include<bits/stdc++.h>
using namespace std;

int main(){
	long long t,a,b,c;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>c;
		long long ans=1;
		for(int j=0;j<b;j++)
		ans*=a,ans%=c;
		cout<<ans<<endl;
	}
	return 0;
}
```

