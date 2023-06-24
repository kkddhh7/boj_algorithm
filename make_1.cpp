#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int num;
	cin >> num;

	vector<int> dp(num + 1);
	dp[num] = 1;
	for (int i = num; i > 0; i--) {
		if (dp[i] != 0) {
			if (i % 3 == 0) {
				if (dp[i / 3] == 0) {
					dp[i / 3] = dp[i] + 1;
				}
				else {
					dp[i / 3] = min(dp[i] + 1, dp[i / 3]);

				}
			}

			if (i % 2 == 0) {
				if (dp[i / 2] == 0) {
					dp[i / 2] = dp[i] + 1;
				}
				else {
					dp[i / 2] = min(dp[i] + 1, dp[i / 2]);

				}
			}

			if (dp[i - 1] == 0) {
				dp[i - 1] = dp[i] + 1;
			}
			else {
				dp[i - 1] = min(dp[i] + 1, dp[i - 1]);
			}
		}
	}


	cout << dp[1] - 1 << endl;

	return 0;
}