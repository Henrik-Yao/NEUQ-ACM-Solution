#include <bits/stdc++.h>
using namespace std;
//��״����
//lowbit����

long long  d[1000000],n;//��״�����ԭ���鳤��
long long lowbit(int x)
{
    return x&(-x);//�õ��������������λֵ
    
}
void update(int x,int y)//xΪλ���±꣬yΪ�޸�����ֵ
{
    for(int i=x;i<=n;i+=lowbit(i))
    {
        d[i]+=y; //ʵ�ָ���
    }
}
long long query(int x)//���ʴ�1��x������ͣ�ǰ׺�ͣ�
{
    long long sum=0;
    for(int i=x;i>0;i-=lowbit(i))
    {
        sum+=d[i];
    }
    return sum;
}
int main()
{
    int num;//������Դ���
    cin>>n>>num;
    for(int i=1;i<=n;i++)
    {
        int remp; 
        cin>>remp;
        update(i,remp);//ʵ�������ʼ��
    }
    for(int i=0;i<num;i++)
    {
        int remp;
        cin>>remp;
        int remp1,remp2;
        if(remp==1)
        {
            cin>>remp1>>remp2;
            update(remp1,remp2);//ʵ�ָ��²���
        }
        else
        {
            cin>>remp1>>remp2;
            cout<<query(remp2)-query(remp1-1)<<endl;
        }
    }

    return 0;
}