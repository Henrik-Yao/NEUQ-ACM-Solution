/*
7-1 ͼ�Ĵ���
���д���򴴽�һ������ͼ������ͼ�а���n�����㣬���Ϊ0��n-1��
�����ʽ:
�����һ��Ϊ����������n��e���ֱ��ʾͼ�Ķ������ͱ���������n������20000��e������20000��
������e�б�ʾÿ���ߵ���Ϣ��ÿ��Ϊ3���Ǹ�����a��b��c������a��b��ʾ�ñߵĶ˵��ţ�c��ʾȨֵ��
���߲��ǰ��˵���˳�����С�
�����ʽ:
�������ŵ���˳�����ÿ�����������ıߣ�ÿ������ռһ�У���ĳ����û�������ߣ��������
ÿ�б�ʾһ���������������бߣ���ʽΪa:(a,b,w)��������ʾ�����a->b��ȨֵΪw��
a�����Ķ����߰����b�ĵ��������С�
��������:
7 7
0 1 5
0 3 7
0 6 6
1 2 4
2 5 1
3 5 3
6 5 4
�������:
0:(0,1,5)(0,3,7)(0,6,6)
1:(1,2,4)
2:(2,5,1)
3:(3,5,3)
6:(6,5,4)
*/
#include<bits/stdc++.h>
using namespace std;
struct node{
	int from,to,weight;
};
bool cmp(node a, node b){
	if(a.from!=b.from) return a.from<b.from;
	else return a.to<b.to;
}
node a[20005];
int count[20005];
int main(){
    ios::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	for (int i=0;i<m;i++){
		cin>>a[i].from>>a[i].to>>a[i].weight;
		count[a[i].from]++;
	}
	sort(a,a+m,cmp);
	for(int i=0;i<n;++i){
		if(!count[i]) continue;
		int sum=count[i];
		cout<<a[i].from;
		for(int j=0;j<sum;j++) cout<<"("<<a[j].from<<","<<a[j].to<<","<<a[j].weight<<")";
		cout<<endl;
	}
}
