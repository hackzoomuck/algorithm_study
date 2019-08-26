//15,28,19
#include <iostream>
using namespace std;

int arr[16][29][20] = { 0, };

int main() {
	int E = 1, S = 1, M = 1;
	int year = 1;
	for (int e = 1; e < 16; e++) {
		for (int s = 1; s < 29; s++) {
			for (int m = 1; m < 20; m++) {
				arr[E][S][M] = year;
				E = (E + 1) % 16;
				S = (S + 1) % 29;
				M = (M + 1) % 20;
				if (E == 0)E++;
				if (S == 0)S++;
				if (M == 0)M++;
				year++;
			}
		}
	}
	int a, b, c;
	cin >> a >> b >> c;
	cout << arr[a][b][c]<<"\n";
	return 0;
}