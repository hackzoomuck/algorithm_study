//�Է�: ���� ���� �׽�Ʈ ���̽��� �̷���� �ִ�.�� �׽�Ʈ ���̽��� �� �ٷ� �̷���� �ִ�.
//    : ù ��° ���� k(6 < k < 13)�̰�, ���� k�� ���� ���� S�� ���ԵǴ� ���̴�.S�� ���Ҵ� ������������ �־�����.
//��ͷ� Ǯ��

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