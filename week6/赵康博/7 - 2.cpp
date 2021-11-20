#include <bits/stdc++.h>
using namespace std;
#define N (int)1e5
map <string,string> node;
int Su(string t){
    int t1 = t.size();
    int t2 = -1;
    int a = t1/4;
    int b = t1%4;
    t1 = 0;
    int xun[4];
    int sum = 0;
    int xum = 0;
    for(int i = 0; i < 4 ;i++)
    {
        if(b!=0){
            xun[i] = a + 1;
            b--;
        }
        else xun[i] = a;
    }
    for(int i = 0; i < 4 ;i++)
    {   xum = 0;
        t2 += xun[i];
        int x;
        for(int j = t1; j <= t2 ;j++)
        {
            char x1 = t[j];
            if(x1>='0'&&x1<='9')
            {
             x = (int)(x1 - '0');
            }
            else if(x1>='a'&&x1<='z')x = (int)(x1 - 'a') + 10;
            else x = (int )(x1 - 'A') + 10;
            xum = xum + x;
        }
        t1 = t2 + 1;
        x = xum%36;
        sum = (sum*36 + x)%2333;
    }
    return sum;
}
void sign(){
    char t[N];
    cin>>t;
    char m[N];
    cin>>m;
    int z = Su(t);
    if(node[t]==""){
        cout<<"Signed!";
        node[t] = m;
    }
    else cout<<"Repeated!";
}
void act(){
    char t[N];
    char m[N];
    cin>>t>>m;
    if(node[t]==m)cout<<"Success!";
    else if(Su(node[t])==Su(m))cout<<"Attention!";
    else cout<<"Failed!";
}
int main()
{
        int n;
        cin>>n;
        for(int i = 0; i < n; i++)
        {
            char t1;
            cin>>t1;
            if(t1 == 'R')sign();
            else act();
            if(i!=n-1)cout<<endl;
        }
    //cout<<Su("1234qwerasdf")<<" "<<Su("0km6trlhdcwc");
    system("pause");
    return 0;
}