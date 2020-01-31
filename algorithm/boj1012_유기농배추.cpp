//dfs로 4방향 탐색할 것, 모든 좌표를 볼 필요없이 주어진 배추의 좌표만 검색
//답이 잘나오는데 무엇이 문제인지 모르겠;;
#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

int arr_baechu[52][52] = { 0, };
int check[52][52] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> q;
int m, n, baechu;

void dfs(int input_x, int input_y) {
	check[input_x][input_y] = 1;
	for (int i = 0; i < 4; i++) {

		int nx = input_x + dx[i];
		int ny = input_y + dy[i];

		if (ny >= 0 && nx >= 0 && ny < n && nx < m) {
			if (arr_baechu[nx][ny] == 1 && !check[nx][ny]) {
				dfs(nx, ny);
			}
		}
	}
}

int main() {
	int testcase;
	cin >> testcase;
	while (testcase--) {
		//memset(check, 0, sizeof(check));
		cin >> m >> n >> baechu;
		
		for (int a = 0; a < m; a++) {
			for (int b = 0; b < n; b++) {
				check[a][b] = 0;
			}
		}
		int bae_x, bae_y;
		for (int i = 0; i < baechu; i++) {
			cin >> bae_x >> bae_y;
			arr_baechu[bae_x][bae_y] = 1;
			q.push(make_pair(bae_x, bae_y));
		}

		int ans = 0;
		while(q.size()) {
			int dfs_x = q.front().first;
			int dfs_y = q.front().second;
			if (!check[dfs_x][dfs_y]) {
				dfs(dfs_x, dfs_y);
				ans++;
			}
			q.pop();
		}
		cout << ans << "\n";
	}
	system("pause");
	return 0;
}

