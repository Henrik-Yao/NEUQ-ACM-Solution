/*1.4 ��д������������������������С���������1����ͷ��㵥����
���һ��ʵ�ֵ���������㷨��Split��������ԭ��������ֵΪż���Ľ���������γ�һ���µ�����
�µ�������ͷ����������룬����������ԭ���������ԭ������ֻʣ��ż��ֵ���ڽ�㣬
�����ʾ2���������ڳ����˳�ǰ���ٵ�����Ҫ��Split�㷨ʱ�临���ԴﵽO��n��,���򲻿ɴ����ڴ�й©��
�����ʽ:������������
�����ʽ:
ÿ�����������ռһ�У�Ԫ�ؼ��÷ָ���->�ָ�����ʼ������ʣ��Ԫ�ص�����ż��Ԫ�ص�������3�С�
��������:
100 2 3  50 2 1 5 8
�������:
1->2->2->3->5->8->50->100
1->3->5
2->2->8->50->100
*/
#include <bits/stdc++.h>
using namespace std;
list<int> a;
struct node{
	int data;
	struct node *next;
};
void init(struct node *n){
	int len=a.size();
	for(int i=0;i<len;i++){
		struct node* pt=(struct node*)malloc(sizeof(struct node));
		pt->data=a.front();
		a.pop_front();
		pt->next=NULL;
		n->next=pt;
		n=n->next;
	}
}
int main(){
	freopen("in.txt","r",stdin);
	ios::sync_with_stdio(false);
	int b,flag=0;
	while(cin>>b) a.push_back(b);
	a.sort();
	struct node* head=(struct node*)malloc(sizeof(struct node));
	head->next=NULL;
	init(head);
	for(node* p=head->next;p!=NULL;p=p->next){
		cout<<p->data;
		if(p->next!=NULL) cout<<"->";
	}
	cout<<endl;
	for(node* p=head->next;p!=NULL;p=p->next)
		if(p->data%2){
			if(flag) cout<<"->";
			cout<<p->data;
			flag=1;
		}
	cout<<endl;
	flag=0;
	for(node* p=head->next;p!=NULL;p=p->next)
		if(p->data%2==0){
			if(flag) cout<<"->";
			cout<<p->data;
			flag=1;
		}
	cout<<endl;
}
