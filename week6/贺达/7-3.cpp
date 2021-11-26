#include<bits/stdc++.h>
using namespace std;

vector<string> v;
int cnt = 0;

int main()
{
	char c;
	string t = "";
	do
	{
		c=getchar();
		if(!isalpha(c))
		{
			if(t.size()>0) v.push_back(t);
			t = "";
		}
		else
        {
            t += tolower(c);//转成小写
        }
	}while(c!='\n');//读到行尾

	cin >> t;
	std::transform(t.begin(), t.end(), t.begin(), ::tolower);

	for(auto x:v)
	{
		if(x.find(t)!=-1) cnt++;
	}
	cout << cnt;
}

