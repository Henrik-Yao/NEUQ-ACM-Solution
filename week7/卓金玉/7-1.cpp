#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    map<string, string> dic;
    int N, M;
    cin >> N >> M;
    string keystring, valuestring, quesstring, tempstring;
    for (int i = 0; i < N; ++i)
    {
        cin >> keystring >> valuestring;
        dic[valuestring] = keystring;
    }
    for (int i = 0; i < M; ++i)
    {
        cin >> quesstring;
        //    tempstring = dic[quesstring];
        if (dic[quesstring] != "")
        {
            cout << dic[quesstring] << endl;
        }
        else
        {
            cout << "eh" << endl;
        }
    }
    return 0;
}