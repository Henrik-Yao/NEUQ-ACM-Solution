#include<bits/stdc++.h>
using namespace std;
int prime[10010],cun[10010],hao[10010],cnt=0,a,b,flag;
void aipre(){//����ɸ 
	for(int i=2;i<=10000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			for(int j=i*i;j<=10000;j+=i)prime[j]=1;//��ÿ�������ı�������Ϊ���� 
		}//���ǲ��ܱ�֤ÿ��������ֻ������һ�� 
	}//ŷ��ɸ����ʵ����ÿ��������ֻ��������С�����Ӹ��� 
}
void oupre(){//ŷ��ɸ 
	for(int i=2;i<=10000;i++){
		if(prime[i]==0){
			cun[++cnt]=i;
			hao[i]=cnt;
		}
		for(int j=1;j<=cnt&&i*cun[j]<=10000;j++){
			prime[i*cun[j]]=1;
			if(i%cun[j]==0)break;//ŷ��ɸΪ��ÿ������ֻ���Լ�����С�����Ӹ��µ� 
		}//����֤�����i%prime[j]==0��j�������һ���ܱ������ĳ��i���µ� 
	}//�ٸ����� ��i = 8 ��j = 1��prime[j] = 2�����������ѭ����prime[j+1] = 3��8 * 3 = 2 * 4 * 3 = 2 * 12����i = 12ʱ�����
}
int main(){
	oupre();
	while(~scanf("%d%d",&a,&b)){//��scanfһ��Ҫ�ӣ�=EOF����ǰ��ȡ����cin���� 
		flag=0;
		for(int i=1;i<=cnt;i++){
			if(cun[i]>b)break;
			if(cun[i]>=a){
				if(flag==0){
					printf("%d",cun[i]);
					flag=1;
				}
				else{
					printf("% d",cun[i]);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
