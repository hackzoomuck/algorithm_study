//1260 bfs dfs 인접리스트
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string.h>
using namespace std;

//error size
int check[1001] = { 0, };
vector<vector<int>> adjcent_list;

void dfs(int d_v) {
	check[d_v] = true;
	cout << d_v<<" ";
	for (int i = 0; i < adjcent_list[d_v].size(); i++) {
		int y = adjcent_list[d_v][i];
		if (!check[y]) {
			 dfs(y);
		}
	}
	return;
}
void bfs(int b_v) {
	memset(check, 0, sizeof(check));
	cout << "\n";
	queue<int> q;
	q.push(b_v);
	check[b_v] = true;
	while (!q.empty()) {
		int next = q.front();
		cout << next<<" ";
		q.pop();
		for (int i = 0; i < adjcent_list[next].size(); i++) {
			int x = adjcent_list[next][i];
			if (!check[x]) {
				check[x] = true;
				q.push(x);
			}
		}
	}
	cout << "\n";
}
void input(int i_n, int i_m) {
	int x, y;
	for (int i = 0; i < i_m; i++) {
		cin >> x >> y;
		adjcent_list[x].push_back(y);
		adjcent_list[y].push_back(x);
	}
	//error! 1부터 n까지
	for (int j = 1; j <= i_n; j++) {
		sort(adjcent_list[j].begin(), adjcent_list[j].end());
	}

}
int main() {
	int n, m, v;
	cin >> n >> m >> v;
	adjcent_list.resize(n+1);
	input(n, m);
	dfs(v);
	bfs(v);
	system("pause");
	return 0;
}