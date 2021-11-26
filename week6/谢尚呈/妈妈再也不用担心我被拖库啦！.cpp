#include<iostream>
#include<string>
using namespace std;

char pre(string it);
string has(string it);


struct us{
	string name;
	string pass;
	string hash;
	
	void regin(string na, string pa)
	{
		name=na;
		pass=pa;
		hash=has(pa);
	}
}user[1000];

int main()
{
	int n;
	cin>>n;
	int now=0;
	string all;
	for(int i=0; i<n; i++)
	{
		string a, b, c;
		cin>>a>>b>>c;
		switch(a[0])
		{
			case 'R':
				{
					bool fit=true;
					for(int j=0; j<now; j++)
					if(user[j].name==b)
					{
						fit=false;
						break;
					}
					if(fit)
					{
						user[now].regin(b, c);
						now+=1;
						all+="Signed!";
					}
					else	all+="Repeated!";
					break;
				}
			case 'L':
				{
					string hass=has(c);
                    bool fit=false;
					for(int j=0; j<now; j++)
					if(user[j].name==b)
					{
						if(user[j].hash==hass)
						if(user[j].pass==c)	all+="Success!";
						else	all+="Attention!";
						else	all+="Failed!";
                        fit=true;
                        break;
					}
                    if(fit);
                    else all+="Failed!";
				}
		}
        if(i!=n-1)  all+="\n";
	}
	cout<<all;
	return 0;
}

char pre(string it)
{
	int re=0;
	for(int i=0;i<it.length();i++)
	{
		if(it[i]>='A'&&it[i]<='Z')	it[i]+='a'-'A';
		if(it[i]>='0'&&it[i]<='9')	re+=it[i]-'0';
		else	re+=it[i]-'a'+10;
	}
	re%=36;
	return (re<10)?(re+'0'):(re-10+'a');
}

string has(string it)
{
	string pas="0000";
	int len=it.length();
	int index[5]={0};
	for(int i=0; i<len%4; i++)	index[i]++;
	int j=0;
	for(int i=0; i<4; i++)
	{
		index[i]+=len/4;
		string tools=it.substr(j, index[i]);
		j+=index[i];
		char h=pre(tools);
		pas[i]=h;
	}
	return pas;
}
