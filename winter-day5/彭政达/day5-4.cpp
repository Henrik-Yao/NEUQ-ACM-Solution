/*
7-4 ���ֲ���
����nֵ(1<=n<=1000)��n���ǽ������е������Լ�Ҫ���ҵ���x��ʹ�ö��ֲ����㷨����x��
���x���ڵ��±꣨0~n-1�����Ƚϴ�������x�����ڣ����-1�ͱȽϴ�����
�����ʽ:
���빲���У� ��һ����nֵ�� �ڶ�����n�������� ��������xֵ��
�����ʽ:
���x���ڵ��±꣨0~n-1�����Ƚϴ�������x�����ڣ����-1�ͱȽϴ�����
��������:
4
1 2 3 4
1
�������:
0
2
*/
#include<iostream>
using namespace std;
int main(){
	int l,r,m,count=0,n,x,a[1005];
	cin>>n;
	for(int i=0;i<n;i++) cin>>a[i];
	cin>>x;
	l=0,r=n-1;
	while(l<=r){
		count++;
		m=l+((r-l)/2);
		if(a[m]>x) r=m-1;
		else if(a[m]<x) l=m+1;
		else break;
	}
	if(l>r) cout<<"-1";
	else cout<<m;
	cout<<endl<<count;
}
