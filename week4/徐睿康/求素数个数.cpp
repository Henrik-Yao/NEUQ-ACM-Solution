#include<bits/stdc++.h>
using namespace std;
int cun[700010],hao[10000010],cnt=0,n;
bool prime[10000010];
void aipre(){//����ɸ 
	for(int i=2;i<=10000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			for(int j=i*i;j<=10000;j+=i)prime[j]=1;//��ÿ�������ı�������Ϊ���� 
		}//���ǲ��ܱ�֤ÿ��������ֻ������һ�� 
	}//ŷ��ɸ����ʵ����ÿ��������ֻ��������С�����Ӹ��� 
}
void oupre(){//ŷ��ɸ 
	for(int i=2;i<=10000000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			hao[i]=hao[i-1]+1;
		}
		else hao[i]=hao[i-1];
		for(int j=1;j<=cnt&&i*cun[j]<=10000000;j++){
			prime[i*cun[j]]=1;
			if(i%cun[j]==0)break;//ŷ��ɸΪ��ÿ������ֻ���Լ�����С�����Ӹ��µ� 
		}//����֤�����i%prime[j]==0��j�������һ���ܱ������ĳ��i���µ� 
	}//�ٸ����� ��i = 8 ��j = 1��prime[j] = 2�����������ѭ����prime[j+1] = 3��8 * 3 = 2 * 4 * 3 = 2 * 12����i = 12ʱ�����
}
int main(){
	oupre();
	scanf("%d",&n);
	printf("%d",hao[n]);
	return 0;
}
