#include<iostream>
#include<vector>
#include<string.h>
#include<set>
#include<string>
#include<algorithm>
using namespace std;
string A, B;
int visit[256] = { 0 };
void Delete()
{
	int i, j, lena = A.size();
	for (i = 0; i < lena; i++)
	{
		if (visit[A[i]] == 0) cout << A[i];
	}
	cout << endl;
}
int main()
{
	while (getline(cin, A))
	{
		int i = 0;
		char c;
		getline(cin, B);
		//cout << "A:"<<A << endl << "B:"<<B << endl;
		for (i = 0; i < B.size(); i++)
			visit[B[i]] = 1;
		Delete();
		memset(visit, 0, sizeof(visit));

	}
	return 0;
}