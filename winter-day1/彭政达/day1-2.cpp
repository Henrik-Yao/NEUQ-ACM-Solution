#include <bits/stdc++.h>
using namespace std ;
struct Node{
	char c;
	struct Node* front, *next;
	Node(char a):c(a) {}
};
typedef Node* List;
List Cr(){
	List l=new Node(0);
 	l->next=l->front=l;
	return l;
}
int main(){
	List x=Cr(),p=x;
	char c; 
	int isinsert=1;
	while(c=getchar()){
		if((c>='a' && c<='z') || c==' '){
			if(!isinsert){
				p->next->c=c;
				p=p->next;
				continue;
			}
			List q=new Node(c);
			q->c=c;
			q->next=p->next;
			q->next->front=q;
			p->next=q;
			q->front=p;
			p=q;
		}
		else if(c=='[') p=x;
		else if(c==']') p=x->front;
		else if(c=='{') if(p!=x) p=p->front;
		else if(c=='}') if(p->next!=x) p=p->next; 
		else if(c=='-') isinsert^= 1;
		else if(p!=x){
				p=p->front;
				p->next=p->next->next;
				p->next->front=p;
			}
	}
	for(List p=x->next;p!=x;p=p->next) cout<<p->c;
	cout<<endl;
}
