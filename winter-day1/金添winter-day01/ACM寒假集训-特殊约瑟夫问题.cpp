#include <bits/stdc++.h>
using namespace std;
//˫��ѭ������
struct node
{
    int num;
    node *last;
    node *next;
};
int main()
{
    int n,M,K;
    cin>>n>>M>>K;
    node *head,*insert,*connect;
    head= new node;
    head->num=1;head->next=NULL;head->last=NULL;
    connect=head;
    for(int i=2;i<=n;i++)//����˫��������(��ͼ������)
    {
        insert=new node;
        insert->num=i;
        insert->next=NULL;
        connect->next=insert;
        insert->last=connect;
        connect=connect->next;
    }
    connect->next=head;
    head->last=connect;
    connect=head;
    
    node *man=head;
    bool round=0;//��ʼ����ʱ��
    while(man!=man->next)//����ֻʣ��һ����ʱ������ѭ��
    {
        if(round==0)//M ��ʱ��
        {
            if(M==1)
            {
                cout<<man->num<<" ";
                man->next->last=man->last;
                man->last->next=man->next;
                man=man->last;
            }
            else
            {
                for(int i=2;i<M;i++)
                {
                    man=man->last;
                }//ͨ��n-2���ҵ��Ǹ���̭�ߵĺ�һ����
                cout<<man->last->num<<" ";//������ߺ���
                man->last=man->last->last;
                man->last->next=man;
                man=man->last;
            }
            round=1;
        }
        else        //N ˳ʱ��
        {
            if(K==1)
            {
                cout<<man->num<<" ";
                man->next->last=man->last;
                man->last->next=man->next;
                man=man->next;
            }
            else
            {
                for(int i=2;i<K;i++)//��λ����̭��ǰһ��
                man=man->next;
                cout<<man->next->num<<" ";
                man->next=man->next->next;
                man->next->last=man;
                man=man->next;
            }
            round=0;
        }
    }
    cout<<man->num;
    return 0;
}