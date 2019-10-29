#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

int solution(int n)
{
	int answer = 0;
	string s = to_string(n);
	for (int i = 0; i<s.size(); i++) {
		answer += s[i] - 48;	
	}
	cout << answer;
	return answer;
}
int main() {
	int in;
	cin >> in;
	solution(in);
	system("pause");
	return 0;
}
