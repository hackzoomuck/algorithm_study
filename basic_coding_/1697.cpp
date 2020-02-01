//1697 숨바꼭질
//수빈이는 현재 점 N(0 ≤ N ≤ 100, 000)에 있고, 동생은 점 K(0 ≤ K ≤ 100, 000)에 있다.
//수빈이는 걷거나 순간이동을 할 수 있다.만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X - 1 또는 X + 1로 이동하게 된다.
//순간이동을 하는 경우에는 1초 후에 2 * X의 위치로 이동하게 된다.
// BFS로 풀것이다. 가장 빠른 시간
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