//11724 연결요소의 개수
//인접리스트 & dfs
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> v;
bool check[1001] = { 0, };

void dfs(int start) {
	check[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		int x = v[start][i];
		if (!check[x]) {
			check[x] = true;
			dfs(x);
		}
	}
}


int main() {
	int n, m, x, y;
	int cnt = 0;
	cin >> n >> m;
	v.resize(n + 1);
	for (int i = 0; i < m; i++) {
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	for (int k = 1; k <= n; k++) {
		if (!check[k]) { 
			cnt++;
			dfs(k);
		}
	}
	cout << cnt<<"\n";
	return 0;
}