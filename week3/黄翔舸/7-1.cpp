#include <iostream>
using namespace std;
#define w 100

typedef struct
{
	int num[w][w];//�ڽӾ���
	int dian, bian; //ͼ��ǰ�ĵ����ͱ���
}Graph;

int main()
{
	int n;//n����ȫ����
	Graph G;

	cin >> G.dian >> n >> G.bian;//������еĸ�������ȫ���еĸ�����·�ĸ���
	int safecity[w];//��ȫ����
	for (int i = 0; i < n; i++)
	{
		cin >> safecity[i];
	}
	for (int i = 0; i < G.dian; i++)
	{
		for (int j = 0; j < G.dian; j++)
		{
			G.num[i][j] = 0;//��ʼ���ڽӾ���Ϊ0
		}
	}
	for (int i = 0; i < G.bian; i++)
	{
		int x, y;
		cin >> x >> y;
		G.num[x][y] = 1;//����·�ĳ���֮��Ȩֵ��Ϊ1
		G.num[y][x] = 1;
	}
	int now, destination, flag = 0;//���ڳ��к�Ŀ�ĵ�
	cin >> now >> destination;
	for (int i = 0; i < n; i++)
	{
		if (destination == safecity[i])//��ѯĿ�ĵ��Ƿ�Ϊ��ȫ���У����ϱ��
		{
			flag = 1;
			break;
		}
	}
	if (G.num[now][destination] == 1)
	{
		if (flag)//�ǰ�ȫ���в�����ͨ·
			cout << "The city " << destination << " can arrive safely!";
		else //��ͨ·���ǲ��ǰ�ȫ����
		{
			cout << "The city " << destination << " is not safe!";

		}
	}
	else
	{
		if (flag)//�ǰ�ȫ���е���û��ͨ·
			cout << "The city " << destination << " can not arrive safely!";
		else cout << "The city " << destination << " is not safe!";//���ǰ�ȫ����Ҳû��ͨ·
	}
	return 0;
}
