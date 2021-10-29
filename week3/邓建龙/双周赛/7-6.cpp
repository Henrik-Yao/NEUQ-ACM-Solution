#include <iostream>
#include <cstring>

using namespace std;

char str[8];
char res[8];
int len = 0;
int height = 0;
int blank[8];

void func(int depth)
{
    if (depth == len) {
        for (int i = 0; i < len; i++) i != len - 1 ? cout << res[i] : cout << res[i] << endl;
        return;
    } else {
        for (int i = 0; i < len; i++) {
            if (blank[i] == 1) { blank[i] = 0,res[height++] = str[i],func(depth + 1),height--,blank[i] = 1;
            }
        }
    }
}

int main()
{
    cin >> str;
    len = (int) strlen(str);
    for (int i = 0; i < len; i++)
        for (int j = i + 1; j < len; j++) if (str[i] >= str[j]) swap(str[i], str[j]);
    for (int & i : blank) i = 1;
    func(0);
    return 0;
}