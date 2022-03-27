#include <bits/stdc++.h>
using namespace std;

multiset<int>s;
vector<int>ans;
int n,m;
int main(){
    while(scanf("%d",&n) != EOF){
        s.clear();ans.clear();
        for(int i = 0;i < n;i++){
            int data;
            scanf("%d",&data);
            s.insert(data);
        }
        scanf("%d",&m);
        for(int i = 0;i < m;i++){
            int num;
            scanf("%d",&num);
        int _time = s.count(num);
        if(!_time){
            ans.push_back(0);
        }
        else {
            int cnt = 0;
            auto it = s.lower_bound(num);
            for(auto i = s.begin();i != s.end();i++,cnt++)
                if(i == it)break;
            ans.push_back(cnt + 1);
        }
        }
        vector<int>res(s.begin(),s.end());
        for(int i = 0,sz = res.size();i < sz - 1;i++){
            printf("%d ",res[i]);
        }    
        printf("%d\n",res[res.size() - 1]);
        for(int i = 0,sz = ans.size();i < sz - 1;i++){
            printf("%d ",ans[i]);
        }    
        printf("%d\n",ans[ans.size() - 1]);
        res.clear();    
    }
    return 0;
}