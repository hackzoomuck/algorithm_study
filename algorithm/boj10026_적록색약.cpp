//dfs 좌표 하나씩 체크
//1.그냥 색약과 아닌 것 따로 각각 구한다.
//rgb입력된 배열과 같은 크기의 check배열로 방문 여부 

#include <iostream>
using namespace std;

char arr_rgb[101][101];
bool check[101][101] = { false, };
bool check1[101][101] = { false, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int ans = 0, ans1 = 0;

void input_rgb(int input_n) {
	for (int i = 0; i < input_n; i++) {
		for (int j = 0; j < input_n; j++) {
			cin >> arr_rgb[i][j];
		}
	}
}

void dfs(int input_x, int input_y, int input_n) {
	char color = arr_rgb[input_x][input_y];
	check[input_x][input_y] = true;
	for (int d = 0; d < 4; d++) {
		int nx = input_x + dx[d];
		int ny = input_y + dy[d];
		if (nx >= 0 && ny >= 0 && nx < input_n && ny < input_n) {
			if (!check[nx][ny] && color == arr_rgb[nx][ny]) {
				dfs(nx, ny, input_n);
			}
		}
	}
}
void dfs1(int input_x, int input_y, int input_n) {
	char color = arr_rgb[input_x][input_y];
	check1[input_x][input_y] = true;
	for (int d = 0; d < 4; d++) {
		int nx = input_x + dx[d];
		int ny = input_y + dy[d];
		if (nx >= 0 && ny >= 0 && nx < input_n && ny < input_n) {
			if (!check1[nx][ny]) {
				if (color=='G' && arr_rgb[nx][ny] == 'R') {
					dfs1(nx, ny, input_n);
				}
				else if (color == 'R' && arr_rgb[nx][ny] == 'G') {
					dfs1(nx, ny, input_n);
				}
				else if (color == arr_rgb[nx][ny]) {
					dfs1(nx, ny, input_n);
				}
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	input_rgb(n);
	for (int x = 0; x < n; x++) {
		for (int y = 0; y < n; y++) {
			if (!check[x][y]) {
				dfs(x, y, n);
				ans++;
			}
			if (!check1[x][y]) {
				dfs1(x, y, n);
				ans1++;
			}
		}
	}
	cout << ans<<" "<<ans1;
	system("pause");
	return 0;
}