#include <iostream>

using namespace std;

int n;
int dp[1000001];

int tile(int n)
{
	// n이 2이하면 그대로 n 반환
	if (n <= 2) return n;
	
	// 크기가 n인 타일이 존재하면 n번째 배열을 그대로 반환
	if (dp[n] != 0) return dp[n] % 15746;

	// n번째 배열에 크기가 n인 타일 개수를 저장
	dp[n] = tile(n - 2) % 15746 + tile(n - 1) % 15746;

	return dp[n];

}

int main()
{
	cin >> n;
	cout << tile(n) % 15746 << '\n';
};
