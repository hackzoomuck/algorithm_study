#include <iostream>
#include <vector>
#include <string>
using namespace std;

string arr[102][102];
vector<string> v;

int main() {
	int n;
	int w;
	int pos = 1;
	cin >> n >> w;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	int start = 0;
	int end = n - 1;
	while (start + end == n - 1 && start < end ) {
		for (int j = start; j <= end-1; j++) {
			v.push_back(arr[start][j]);
		}
		for (int i = start; i <= end-1; i++) {
			v.push_back(arr[i][end]);
		}
		for (int j = end; j >= start + 1; j--) {
			v.push_back(arr[end][j]);
		}
		for (int i = end; i >= start + 1; i--) {
			v.push_back(arr[i][start]);
		}
		//È¸Àü
		int mod = v.size();
		int mod_w;
		bool check = true;
		if (w < 0) {
			w = -w;
			check = false;
		}
		mod_w = w % mod;
		if (!check) mod_w = - mod_w;
		int index = (mod - mod_w)%mod;
		//pos
		for (int j = start; j <= end - 1; j++) {
			arr[start][j]=v[index];
			index = (index + 1) % mod;
		}
		for (int i = start; i <= end - 1; i++) {
			arr[i][end]= v[index];
			index = (index + 1) % mod;
		}
		for (int j = end; j >= start + 1; j--) {
			arr[end][j]= v[index];
			index = (index + 1) % mod;
		}
		for (int i = end; i >= start + 1; i--) {
			arr[i][start]= v[index];
			index = (index + 1) % mod;
		}
		start++;
		end--;
		v.clear();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout<< arr[i][j]<<" ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}