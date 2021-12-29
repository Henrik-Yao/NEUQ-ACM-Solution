#include<bits/stdc++.h>
using namespace std;

#define lowbit(x) (x & (-x))
typedef long long ll;
const int MAXN = 500010;
const ll inf = 0x3f3f3f3f3f3f3f3f;

void in(){}
template<typename T, typename ...otr_T>
void in(T &t, otr_T & ...otr)
{
    cin >> t;
    in(otr...);
}

map< string, pair<int, string> > f;

bool Check(string s1, string s2)
{
    int fa = 1;
	for(string sa=s1;!sa.empty();sa=f[sa].second,fa++)
	{
		int fb = 1;
		for(string sb=s2;!sb.empty();sb=f[sb].second,fb++)
		{
			if(fa>=5&&fb>=5)return 1;
			if(sa==sb&&(fa<5||fb<5))
			{
				return 0;
			}
		} 
	}
	return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n; in(n);
    for(int i = 1; i <= n; ++i)
    {
        string a, b;
        in(a, b);
        if(b[b.size() - 1] == 'f') f[a] = make_pair(2, "");
        else if(b[b.size() - 1] == 'm') f[a] = make_pair(1, "");
        else if(b[b.size() - 1] == 'n') f[a] = make_pair(1, b.substr(0, b.size() - 4));
        else if(b[b.size() - 1] == 'r') f[a] = make_pair(2, b.substr(0, b.size() - 7));
    }
    int m; in(m);
    while(m--)
    {
        string a, b, c, d;
        in(a, b, c, d);
        if(f.find(a) == f.end() || f.find(c) == f.end()) {cout << "NA\n"; continue;}
        else if(f[a].first == f[c].first) {cout << "Whatever\n"; continue;}
        else if(Check(a, c)) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}
