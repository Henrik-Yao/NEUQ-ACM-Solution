#include  <stdio.h>
#define N 200                  // ������Ŀ������
void sort1(int value[],int n)  // ���������ǵ�����
{
	int i,j,t;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-1-i;j++)
			if(value[j]<value[j+1])
			{
				t=value[j];
				value[j]=value[j+1];
				value[j+1]=t;
			}
}
int main()
{
	int m,i,n;         // m��Ҫ���ǵ���������n�ǿ����ڸ��ǵ��߶���
	int position[N];  // ����Ҫ���ǵ�����
	int distance[N-1];  // �����������ľ���
	printf("������Ҫ���ǵ�������m= ");
	scanf("%d",&m);   // ����Ҫ���ǵ�������
	printf("������ %d ��Ҫ���ǵ����䣺 ",m);
	for(i=0;i<m;i++)
		scanf("%d",&position[i]);  // ����m������
	sort1(position,m);   // m�����併������
	for(i=0;i<m-1;i++)
		distance[i]=position[i]-position[i+1]-1;//���������������
	sort1(distance,m-1);  // m-1��������뽵������
	printf("�������ʹ�õ��߶ε�����n= ");
	scanf("%d",&n);  // �������ڸ��ǵ��߶���
	if(n>=m)
	     {
		printf("��С���߶��ܳ�Ϊ��%d\n",m);
		return 0;
	     }
	int nline=1;  // ��ǰ����������߶�����
	int totallength=position[0]-position[m-1]+1;
                    // ��ǰ����������߶��ܳ�
	int devide=0;  // ��ǰ����δ�Ͽ����������
	while((nline<n)&&  //  ��δ�ﵽ�����߶�����
                 (distance[devide]>0))  // ���в����ڵ�����

	     {
		nline++;           // ����һ���߶�
		totallength -= distance[devide]; // �ܳ�����
		devide++;     // ���Ǹ�������߶ζϿ���ָ����һ�����
	     }
	printf("��С�߶��ܳ�Ϊ��%d\n",totallength);
	return 0;
}
