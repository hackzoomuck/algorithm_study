//i)최소 1개의 모음과 최소 2개의 자음
//sol 2. 재귀
//ㄱ.불가능한 경우 ㄴ.정답을 찾은 경우(맞으면 바로 출력) ㄷ.다음 경우 호출
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
	int a = 0, b = 0;//a자음 b모음
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

// length:만들어야하는 암호의 길이, use: 사용할 수 있는 알파벳, password:만들고 있는 암호, index:현재 결정위치
void go(int len, vector<char> &use, string password, int index) {
	if (password.size() == len) {
		if (check(password))
			cout << password << '\n';
		return;
	}
	if (index >= use.size()) return;

//  error!! 답과 동일한 갯수의 맨처음 암호만 반복되어서 나옴
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