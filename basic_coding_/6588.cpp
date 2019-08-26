//∞ÒµÂπŸ»Â
#include <iostream>
#include <stdio.h>
using namespace std;
bool arr[1000001] = { 0, };

void aera() {
	arr[1] = 1;
	for (int i = 2; i*i < 1000001; i++) {
		for (int j = i * 2; j <= 1000000; j += i) {
			arr[j] = 1;
		}
	}
}

int main() {
	aera();
	int input;
	scanf("%d", &input);
	while (input) {
		bool check = false;
		if (input % 2 == 0 && input >= 6) {
			for (int i = 3; i * 2 <= input; i += 2) {
				if (arr[i] == 0 && arr[input - i] == 0) {
					printf("%d = %d + %d\n", input, i, input - i);
					check = true;
					break;
				}
			}
		}
		if (check == false) {
			printf("Goldbach's conjecture is wrong.\n");
		}
		scanf("%d", &input);
	}
	return 0;
}