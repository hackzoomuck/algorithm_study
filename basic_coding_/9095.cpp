//1,2,3더하기-n중for문
#include <iostream>
using namespace std;


int main() {

	int n, nu;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nu;
		int ans = 0;
		for (int a1 = 1; a1 <= 3; a1++) {
			if (a1 == nu) ans += 1;
			for (int a2 = 1; a2 <= 3; a2++) {
				if (a1 + a2 == nu) ans += 1;
				for (int a3 = 1; a3 <= 3; a3++) {
					if (a1 + a2 + a3 == nu) ans += 1;
					for (int a4 = 1; a4 <= 3; a4++) {
						if (a1 + a2 + a3 + a4 == nu) ans += 1;
						for (int a5 = 1; a5 <= 3; a5++) {
							if (a1 + a2 + a3 + a4 + a5 == nu)ans++;
							for (int a6 = 1; a6 <= 3; a6++) {
								if (a1 + a2 + a3 + a4 + a5 + a6 == nu)ans++;
								for (int a7 = 1; a7 <= 3; a7++) {
									if (a1 + a2 + a3 + a4 + a5 + a6 + a7 == nu)ans++;
									for (int a8 = 1; a8 <= 3; a8++) {
										if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 == nu)ans++;
										for (int a9 = 1; a9 <= 3; a9++) {
											if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 == nu)ans++;
											for (int a0 = 1; a0 <= 3; a0++) {
												if (a1 + a2 + a3 + a4 + a5 + a6 + a7 + a8 + a9 + a0 == nu)ans++;
											}
										}
									}
								}

							}
						}
					}
				}
			}
		}
		cout << ans << "\n";
	}

	return 0;
}