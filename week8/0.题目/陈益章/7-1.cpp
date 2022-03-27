#include<iostream>
#include<algorithm>
using namespace std;
struct ss{
    int a;
    int b;
}p[107];
bool ssa(ss ss1, ss ss2){
    return ss1.b < ss2.b;
}
int main()
{
    int T, n;
    cin >> T;
    for(int w = 0; w < T; w ++){
        cin >> n;
        for(int j = 0; j < n; j ++){
            cin >> p[j].a >> p[j].b;
        }
        sort(p,p+n,ssa);
        int j = 0;
        int sum = 1;
        for(int i = 1; i < n; i ++){
            if(p[i].a >= p[j].b){
                j = i;
                sum ++;
            }
        }
        cout << n-sum << endl;
    }
}

