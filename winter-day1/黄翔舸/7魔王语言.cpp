/*��->��1��2...��n
(�Ȧ�1��2...��n)->�Ȧ�n�Ȧ�n-1...�Ȧ�1��      */
#include<iostream>
#include<cstring>
using namespace std;
char temp[1001];
int main()
{
	string c;
	cin >> c;
	int u = c.length();
	for (int i = 0; i < u; i++)
	{
		if (c[i] == 'B')
		{
			cout << "tsaedsae";
		}
		else if (c[i] == 'A')
		{
			cout << "sae";
		}
		else if (c[i] == '(')
		{
			char te = c[i + 1];
			cout << te;
			int y = 0;
			for (int j = i + 2; j < u; j++)
			{
				if (c[j] != ')')
				{
					temp[y] = c[j];
					y++;
				}

				else { break; }

			}

			for (int j = y - 1; j >= 0; j--)
			{
				cout << temp[j] << te;
			}
			i = i + y + 1;
		}
	}
	cout << endl;
	return 0;
}