#include <iostream>
using namespace std;
int main() {
    int left = 0;
	int right = 0;
	string str;
	while(cin >> str){
	int len = str.size();
	for (int i = 0; i < len; i++) {
		if (str[i] == '(') {
			left++;
		}
		else
		{
			if (left == 0) {
				right++;
			}
			else {
				left--;
			}
		}
	}
	if (left == 0 && right == 0) {
		cout << "Match";
	}
	else {
		cout << left + right << endl;
		for(int i = 0; i < right; i++)
            cout << '(';
		cout << str;
        for(int i = 0; i < left; i++)
            cout << ')';
	}
	left=0;right=0;
	cout<<endl;
}
}

