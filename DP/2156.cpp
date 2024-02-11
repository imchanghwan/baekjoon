#include <iostream>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
계단 오르기 문제랑 매우 비슷해서
응용해서 푸는게 쉬울거 같다.
계단 오르기 문제는
n번째 계단을 오를 때 최대합을 dp 배열에 저장하는데
점화식이
dp[n] = arr[n] + arr[n-1] + dp[n-3]
dp[n] = arr[n] + dp[n-2]
이었다.
이번 문제는 마지막 포도주를 마실 필요가 없기에 점화식이 하나 더 추가된다.
dp[n] = dp[n-1]


시간 복잡도
O(N)
*/

int n;
int arr[10001]; // 포도주
int dp[10001]; // 포도주의 합

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	dp[3] = max(dp[2], dp[3]);

	for (int i = 4; i <= n; i++) {
		dp[i] = max(arr[i] + dp[i - 2], arr[i] + arr[i - 1] + dp[i - 3]);
		dp[i] = max(dp[i - 1], dp[i]);
	}
	
	cout << dp[n] << '\n';
}
