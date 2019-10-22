//5:50-6:00 추석 트래픽 넘김
//뉴스 클러스터링
//a,b집합 각각 모두 공집합 일 경우에는 J(A,B)=1
//6:00-7:30
//다른 날 6:15-8:11
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

int solution(string str1, string str2) {
	int answer = 0;
	map<string, int> m1;
	map<string, int> m2;
	for (int i = 0; i < str1.size(); i++) {
		if (!isalpha(str1[i])) continue;
		str1[i] = toupper(str1[i]);
	}
	for (int i = 0; i < str2.size(); i++) {
		if (!isalpha(str2[i])) continue;
		str2[i] = toupper(str2[i]);
	}
	double str1_size = 0;
	double str2_size = 0;
	for (int i = 0; i < str1.size()-1; i++) {
		if (!isalpha(str1[i])) continue;
		if (isalpha(str1[i + 1])) {
			string tmp;
			tmp.append(1,str1[i]);
			tmp.append(1,str1[i + 1]);
			if (m1.find(tmp) == m1.end()) {
				m1.insert(make_pair(tmp, 1));
			}
			else {
				int tmp_count = m1.find(tmp)->second;
				m1.find(tmp)->second = tmp_count+1;
				cout << m1.find(tmp)->second << "\n";
			}
			str1_size++;
		}
	}
	for (int i = 0; i < str2.size() - 1; i++) {
		if (!isalpha(str2[i])) continue;
		if (isalpha(str2[i + 1])) {
			string tmp;
			tmp.append(1, str2[i]);
			tmp.append(1, str2[i + 1]);
			if (m2.find(tmp) == m2.end()) {
				m2.insert(make_pair(tmp, 1));
			}
			else {
				int tmp_count = m2.find(tmp)->second;
				m2.find(tmp)->second = tmp_count + 1;
				cout << m2.find(tmp)->second << "\n";
			}
			str2_size++;
		}
	}	
	cout << "str1:" << str1_size << " st2:" << str2_size << "\n";
	double common_count = 0;
	for (auto it1 = m1.begin();it1!=m1.end();it1++) {
		if (m2.find(it1->first) != m2.end()) {
			int cmp = m2.find(it1->first)->second;
			cout << "cmp" << cmp << "\n";
			if ((it1->second) >= cmp) common_count += cmp;
			else common_count += it1->second;
			cout << "common_count:" << common_count << "\n";
		}
	}


	double double_answer = 0;
	bool check = true;
	if (str1_size == 0 && str2_size == 0) { answer = 65536; return answer; }
	if (common_count == 0) double_answer = 0;
	else {
		double_answer = common_count / (str1_size + str2_size- common_count);
	}
	double_answer *= 65536;
	answer = double_answer;
	cout << answer;
	return answer;
}


int main() {
	string input_str1;
	string input_str2;
	getline(cin,input_str1);
	getline(cin,input_str2);
	solution(input_str1, input_str2);

	system("pause");
	return 0;
}