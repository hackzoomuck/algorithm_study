#include <iostream>
using namespace std;

int arr[101][101] = { 0, };
int visit[101][101] = { 0, };
int height = 0, section_max = 0, n;
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void dfs(int x, int y) {
	visit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && nx < n && ny >= 0 && ny < n) {
			if (!visit[nx][ny]) dfs(nx, ny);
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (height <= arr[i][j])height = arr[i][j];
		}
	}

	for (int h = 1; h <= height; h++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h >= arr[i][j]) visit[i][j] = 1;
				else visit[i][j] = 0;
			}
		}

		int sec = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visit[i][j]) {
					dfs(i, j);
					sec++;
				}
			}
		}
		if (sec >= section_max)section_max = sec;
	}
	//모두 같은 높이의 지대일때 0이 출력됨.
	if (!section_max) section_max = 1;
	cout << section_max << "\n";
	system("pause");
	return 0;
}