#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int dx[8] = {0, 0,1,-1,1,-1,1,-1};
int dy[8] = {1,-1,0,0,-1,-1,1,1};
int arr_map[51][51] = { 0, };
bool check[51][51] = { 0, };
int w, h;

void dfs(int x, int y) {
	check[x][y] = true;
	for (int d = 0; d < 8; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx>=0 && nx<h && ny>=0 && ny<w && check[nx][ny]==false && arr_map[nx][ny]==1) {
			dfs(nx, ny);
		}
	}
	return;
}

void input(int input_w, int input_h) {
	for (int i = 0; i < input_h; i++) {
		for (int j = 0; j < input_w; j++) {
			cin >> arr_map[i][j];
		}
	}
}

int main() {

	cin >> w >> h;
	while (w || h) {
		int cnt = 0;
		input(w, h);
		//memset으로 초기화하는거 오류임.
		/*for (int k = 0; k < h; k++) {
			memset(check, 0, sizeof(int)*w);
		}*/
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				check[i][j] = false;
			}
		}
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (arr_map[i][j] == 1 && check[i][j] == false) {
					cnt++;
					dfs(i, j);
				}
			}
		}
		cout << cnt << "\n";
		cin >> w >> h;
	}

	return 0;
}