//i)�ּ� 1���� ������ �ּ� 2���� ����
//sol 2. ���
//��.�Ұ����� ��� ��.������ ã�� ���(������ �ٷ� ���) ��.���� ��� ȣ��
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector <char> v_c;
int input_L, input_C;
char c;
string s="";

bool check(string ck_s) {
	int a = 0, b = 0;//a���� b����
	string tmp_s = "";
	for (int i = 0; i < input_L; i++) {
		if (ck_s[i] == 'a' || ck_s[i] == 'e' || ck_s[i] == 'i' || ck_s[i] == 'o' || ck_s[i] == 'u') {
			b++;
		}
		else {
			a++;
		}
	}
	return a >= 2 && b >= 1;
}

// length:�������ϴ� ��ȣ�� ����, use: ����� �� �ִ� ���ĺ�, password:����� �ִ� ��ȣ, index:���� ������ġ
void go(int len, vector<char> &use, string password, int index) {
	if (password.size() == len) {
		if (check(password))
			cout << password << '\n';
		return;
	}
	if (index >= use.size()) return;

//  error!! ��� ������ ������ ��ó�� ��ȣ�� �ݺ��Ǿ ����
//	go(len, use, password.append(1,use[index]), index + 1);

	go(len, use, password+use[index], index + 1);
	go(len, use, password, index + 1);
}

int main() {
	cin >> input_L >> input_C;
	for (int i = 0; i < input_C; i++) {
		cin >> c;
		v_c.push_back(c);
	}
	sort(v_c.begin(), v_c.end());
	go(input_L, v_c, s, 0);


	system("pause");
	return 0;
}