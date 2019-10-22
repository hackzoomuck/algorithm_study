#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m;
char arr[51][51] = { 0, };
int check[51][51] = { 0, };
vector<int> v;
queue<pair<int,int>> q;
queue<int>q_c;
int dx[4] = { -1,0,1,0 };
int dy[4] = {  0,-1,0,1};
int c = 0;

void bfs(int x, int y) {
	int nx;
	int ny;
	int _x;
	int _y;
	q.push(make_pair(x,y));
	q_c.push(0);
	while (!q.empty()) {
		_x = q.front().first;
		_y = q.front().second;
		q.pop();
		int qc = q_c.front()+1;
		q_c.pop();
		for (int i = 0; i < 4; i++) {
			nx = _x + dx[i];
			ny = _y + dy[i];
			if (0 <= nx && nx < n && 0 <= ny && ny < m && arr[nx][ny] == 'L' && check[nx][ny] == 0) {
				check[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				q_c.push(qc);
			}
		}
		c = qc-1;
	}
	v.push_back(c);
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L' && check[i][j]==0) {
				check[i][j] = 1;
				bfs(i, j);

				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						check[i][j] = 0;
					}
				}
			}
		}
	}
	sort(v.rbegin(), v.rend());
	if (v.size() == 0) {
		cout << "0\n";
		return 0;
	}
	cout << v[0] << "\n";
	system("pause");
	return 0;
}