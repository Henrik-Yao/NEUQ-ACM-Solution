#include<iostream>
#include<algorithm>
using namespace std;
struct ss
{
    int a;
    int b;
}p[105];
bool sa(ss s1, ss s2)
{
    return s1.b < s2.b;
}
int main()
{
    int T, n;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> n;
        for(int j = 0; j < n; j ++)
        {
            cin>>p[j].a>>p[j].b;
        }
        sort(p,p+n,sa);
        int j = 0;
        int count = 1;
        for(int k=1;k<n;k++){
            if(p[k].a >= p[j].b){
                j = k;
                count++;
            }
        }
        cout << n-count << endl;
    }
    return 0;
}