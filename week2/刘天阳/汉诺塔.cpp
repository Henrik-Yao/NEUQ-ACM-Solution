#include <iostream>
#include <string>

using namespace std;

// n ���Ӹ����� s ��ʼ׮��  e Ŀ��׮��  m �м�׮�� 
void h(int n, string s, string e, string m){
	if (n == 1) cout << s << "->" << e << endl;
	else {
		h(n-1, s, m, e);
		h(1, s, e, m);
		h(n-1, m, e, s);
	}
}

int main (){
	int n;
	string a, b, c;
	
	cin >> n >> a >> b >> c;
	
	h(n, a, c, b);
	
	
	
	return 0;
}
