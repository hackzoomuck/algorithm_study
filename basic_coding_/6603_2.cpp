//입력: 여러 개의 테스트 케이스로 이루어져 있다.각 테스트 케이스는 한 줄로 이루어져 있다.
//    : 첫 번째 수는 k(6 < k < 13)이고, 다음 k개 수는 집합 S에 포함되는 수이다.S의 원소는 오름차순으로 주어진다.
//재귀로 풀자

#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector <int> v;
void go(vector<int> &lotto, int choose , int index) {

	if (choose == 6) {
		for (int g = 0; g < v.size(); g++) {
			cout << v[g] << " ";
		}
		cout << "\n";
		return;
	}	
	if (index >= lotto.size())
		return;
	v.push_back(lotto[index]);
	go(lotto, choose + 1, index + 1);
	v.pop_back();
	go(lotto, choose, index + 1);
}

int main() {
	int input_k, input_s;
	cin >> input_k;
	while (input_k) {
		vector <int> v_i;
		for (int i = 0; i < input_k; i++) {
			cin >> input_s;
			v_i.push_back(input_s);
		}
		go(v_i,0,0);
		cin >> input_k;
		cout << "\n";
	}

	return 0;
}