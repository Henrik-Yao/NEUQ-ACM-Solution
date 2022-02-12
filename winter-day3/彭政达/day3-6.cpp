/*
7-6 ��С֧����
����һ������n���������Ȩ����ͼ�����Ϊ1��n�����д�����������С֧���������������Ȩ֮�͡�
�����ʽ:
��������������ݡ�ÿ�����ݵ�һ��Ϊ2������n��e����������1500���ֱ��ʾͼ�Ķ������ͱ�����
������e�б�ʾÿ���ߵ���Ϣ��ÿ��Ϊ3���Ǹ�����a��b��c������a��b��ʾ�ñߵĶ˵��ţ�
c��ʾȨֵ��������100�����߲��ǰ��˵���˳�����С�
�����ʽ:
����ÿ�����ݣ���������С֧���������һ��������Ϊ��С֧��������Ȩֵ֮�ͣ�
����������С֧�������������There is no minimum spanning tree.����
��������:
4 5
1 2 1
1 4 1
2 4 5
2 3 1
3 4 8
4 2
1 2 1
3 4 8
�������:
3
There is no minimum spanning tree.
*/
#include<bits/stdc++.h>
using namespace std;
int f[1555];
typedef struct node{
	int from,to,weight;
};
bool cmp(tree a,tree b){
	return a.weight<b.weight;
}
int find(int x){
	if(f[x]==x) return x;
	else return f[x]=find(f[x]);
}
void merge(int x,int y){
	int a=find(x),b=find(y);
	if(a!=b) f[a]=b;
}
int main(){
	int vertex,edge;
	ios::sync_with_stdio(false);
	freopen("in6.txt","r",stdin);
	while(cin>>vertex>>edge){
		node n[edge+1];
		int flag[1555]={0};
		int a,b,c;
		for(int i=0;i<vertex;i++) f[i]=i;
		for(int i=0;i<edge;i++){
			cin>>a>>b>>c;
			n[i].from=a;
			n[i].to=b;
			n[i].weight=c;
			merge(a,b);
			int x=find(a),y=find(b);
			if(a!=b) f[a]=b;
		}
		int num=0;
		for(int i=0;i<vertex;i++)
			if(f[i]==i) num++;
		if(num==1){
			sort(n,n+edge,cmp);
			int sum=0;
			for(int i=0;i<edge;i++)
				if(flag[n[i].from] && flag[n[i].to]) continue;
				else{
					flag[n[i].from]=flag[n[i].to]=1;
					sum+=n[i].weight;
				}
			cout<<sum<<endl;
		}
		else cout<<"There is no minimum spanning tree."<<endl;
	}
} 
