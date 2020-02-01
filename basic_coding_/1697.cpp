//1697 ���ٲ���
//�����̴� ���� �� N(0 �� N �� 100, 000)�� �ְ�, ������ �� K(0 �� K �� 100, 000)�� �ִ�.
//�����̴� �Ȱų� �����̵��� �� �� �ִ�.����, �������� ��ġ�� X�� �� �ȴ´ٸ� 1�� �Ŀ� X - 1 �Ǵ� X + 1�� �̵��ϰ� �ȴ�.
//�����̵��� �ϴ� ��쿡�� 1�� �Ŀ� 2 * X�� ��ġ�� �̵��ϰ� �ȴ�.
// BFS�� Ǯ���̴�. ���� ���� �ð�
#include <iostream>
#include <queue>
using namespace std;

bool check[100002] = { 0, };
queue <int> q;
	
void bfs(int input_n, int input_k) {
	q.push(input_n);
	check[input_n] = true;
	int cnt = 0;
	while (!q.empty()) {
		int size = q.size();
		for (int i = 0; i < size; i++) {
			int front = q.front();
			q.pop();
			if (front == input_k) {
				cout << cnt;
				return;
			}
			if (front - 1 >= 0 && !check[front - 1]) {
				q.push(front - 1);
				check[front - 1] = true;
			}
			if (front + 1 < 100001 && !check[front + 1]) {
				q.push(front + 1);
				check[front + 1] = true;
			}
			if (front * 2 < 100001 && !check[front * 2]) {
				q.push(front * 2);
				check[front * 2] = true;
			}
		}
		cnt++;
	}

}

int main() {
	int n, k;
	cin >> n >> k;
	bfs(n, k);
	system("pause");
	return 0;
}