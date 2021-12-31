#include<iostream>
#include<stdlib.h> 
using namespace std;
int sum[100];//和
int cs = 1;//层数

struct TT
{
	int data;
	struct TT* lc, * rc;
};

TT* createtree()
{
	int data;
	TT* T1;
	cin >> data;
	if (!data)T1 = NULL;
	else
	{
		T1 = (TT*)malloc(sizeof(TT));
		T1->data = data;
		T1->lc = createtree();
		T1->rc = createtree();
	}
	return T1;
}

void P(TT* B)
{
	if (B)//如果B不为NULL
	{
		if (!B->lc && !B->rc)//没娃
			sum[cs] += B->data;
		P(B->lc);
		P(B->rc);
		if (B->lc && B->rc)cs++;
	}
}

int main()
{
	TT* T = NULL;
	T = createtree();

	if (T->lc == NULL && T->rc == NULL)//没娃
	{
		cout << "0";
	}
	else
	{
		P(T);
		int he = 0, c = 0;
		for (int i = 0; i < cs; i++)
			if (sum[i] >= he)
			{
				he = sum[i];
				c = i;
			}
		cout << c;
	}
}