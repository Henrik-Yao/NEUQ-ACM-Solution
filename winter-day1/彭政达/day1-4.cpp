/*1.4 编写程序，输入若干正整数，按从小到大次序建立1个带头结点单链表，
设计一个实现单链表分离算法的Split函数，将原单链表中值为偶数的结点分离出来形成一个新单链表，
新单链表中头结点重新申请，其余结点来自原链表，分离后，原链表中只剩非偶数值所在结点，
最后显示2个单链表，在程序退出前销毁单链表。要求Split算法时间复杂性达到O（n）,程序不可存在内存泄漏。
输入格式:若干正整数。
输出格式:
每个单链表输出占一行，元素间用分隔符->分隔；初始单链表、剩余元素单链表、偶数元素单链表，共3行。
输入样例:
100 2 3  50 2 1 5 8
输出样例:
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
