/*
7-2 �ɼ�����
����
��������ĳ�ſγ̵ĳɼ��������㰴�ɼ��Ӹߵ��ͶԳɼ������������
�������ͬ�����������ֵ���С����ǰ��
����
��һ��Ϊn (0 < n < 20)����ʾ�����ѧ����Ŀ�� ��������n�У�ÿ��Ϊÿ��ѧ�������ֺ����ĳɼ�, 
�м��õ����ո����������ֻ������ĸ�ҳ��Ȳ�����20���ɼ�Ϊһ��������100�ķǸ�������
���
�ѳɼ����������Ӹߵ��͵�˳��������������ÿ�а������ֺͷ������֮����һ���ո�
��������
4
Kitty 80
Hanmeimei 90
Joey 92
Tim 28
�������
Joey 92
Hanmeimei 90
Kitty 80
Tim 28
��ʾ
�����ʹ�ýṹ�壬ע�⣺ 1.�ṹ����������(ָ��)��Աʱ�ģ�
�ṹ�����֮��Ŀ������⣨������� 2.��ע�Ȿ������ԭ��
*/
#include <bits/stdc++.h>
using namespace std;
struct Stu{
	string name;
	int score;
}stu[24],temp;
int main(){
	int n;
	cin>>n;
	for(int i=0;i<n;i++) cin>>stu[i].name>>stu[i].score;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			if(stu[i].score<stu[j].score || (stu[i].score==stu[j].score && stu[i].name>stu[j].name)){
				temp=stu[i];
				stu[i]=stu[j];
				stu[j]=temp;
			}
	for(int i=0;i<n;i++) cout<<stu[i].name<<" "<<stu[i].score<<endl; 
}
