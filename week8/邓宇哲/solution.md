# ����ʧԼ
����û��̰���㷨����ʹ�����������������Ϊ��ȷ�����ҵ����Ž⡣  
����date�࣬�������Ŀ�ʼʱ�䣬����ʱ�䣬������ɲμӻ����������������ɲμӵĻ���ı�š���ͼ���������������ʾ�μӻ����������
```c++
#include <algorithm>
#include <iostream>
using namespace std;
class date
{
public:
	int start, end, num = 0;
	int next[128] = {0};
};
bool compare(date a, date b)//�Զ�������ĺ���
{
	return a.start < b.start;
}
void dfs(date *, int);
int deep = 1;//���浱ǰ������ȵı���
int maxt;//�������������ȵı���
main()
{
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> t;
		maxt = 0;
		date node[t];
		for (int j = 0; j < t; j++)//����
		{
			cin >> node[j].start >> node[j].end;
		}
		sort(node, node + t, compare);//��Ҫ������ʼʱ����б������
		for (int j = 0; j < t - 1; j++)//�������л��飬��ÿ��������� ���������ܲμӵĻ��顯 ����Ϣ
		{
			for (int k = j + 1; k < t; k++)
			{
				if (node[k].start >= node[j].end)
				{
					node[j].next[node[j].num++] = k;
				}
			}
		}
		for (int j = 0; j < t; j++)//��ÿ��������������������������������
		{
			dfs(node, j);
		}
		cout << t-maxt<<endl;
	}
}
void dfs(date *node, int n)
{
	maxt = max(maxt, deep);
	{
		for (int i = 0; i < node[n].num; i++)//��ÿ�����顮�������ܲμӵĻ��顯������������¼���
		{
			deep++;
			dfs(node, node[n].next[i]);
			deep--;
		}
	}
}
```
# ��һ��
����������Ȼ��ѿ���ֻ��̰���ˡ�
�Ƚϡ���һ�����ߵ��ĵ��ܵ������Զλ�á������к��ʵĵ�ѡ��
```c++
#include <iostream>
using namespace std;
main()
{
    long n, step = 0;
    long long maxt;//��¼���ŵ�λ����
    cin >> n;
    long long *list = new long long[n];
    for (int i = 0; i < n; i++)
    {
        cin >> list[i];
    }
    long point = 0;
    bool sign=0;
    while (point < n - 1)
    {
        maxt =0;
        step++;
        for (long i = point + 1; (i <= point + list[point]) && i < n; i++)
        {   
            if(list[point]+point>=n-1)//û������ж�ֱ�ӳ�ʱ������
            {
                sign = 1;
                break;
            }
            if(list[i] + i>=list[maxt+point]+point+maxt)
            {
                maxt = i-point;
            }
        }
        if(sign==1)
        {
            break;
        }
        point += maxt;
        
    }
    cout << step ;
    delete[] list;//������ɾ��
}
```