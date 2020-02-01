//2178 미로탐색
//최단거리를 찾는 문제, 가중치는 거리로 bfs로 풀꺼다.
//16:55-
#include <iostream>
#include <queue>
using namespace std;

queue <pair<int,int>> q;
bool check[102][102] = { false, };
int arr[102][102] = {0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int cnt = 0;
int n, m;

void bfs(int start_x, int start_y) {
	q.push(make_pair(start_x, start_y));
	check[start_x][start_y] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		if (x == n - 1 && y == m - 1) break;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < n && cy >= 0 && cy < m && arr[cx][cy]==1 && check[cx][cy]== false) {
				q.push(make_pair(cx, cy));
				check[cx][cy] = true;
				arr[cx][cy] = arr[x][y] + 1;
			/* 
				int change = arr[x][y] - '0' + 1;
				arr[cx][cy] = change + '0';*/
			}
		}
	}
}

int main() {
	char c;
	cin >> n >> m;
	/*for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}*/
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			arr[i][j] = c - '0';
		}
	}
	bfs(0,0);
	cout << arr[n - 1][m - 1];
	system("pause");
	return 0;
}