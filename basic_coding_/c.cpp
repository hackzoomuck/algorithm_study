//뒤질것같다 하기싫어서
//9:00-9:53다트게임
#include <string>
#include <ctype.h>
#include <math.h>
#include <iostream>
using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int count = 0;
	string string_number;
	int arr[3] = { 0, };
	bool number_end = false;
	for (int i = 0; i < dartResult.size(); i++) {
		while (isdigit(dartResult[i])) {
			string_number.append(1, dartResult[i]);
			number_end = true;
			i++;
		}
		if (number_end) {
			arr[count] = atoi(string_number.c_str());
			string_number.clear();
			number_end = false;
			i--;
		}
		if (dartResult[i] == 'S') {
			if (isdigit(dartResult[i + 1])) count++;
		}
		if (dartResult[i] == 'D') {
			arr[count] = pow(arr[count], 2);
			if (isdigit(dartResult[i + 1])) count++;
		}
		if (dartResult[i] == 'T') {
			arr[count] = pow(arr[count], 3);
			if (isdigit(dartResult[i + 1])) count++;
		}
		if (dartResult[i] == '*') {
			if (count!=0) {
				arr[count - 1] *= 2;
				arr[count] *= 2;
			}
			else {
				arr[count] *= 2;
			}
			count++;
		}
		if (dartResult[i] == '#') {
			arr[count] *= -1;
			count++;
		}
	}
	for (int i = 0; i < 3; i++) {
		answer += arr[i];
	}
	return answer;
}

int main() {
	string input_str;
	cin >> input_str;
	solution(input_str);
	system("pause");
	return 0;
}