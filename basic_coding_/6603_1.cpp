#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arr[13] = { 0, };

int main() {
	int number;
	int input;
	vector<int> v;
	cin >> number;
	while (number) {
		for (int i = 0; i < number; i++) {
			cin >> input;
			arr[i] = input;
			if (i > 5) {
				v.push_back(0);
				continue;
			}
			v.push_back(1);
		}
		
		do {
			for (int j = 0; j < v.size(); j++) {
				if (v[j] == 1) {
					cout << arr[j] << " ";
				}
			}
			cout << "\n";
		} while (prev_permutation(v.begin(), v.end()));
		cout << "\n";
		v.clear();
		cin >> number;
	}

	system("pause");
	return 0;
}