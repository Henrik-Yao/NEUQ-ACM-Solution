#include<iostream>
#include<string>
using namespace std;

int index[100001];

void set_index(string cop)
{
	int on=0, to=-1;
    index[0]=-1;   
    int len=cop.length();
    
    while(on<len)
    if(to==-1||cop[on]==cop[to])
	{
       	on+=1;
    	to+=1;
       	index[on]=to;
    }
    else	to=index[to];     
}

int find(string ori, string cop)
{
	int nex=0,now=0, total=0;
	int leno=ori.length();
	int lenc=cop.length();
	while(now<leno)
	{
		if(ori[now]==cop[nex]||nex==-1)
		{
			now+=1;
			nex+=1;
		}
		else	nex=index[nex];
		if(nex==lenc)	total+=1;		
	}
	return total;
}

int main ()
{
	string org, cop;
	cin>>org>>cop;
	set_index(cop);
	cout<<find(org, cop);
	return 0;
}


