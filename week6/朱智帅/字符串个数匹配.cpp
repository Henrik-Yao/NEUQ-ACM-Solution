#include<iostream>
#include<string>
#include<cmath>
#include<string.h>
using namespace std;
int nextval[100001];
string B;
char A[1001][1001];
int sum = 0, lenA = 0;
void get_nextval()
{
	int i = 0, j = -1;
	nextval[i] = j;
	while (i < B.size() - 1)
	{
		if (j == -1 || B[i] == B[j])
		{
			++i, ++j;
			if (B[i] != B[j]) nextval[i] = j;
			else nextval[i] = nextval[j];
		}
		else j = nextval[j];
	}
}
void KMP(string Ai)
{
	int i, j;
	i = 0, j = 0;
	int lenB = B.size();
	while (i < Ai.size() && j < lenB)
	{
		if (j == -1 || Ai[i] == B[j] || fabs(Ai[i] - B[j]) == int('a' - 'A'))
		{
			i++;
			j++;
		}
		else
		{
			j = nextval[j];
		}
	}
	if (j == B.size())
	{
		sum++;
	}
}
int main()
{
	int i = 0, j = 0;
	char c;
	for (; (c = getchar()) != '\n';)
	{
		if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z')
		{
			A[j][i++] = c;
		}
		else
		{
			if (i)
			{
				j++;
				i = 0;
			}
		}
		
	}
	j++;
	cin >> B;
	get_nextval();
	for (i = 0; i < j; i++)
	{
		lenA = strlen(A[i]);
		KMP(A[i]);
	}
	cout << sum;
	return 0;
}