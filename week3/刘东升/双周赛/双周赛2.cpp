#include<bits/stdc++.h>
using namespace std;
void move(int n,string a,string b,string c);//����һ����ģ�ͺ��� 
int main()
{
    int n;string a,b,c;cin>>n>>a>>b>>c;
    move(n,a,b,c);
    return 0;
}
void move(int n,string a,string b,string c)//��ģ��Ϊ�ƶ�n-1�����Ӻ����һ�����ӵ����� ��nΪ����������aΪ��ʼλ�ã�bΪ�м����ӣ�cΪ�������� 
{
	if(n==1){
		cout<<a<<"->"<<c<<endl; //�ƶ��������� 
	}
	else{
		move(n-1,a,c,b);//�ƶ����м� 
		cout<<a<<"->"<<c<<endl; 
		move(n-1,b,a,c); //���һ�� 
	}
} 
