//s:화면의 이모티콘, c:클립보드의 이모티콘 
//s,c에 따라 시간이 달라짐.
//모든 연산은 1초, 최소 시간을 구함.
#include <iostream>
#include <tuple>
#include <queue>
#include <cstring>
using namespace std;

int d[1001][1001];
int main() {
	int n;
	cin >> n;
	memset(d, -1, sizeof(d));
	/*for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) {
			d[i][j] = -1;
		}
	}
	*/
	queue<pair<int, int>> q;
	q.push(make_pair(1, 0));
	d[1][0] = 0;
	while (!q.empty()) {
		int s, c;
		tie(s, c) = q.front();
		q.pop();
		if (d[s][s] == -1) {
			d[s][s] = d[s][c] + 1;
			q.push(make_pair(s, s));
		}
		if (s + c <= n && d[s + c][c] == -1) {
			d[s + c][c] = d[s][c] + 1;
			q.push(make_pair(s + c, c));
		}
		if (s - 1 >= 0 && d[s - 1][c] == -1) {
			d[s - 1][c] = d[s][c] + 1;
			q.push(make_pair(s - 1, c));
		}
	}
	int ans = -1;
	for (int k = 0; k <= n; k++) {
		if (d[n][k] != -1) {
			if (ans == -1 || ans > d[n][k]) {
				ans = d[n][k];
			}
		}
	}
	cout << ans << '\n';
	system("pause");
	return 0;
}