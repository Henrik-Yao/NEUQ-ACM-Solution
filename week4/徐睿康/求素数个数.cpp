#include<bits/stdc++.h>
using namespace std;
int cun[700010],hao[10000010],cnt=0,n;
bool prime[10000010];
void aipre(){//埃氏筛 
	for(int i=2;i<=10000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			for(int j=i*i;j<=10000;j+=i)prime[j]=1;//将每个质数的倍数处理为合数 
		}//但是不能保证每个合数都只被处理一次 
	}//欧拉筛可以实现让每个合数都只被它的最小质因子更新 
}
void oupre(){//欧拉筛 
	for(int i=2;i<=10000000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			hao[i]=hao[i-1]+1;
		}
		else hao[i]=hao[i-1];
		for(int j=1;j<=cnt&&i*cun[j]<=10000000;j++){
			prime[i*cun[j]]=1;
			if(i%cun[j]==0)break;//欧拉筛为让每个合数只被自己的最小质因子更新掉 
		}//可以证明如果i%prime[j]==0，j往后的数一定能被后面的某个i更新掉 
	}//举个例子 ：i = 8 ，j = 1，prime[j] = 2，如果不跳出循环，prime[j+1] = 3，8 * 3 = 2 * 4 * 3 = 2 * 12，在i = 12时会计算
}
int main(){
	oupre();
	scanf("%d",&n);
	printf("%d",hao[n]);
	return 0;
}
