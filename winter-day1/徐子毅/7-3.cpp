#include <iostream>
using namespace std;
struct kids{
	int num;
	kids*next=NULL;
	kids*prior=NULL;
};
int main(){
	int N,M,K;
	cin >> N >> M >> K;
	kids * head=new kids;
	kids * p = new kids;
	p=head;
	for(int i=1;i<=N;i++){
		kids* newkids=new kids;
		newkids->num=i;
		newkids->prior=p;
		p->next=newkids;
		p=p->next;
	}
	p->next=head->next;
	head->next->prior=p;
	int playing=N;
	bool right_circle=true;
	p=p->next;
	while(playing>0){
		if(right_circle){
			for(int T=1;T<M;T++) 
			p=p->prior;
			kids * need_delete=p;
//			if(need_delete==head->next) head->next=need_delete->next;
			p=p->prior;
			p->next=need_delete->next;
			need_delete->next->prior=p;
			playing--;
			cout << need_delete->num << " ";
			right_circle=false;
		}else{
			for(int T=1;T<K;T++) p=p->next;
			kids * need_delete=p;
//			if(need_delete==head->next) head->next=need_delete->next;
			p=p->next;
			p->prior=need_delete->prior;
			need_delete->prior->next=p;
			playing--;
			cout << need_delete->num << " ";
			right_circle=true;
		}
		
	}
//	cout << head->next->num << endl;
	return 0;
}