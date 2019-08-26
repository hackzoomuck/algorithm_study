//테트로미노
#include <iostream>
#include <algorithm>
using namespace std;
int arr[500][500] = { 0, };
bool visit[500][500] = { 0, };
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };
int x, y, sum = 0;

void test(int _X, int _Y) {

	for (int i = 0; i < 4; i++) {
	
		int test_sum = 0;
		int tx = _X;
		int ty = _Y;
		test_sum += arr[tx][ty];
		visit[tx][ty] = true;

		if ((tx + dx[i] >= x) || (tx + dx[i] < 0) || (ty + dy[i] >= y) || (ty + dy[i] < 0) || (visit[tx + dx[i]][ty + dy[i]] == 1)) {
			continue;
		}
		int _tx = tx + dx[i];
		int _ty = ty + dy[i];
		test_sum += arr[_tx][_ty];
		visit[_tx][_ty] = true;
		
		
		for (int j = 0; j < 4; j++) {
			if ((_tx + dx[j] >= x) || (_tx + dx[j] < 0) || (_ty + dy[j] >= y) || (_ty + dy[j] < 0) || (visit[_tx + dx[j]][_ty + dy[j]] == 1)) {
				continue;
			}
			int __tx = _tx + dx[j];
			int __ty = _ty + dy[j];
			test_sum += arr[__tx][__ty];
			visit[__tx][__ty] = true;

			for (int k = 0; k < 4; k++) {
				if ((__tx + dx[k] >= x) || (__tx + dx[k] < 0) || (__ty + dy[k] >= y) || (__ty + dy[k] < 0) || (visit[__tx + dx[k]][__ty + dy[k]] == 1)) {
					continue;
				}
				int ___tx = __tx + dx[k];
				int ___ty = __ty + dy[k];
				test_sum += arr[___tx][___ty];
				visit[___tx][___ty] = true;
				
				if (sum < test_sum)sum = test_sum;

				test_sum -= arr[___tx][___ty];
				visit[___tx][___ty] = false;
			}
			test_sum -= arr[__tx][__ty];
			visit[__tx][__ty] = false;
		}
		test_sum -= arr[_tx][_ty];
		visit[_tx][_ty] = false;
	}
	visit[_X][_Y] = false;

		int tx1 = _X;
		int ty1 = _Y;
		int test_sum1 = arr[tx1][ty1];
		if ((tx1 - 1 >= 0) && (tx1 + 1 < x) && (ty1 - 1 >= 0) && (ty1 + 1 < y)) {
			int a1 = test_sum1 + arr[tx1 - 1][ty1]+arr[tx1][ty1 - 1]+arr[tx1 + 1][ty1];
			int a2 = test_sum1 + arr[tx1][ty1 - 1] + arr[tx1 + 1][ty1] + arr[tx1][ty1 + 1];
			int a3 = test_sum1 + arr[tx1 - 1][ty1] + arr[tx1][ty1 + 1] + arr[tx1 + 1][ty1];
			int a4 = test_sum1 + arr[tx1 - 1][ty1] + arr[tx1][ty1 - 1] + arr[tx1][ty1 + 1];
			if (sum < a1)sum = a1;
			if (sum < a2)sum = a2;
			if (sum < a3)sum = a3;
			if (sum < a4)sum = a4;
		
		}

}
int main() {
	int z;
	cin >> x >> y;
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			cin >> z;
			arr[i][j] = z;
		}
	}

	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			test(i, j);
		}
	}

	cout << sum;
	return 0;
}

