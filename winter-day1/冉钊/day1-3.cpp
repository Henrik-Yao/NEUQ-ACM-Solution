#include<bits/stdc++.h>
using namespace std;
int m,nn,k;
int flag=1;
bool ope=1;//1=逆时针报数m；0=顺时针报数k；
 struct peo {
    int id;
    peo *next,*front;
    peo(){
        next=front=NULL;
    }
}n[1000];
void ccut(peo *now){
    now->front->next=now->next;
    now->next->front=now->front;
}//出列操作实现函数
int main(){
    cin>>nn>>m>>k;
    peo *now=n;//计数的指针，初始指向第一个小朋友
    
    for(int i=1;i<nn-1;i++){
        n[i].front=n+i-1;
        n[i].next=n+i+1;
        n[i].id=i+1;
    }
    n[0].id=1;n[0].front=n+nn-1;n[0].next=n+1;
    n[nn-1].id=nn;n[nn-1].front=n+nn-2;n[nn-1].next=n;//双向循环链表初始化

    while(nn>0){
        if(ope){
             if(flag==m){
                cout<<now->id<<" ";
                ccut(now);
                flag=1;
                nn--;
                now=now->front;
                ope=0;
             }
             else{
                 flag++;
                 now=now->front;
             }
        }
        else{
            if(flag==k){
                cout<<now->id<<" ";
                ccut(now);
                flag=1;
                nn--;
                now=now->next;
                ope=1;
            }
            else{
                flag++;
                now=now->next;
            }
        }
       
    }
    
    return 0;
}