#include <iostream>
#include <cstring>
using namespace std;
struct Word{
	char data;
	Word* next=NULL;
	Word* prior=NULL;
};
int main(){
	Word * head=new Word;
	Word *p=new Word;
	p=head;
	head->prior=NULL;
	char ch;
	bool insert=false;
    string str;
    getline(cin,str);
	for(int i=0;i<str.size();i++){
        ch=str[i];
		if(ch=='['){
			p=head;
		}else if(ch==']'){
			while(p->next!=NULL) p=p->next;
		}else if(ch=='{'){
			if(p->prior!=NULL) p=p->prior;
		}else if(ch=='}'){
			if(p->next!=NULL) p=p->next;
		}else if(ch=='='){
			Word *need_delete=p;
			p=p->prior;
			if(need_delete->next!=NULL) need_delete->next->prior=p;
			else p->next=NULL;
			p->next=need_delete->next;
			delete need_delete;
		}else if(ch=='-'){
			if(insert==true) insert=false;
			else insert=true;
		}else{
			if(insert&&p->next!=NULL){
				p=p->next;
				p->data=ch;
			}else if(!insert){
				Word *newin=new Word;
				newin->data=ch;
				newin->prior=p;
				newin->next=p->next;
				if(p->next!=NULL){
					Word *nextdata=p->next;
					nextdata->prior=newin;
				}
				p->next=newin;
				p=p->next;
			}
		}
	}
	p=head->next;
	for(;p!=NULL;p=p->next) 
		cout << p->data;
	return 0;
}