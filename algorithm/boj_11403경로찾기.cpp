#include <iostream>
#include <cstring>
using namespace std;
int arr[101][101] = { 0, };
int visit[101] = { 0, };
int n;

//���������� ���� dfs�� �������� �� ����
void dfs(int now) {
	for (int next = 0; next < n; next++) {
		if (arr[now][next] && !visit[next]) {
			visit[next] = 1;
			dfs(next);
		}
	}
}
int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit));
		dfs(i);
		//�湮�ϸ� visit[j]=1�̹Ƿ� i�� j�� ���� ��.
		for (int j = 0; j < n; j++) {
			if (visit[j])
				arr[i][j] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	system("pause");
	return 0;
}