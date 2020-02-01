//7576 토마토
#include <iostream>
#include <queue>
using namespace std;

queue<pair<int,int>> q;
bool check[1002][1002] = { false, };
bool check_tomato = true;
int arr[1002][1002] = { 0, };
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };
int m, n;
int cnt = 0;

void input() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j));
			}
		}
	}
}

void bfs() {
	if (q.empty()) {
		check_tomato = false;
		return;
	}
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int cx = x + dx[i];
			int cy = y + dy[i];
			if (cx >= 0 && cx < n && cy >= 0 && cy < m && check[cx][cy] == false && arr[cx][cy] == 0) {
				check[cx][cy] = true;
				arr[cx][cy] = arr[x][y] + 1;
				q.push(make_pair(cx, cy));
				if (cnt < arr[cx][cy]) cnt = arr[cx][cy];
			}
		}
	}

}

void tomato_check() {
	check_tomato = true;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) {
				check_tomato = false;
				return;
			}
		}
	}
}


int main() {
	input();
	bfs();
	tomato_check();
	if (check_tomato) {
		if (cnt > 0)
			cout << cnt - 1;
		//error! cnt=0일때에 -1을 출력
		else
			cout << cnt;
	}
	else cout << "-1\n";
	system("pause");
	return 0;
}