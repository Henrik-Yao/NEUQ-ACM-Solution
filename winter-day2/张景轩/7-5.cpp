#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;

priority_queue<int ,vector<int>,greater<int> > q;

int main()
{
	int n;
	char str[100];
	int p[100];
	cin>>n;
	for(int i=0;i<n;i++)
    {
		getchar();
		cin>>str[i]>>p[i];
		q.push(p[i]);
	}
	int ans=0;


	while(q.size() > 1)
    {
		int x;
        x = q.top();
		q.pop();
		int y;
        y = q.top();
		q.pop();
		q.push(x + y);
		ans =ans + x + y;
	}
	int m;

	cin>>m;
	for(int i=0;i<m;i++)
    {
		char s[100][100];
		int sum = 0;
		for(int j=0;j<n;j++)
        {
			getchar();
			char c;
			cin>>c>>s[j];
			sum = sum + strlen(s[j])*p[j];
		}

		if(sum!=ans)
        {
            cout<<"No\n";
        }
		else
        {
			int flag=0;

			for(int j=0;j<n;j++)
            {
				int x = strlen(s[j]);
				for(int l=0;l<n;l++)
                {
					if(j!=l)
                    {
						if(strstr(s[l],s[j])==&s[l][0])
                        {
							flag=1;
							break;
						}
					}
				}
				if(flag==1)
                {
                    break;
                }
			}
			if(flag==1)
            {
                cout<<"No\n";
            }
			else
            {
                cout<<"Yes\n";
            }
		}
	}
	return 0;
}
