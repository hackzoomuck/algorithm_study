#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	int testcase;
	cin >> testcase;
	vector<string> v;
	v.resize(testcase);
	for (int i = 0; i < testcase; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < testcase; i++) {
		for (int j = 0; j < v[i].size()-1; j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				if (v[i][j] == v[i][k]) {
					v[i].erase(j, 1);
					v[i].erase(k-1, 1);
					j--;
					break;
				}
			}
			if (!v[i].size()) break;
		}
		cout << "#" << i+1 << " " << v[i].size() << "\n";
	}
	system("pause");
	return 0;
}