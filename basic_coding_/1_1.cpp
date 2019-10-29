#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
	string answer = "";
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') continue;
		if (s[i] > 'Z') {//소문자
			if (s[i] + n > 'z') {
				s[i] = (s[i] + n) - 26;
				continue;
			}
			if (s[i] = 'a') {
				s[i] = (s[i] + n) - 25 + 25;
				continue;
			}
			s[i] = (s[i] + n) % ('a' + 25);
			continue;
		}
		//대문자
		if (s[i] + n > 'Z') {
			s[i] = (s[i] + n) - 26;
			continue;
		}
		if (s[i] = 'A') {
			s[i] = (s[i] + n) - 25 + 25;
			continue;
		}
		s[i] = (s[i] + n) % ('A' + 25);

	}
	answer = s;
	cout << answer;
	return answer;
}

int main() {
	string is;
	int in;
	getline(cin,is);
	cin>> in;
	solution(is, in);
	system("pause");
	return 0;
}
