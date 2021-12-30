#include <iostream>
#include <map>
using namespace std;
struct People
{
	string firstname;
	string seccondname;
	int order;
	int orderoffather = -1;
	bool isman = 1;
};
map<string, int> name2order;
People list[100];
int path[100],p=0;
int path2[100], p2 = 0;
int deep=0,deep2=0;
void dls(int);
void dls2(int);
main()
{
	int n;
	cin >> n;
	string firstname, secondname;
	for (int i = 0; i < n; i++)
	{
		cin >> firstname >> secondname;
		name2order.insert({firstname, i});
		list[i].firstname = firstname;
		list[i].seccondname = secondname;
		if (secondname[secondname.length() - 1] == 'f' || secondname[secondname.length() - 1] == 'r')
		{
			list[i].isman = 0;
		}
		if (list[i].seccondname[secondname.length() - 1] == 'f' || list[i].seccondname[secondname.length() - 1] == 'm')
		{
			list[i].seccondname.pop_back();
		}
		if (list[i].seccondname[secondname.length() - 1] == 'r')
		{
			list[i].seccondname.erase(secondname.length() - 7,secondname.length() - 1);
		}
		if (list[i].seccondname[secondname.length() - 1] == 'n')
		{
			list[i].seccondname.erase(secondname.length() - 4,secondname.length() - 1);
		}
		list[i].orderoffather = name2order[list[i].seccondname];
	}
	cin >> n;
	string a, b, c, d;
	for (int i = 0; i < n;i++)
	{
		cin >> a >> b >> c >> d;
		if(list[name2order[a]].seccondname != b||list[name2order[c]].seccondname != d)
		{
			cout << "NA" << endl;
			continue;
		}
		if(list[name2order[a]].isman==list[name2order[c]].isman)
		{
			cout << "Whatever" << endl;
			continue;
		}
		deep = 0,deep2=0;
		p = 0, p2 = 0;
		dls(name2order[a]), dls2(name2order[c]);
		bool done = 0;
		for (int k = 0; k < p; k++)
        {
            for (int l = 0; l < p2; l++)
            {
                if (path[k] == path2[l])
                {
                    done = 1;//优化
                    break;
                }
            }
            if (done == 1)//优化
            {
                break;
            }
        }
		if(done==1)
		{
			cout << "No" << endl;
		}
		else
			cout << "Yes" << endl;
	}
}
void dls(int a)
{
	if(a==-1||deep==4)
	{
		return;
	}
	path[p++] = a;
	deep++;
	dls(list[a].orderoffather);
	deep--;
}
void dls2(int a)
{
	if(a==-1||deep2==4)
	{
		return;
	}
	path2[p2++] = a;
	deep2++;
	dls2(list[a].orderoffather);
	deep2--;
}