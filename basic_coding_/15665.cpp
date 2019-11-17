#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> v_count;
int arr[10];

void go(int index, int n, int m) {
	if (index == m) {
		
			for (int l = 0; l < m; l++) {
				cout << arr[l] << " ";
			}
			cout << "\n";
	
		return;
	}
	for (int j = 0; j < v.size(); j++) {
		arr[index] = v[j];
		go(index + 1, n, m);
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
	v.erase(unique(v.begin(), v.end()), v.end());
	go(0, input_n, input_m);
	system("pause");
	return 0;
}