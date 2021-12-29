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

int cmp(pair<ll, string> a, pair<ll, string> b)
{
    if(a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

struct Trie
{
    int ch[MAXN][36], tot;
    int End[MAXN];
    pair<ll, string> sum[MAXN];
    vector< pair<ll, string> > ans;
    
    void Insert(string s, ll w, string ss)
    {
        int u = 0, c;
        for(int i = 0; i < s.size(); ++i)
        {
            c = s[i];
            if(!ch[u][c]) ch[u][c] = ++tot;
            u = ch[u][c];
        }
        if(End[u])
        {
            sum[u] = make_pair(max(w, sum[u].first), ss);
        }
        else
        {
            End[u] = 1;
            sum[u] = make_pair(w, ss);
        }
    }
    
    void dfs(int u)
    {
        if(!u) return;
        if(End[u]) ans.push_back(sum[u]);
        for(int i = 0; i < 36; ++i) dfs(ch[u][i]);
    }
    
    void query(string s)
    {
        int u = 0, c;
        ans.clear();
        for(int i = 0; i < s.size(); ++i)
        {
            c = s[i];
            if(!ch[u][c]) return;
            u = ch[u][c];
        }
        for(int i = 0; i < 36; ++i) dfs(ch[u][i]);
        sort(ans.begin(), ans.end(), cmp);
    }
}T;

void get(string &s)
{
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] >= 'a' && s[i] <= 'z') s[i] -= 'a';
        else s[i] = s[i] - '0' + 26;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n, m, k;
    in(n, m, k);
    for(int i = 1; i <= n; ++i)
    {
        ll w; string s, ss;
        in(w, s); ss = s;
        get(s);
        T.Insert(s, w, ss);
    }
    while(m--)
    {
        string s;
        in(s); get(s);
        T.query(s);
        for(int i = 0; i < T.ans.size() && i < k; ++i)
            cout << T.ans[i].second << "\n";
        if(T.ans.size() == 0) cout << "no suggestion\n";
        if(m) cout << "\n";
    }
    return 0;
}
