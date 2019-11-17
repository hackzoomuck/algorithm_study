//(������ ����->�迭�� �Ҵ�� ũ�⸦ �Ѿ �������� ��)
//vector���� ���� index�� ���� index ���� �� ��������.
//�ߺ��κп� �־
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arr[10];
vector<int> input_arr_vector;
vector<int> same_count_vector;

void go(int index, int n, int m) {
	if (index == m) {
		for (int j = 0; j < m; j++) {
			cout << arr[j] << " ";
		}
		cout << "\n";
		return;
	}
	for (int k = 0; k < input_arr_vector.size(); k++) {
		if (same_count_vector[k]==0) continue;
		arr[index] = input_arr_vector[k];
		same_count_vector[k]--;
		//arr[index] = input_arr[k];
		go(index + 1, n, m);
		same_count_vector[k]++;
	}
	return;
}

int main() {
	int input_n, input_m;
	int number;
	cin >> input_n >> input_m;
	for (int i = 0; i < input_n; i++) {
		cin >> number;
		input_arr_vector.push_back(number);
	}
	sort(input_arr_vector.begin(), input_arr_vector.end());
	int same_count = 0;
	for (int j = 0; j < input_n; j++) {
		same_count++;
		if (j == input_n - 1) {
			same_count_vector.push_back(same_count);
			break;
		}
		if (input_arr_vector[j] != input_arr_vector[j + 1]) {
			same_count_vector.push_back(same_count);
			same_count = 0;
		}
	}
	input_arr_vector.erase(unique(input_arr_vector.begin(), input_arr_vector.end()), input_arr_vector.end());
	go(0, input_n, input_m);
	system("pause");
	return 0;
}
