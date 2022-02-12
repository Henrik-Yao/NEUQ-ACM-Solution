#include<iostream>
#include<queue>
#include<vector>
using namespace std;
typedef struct Link
{
	int data;
	Link* next, * end;
}*LinkList;
int main() 
{
	int n, m, i, a, b;
	while (cin >> n >> m)
	{
		int cnt = 0;
		int visited[10005] = { 0 };
		int Indegree[10005] = { 0 };
		int tag = 1;
		
		
		LinkList L[10005];
		for (i = 1; i <= n; i++)
		{
			L[i] = (LinkList)malloc(sizeof(Link));
			L[i]->data = i;
			L[i]->next = NULL;
			L[i]->end = L[i];
		}
		for (i = 0; i < m; i++)
		{
			cin >> a >> b;
			Indegree[b]++;
			LinkList l = (LinkList)malloc(sizeof(Link));
			l->data = b;
			l->next = NULL;
			L[a]->end->next = l;
			L[a]->end = l;
		}
		while (cnt != n)
		{
			vector<int>p;
			for (i = 1; i <= n; i++)
			{
				//cout << "i:" << i << "   Indegree:" << Indegree[i] << endl;
				if (Indegree[i] == 0&&!visited[i])
				{
					cnt++;
					p.push_back(i);
					visited[i] = 1;
				}
			}
			int k = p.size();
			while(k--)
			{
				LinkList q = L[p[k]];
				while (q->next)
				{
					q = q->next;
					Indegree[q->data]--;
				}
			}
			//cout << "size:" << p.size() << endl;
			if (p.size() == 0 && cnt != n)
			{
				//cout << "cnt:" << cnt << endl;
				cout << "0" << endl;
				tag = 0;
				break;
			}
			else if (p.size() >= 2) tag = 2;			
			if (tag == 0) break;
		}
		if (tag == 2) cout << "2" << endl;
		else if(tag==1) cout << "1" << endl;
	}
	return 0;
}