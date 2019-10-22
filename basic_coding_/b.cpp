//일단 [뉴스 클래스터]69.2로 나두고 다른 문제보기
//7:30-7:40 딴짓
//7:40-8:50 비밀지도
//새로운 배움은 string에 append로 한문자 붙이기
//비트위치에 1인지 0인지 알아보기->0인지 아닌지로 판단
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	
	for (int i = 0; i < n; i++)
	{
		int cal = arr1[i] | arr2[i];
		string tmp;
		for (int j = n-1; j >= 0; j--) {
			if ((cal & (1 << j))) {
				tmp.append("#");
			}
			else {
				tmp.append(" ");
			}
		}
		answer.push_back(tmp);
	}
	
	
	return answer;
}

int main() {
	int input_n, a;
	vector<int> i1;
	vector<int> i2;
	cin >> input_n;
	for (int i = 0; i < input_n; i++) {
		cin >> a;
		i1.push_back(a);
	}
	for (int i = 0; i < input_n; i++) {
		cin >> a;
		i2.push_back(a);
	}
	solution(input_n, i1, i2);
	system("pause");
	return 0;
}