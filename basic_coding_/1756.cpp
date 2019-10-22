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
		choice.push_back(0);
	}
	for (int j = 0; j < C-L; j++) {
		choice.pop_back();
	}
	for (int j = 0; j < C-L; j++) {
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

	} while (next_permutation(choice.begin(),choice.end()));


	system("pause");
	return 0;
}