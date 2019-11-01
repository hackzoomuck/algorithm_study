//i)최소 1개의 모음과 최소 2개의 자음
//vector<char>입력하고 sort하고 
//sol 1. 그냥 순열(next_permutation)로 해서 i)조건 이면 출력 아니면 다음껄로? 
//=>그냥 순열 돌리고 L 앞부분만 짤라서 보여줬는데 그러면 안됨.
//=>순열이 아닌 조합이기에 틀림

//=>조합(0과 1)로 선택과 선택안함을 갈라서 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<char> v;
vector<int> choice;

int main() {
	int L, C;
	char c;
	cin >> L >> C;
	for (int i = 0; i < C; i++) {
		cin >> c;
		v.push_back(c);
	}
	for (int j = 0; j < L; j++) {
		choice.push_back(0);
	}
	for (int j = 0; j < C - L; j++) {
		choice.push_back(1);
	}
	//a,e,i,u,o
	sort(v.begin(), v.end());
	sort(choice.begin(), choice.end());

	do {
		int mo = 0; int za = 0;
		vector<char> tmp;
		for (int k = 0; k < choice.size(); k++) {
			if (choice[k] == 0) {
				if (v[k] == 'a' || v[k] == 'e' || v[k] == 'i' || v[k] == 'u' || v[k] == 'o') {
					mo++;
				}
				else za++;
				tmp.push_back(v[k]);
			}
		}
		if (mo > 0 && za > 1) {
			for (int l = 0; l < tmp.size(); l++) {
				cout << tmp[l];
			}
			cout << "\n";
		}

	} while (next_permutation(choice.begin(), choice.end()));


	return 0;
}