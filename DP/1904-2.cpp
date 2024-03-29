#include <iostream>

using namespace std;

int n;
int dp[1000001];

int main()
{
	cin >> n;

	dp[1] = 1;
	dp[2] = 2;

	for (int i = 3; i <= n; i++) {
		dp[i] = dp[i - 2] % 15746 + dp[i - 1] % 15746;
	}

	cout << dp[n] % 15746 << '\n';
};
