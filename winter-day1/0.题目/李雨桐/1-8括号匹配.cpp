#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
	while(cin>>s)
	{
		int num1=0,num2=0;
		int lens=s.length();

		for (int i=0;i<lens;i++)
		{
			if (s[i] == '(')
				num1++;
			if (s[i] == ')')
			{
				if (num1>0)
                    num1--;
				else num2++;
			}
		}

		if ( num1==0 && num2==0 )
            cout << "Match" ;
		else
		{
			cout<<num1+num2<<endl;
			for (int i=0;i<num2;i++)
                cout << "(";
            cout << s;
			for (int i=0;i<num1;i++)
                cout << ")";
		}
		cout << endl;
	}
}
