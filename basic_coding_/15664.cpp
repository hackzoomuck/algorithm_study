//16:07-
//15664 N�� M(10)
//N���� �ڿ��� �߿��� M���� �� ����
//�� ������ �񳻸������̾�� �Ѵ�.
//���̰� K�� ���� A�� A1 �� A2 �� ... �� AK - 1 �� AK�� �����ϸ�, �񳻸������̶�� �Ѵ�.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> v_count;
int arr[10];

void go(int index, int n, int m) {
	if (index == m) {
		bool check = true;
		for (int k = 0; k < m-1; k++) {
			if (arr[k] > arr[k + 1]) {
				check = false;
				break;
			}
		}
		if (check) {
			for (int l = 0; l < m; l++) {
				cout << arr[l]<<" ";
			}
			cout << "\n";
		}
		return;
	}
	for (int j = 0; j < v.size(); j++) {
		if (v_count[j] == 0) continue;
			arr[index] = v[j];
			//�̺κ����� ��Ÿ�ӿ�����....index�� �ƴ϶� j���ݾ�.
			//v_count[index]--;
			go(index + 1, n, m);
			//v_count[index]++;
	}
	return;
}

int main() {
	int input_n, input_m;
	int num;
	cin >> input_n >> input_m;
	for (int i = 0; i < input_n; i++) {
		cin >> num;
		v.push_back(num);
	}
	sort(v.begin(), v.end());
	int count = 0;
	for (int j = 0; j < input_n; j++) {
		count++;
		if (j == input_n - 1) {
			v_count.push_back(count);
			break;
		}
		if (v[j] != v[j + 1]) {
			v_count.push_back(count);
			count = 0;
		}
	}
	v.erase(unique(v.begin(), v.end()), v.end());
	go(0, input_n, input_m);
	system("pause");
	return 0;
}