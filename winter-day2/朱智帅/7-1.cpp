#include<iostream>
using namespace std;
typedef struct TNode
{
	int data;
	int hight;
	TNode* L, * R;
}*Tree;
Tree T[105];
int Pre[105];
int highsum[105] = { 0 };
bool ifhavelef[105] = { 0 };
int maxhigh = -1;
int cnt = 0;
void BuildTree(int high, Tree& T)
{
	if (Pre[cnt])
	{
		if (high > maxhigh) maxhigh = high;
		T = (Tree)malloc(sizeof(TNode));
		T->data = Pre[cnt];
		T->hight = high;
		T->L = NULL;
		T->R = NULL;
		cnt++;
		BuildTree(high + 1, T->L);
		cnt++;
		BuildTree(high + 1, T->R);
		if (!T->L && !T->R)
		{
			highsum[high] += T->data;
			ifhavelef[high] = 1;
		}
	}
}
void Pres(Tree T)
{
	if (T)
	{
		cout << T->data << " ";
		cout << T->hight << " ";
		cout << endl;
		Pres(T->L);
		Pres(T->R);
	}
	else cout << "0 " << "NULL" << endl;
}
int main()
{
	int i = 0, j = 0;
	while (cin >> Pre[i]) i++;
	Tree T, Head = (Tree)malloc(sizeof(TNode));
	BuildTree(0, T);
	//Pres(T);
	Head->data = NULL;
	Head->L = T;
	Head->R = NULL;
	Head->hight = -1;
	//cout << maxhigh << endl;
	int tag;
	for (i = 0; i <= maxhigh; i++)
	{
		if (ifhavelef[i])
		{
			tag = i;
			break;
		}
	}
	for (i = 0; i <= maxhigh; i++)
	{
		if (ifhavelef[i] && highsum[i] >= highsum[tag]) tag = i;
		//cout << ifhavelef[i] << " " << highsum[i] << endl;
	}
	cout << tag << endl;
	return 0;

}