/*
7-4 罪犯帮派
Tabu市的警察局决定结束混乱，因此要采取行动根除城市中的几大帮派。
目前的问题是，给出两个罪犯，他们是属于同一帮派么？城市里一共有多少个帮派？
假设在Tabu市现有n名罪犯，编号为1到n，给出m条消息表示属于同一帮派的两个罪犯编号。
请基于这些不完全的信息帮助警方计算出他们想要的信息。
输入格式:
输入第一行为三个正整数，n、m和q。n为罪犯数；m为给出的已知信息数量；q为查询数。
接下来m行，每行2个正整数a和b，表示罪犯a和罪犯b属于同一帮派。接下来q行，每行2个正整数c和d，
即查询罪犯c和d是否属于同一帮派。每行输入的整数以空格间隔，n、m、q均不超过1000。
输出格式:
输出为q+1行，前q行对应于输入的q个查询的结果，如果属于同一帮派，则输出“In the same gang.”，
否则输出“In different gangs.”。最后一行为一个整数，表示帮派数目。
输入样例:
3 2 1
1 2
2 3
1 3
输出样例:
In the same gang.
1
*/
#include <bits/stdc++.h>
using namespace std;
set<int> s[1005];
int v=0,n,m,q;
int main(){
	ios::sync_with_stdio(false);
    cin>>n>>m>>q;
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        if(!s[v].count(a) && !s[v].count(b)){
        	v++;
        	s[v].insert(a);s[v].insert(b); 
        }
        else if(!s[v].count(a)) s[v].insert(a);
        else if(!s[v].count(b)) s[v].insert(b);
    }
    for(int i=0;i<q;i++){
        int c,d;
        cin>>c>>d;
        bool flag=0;
        for(int i=1;i<=v;i++)
            if(s[i].count(c) && s[i].count(d)){
                flag=1;
                break;
            }
        if(flag) cout<<"In the same gang."<<endl;
        else cout<<"In different gangs."<<endl;
    }
    cout<<v<<endl;
    return 0;
}
