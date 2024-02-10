#include <iostream>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
첫번째 집에서 빨,초,파에서 하나씩 다음 집의 빨초파 가격과 하나씩 더하는데
색깔이 겹치지 않은거만 더한다. 그리고 최소 가격만 저장하여 나간다.
마지막 배열에서 최솟값이 정답이 된다.

시간 복잡도
O(N)
N개의 집을 순차적으로 더하고
앞집 3개의 가격중 겹치지않게 2개만 검사한다.
1000*3*2=6000
*/

int n;
int arr[1000][3]; // 집마다 칠하는 비용
int dp[1000][3]; // 집마다 칠하는 비용의 최솟값의 합

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> arr[i][j];
		}
	}

	// 첫번째집 색깔별 가격
	for (int i = 0; i < 3; i++) dp[0][i] = arr[0][i];

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			for (int k = 0; k < 3; k++) {
				// 앞에 집과 색깔이 달라야함
				if (j != k) {
					// 앞에 집의 비용과 현재 집의 비용을 더함
					int min = dp[i - 1][j] + arr[i][k];

					// 최소값 합이 빈값이면 저장
					if (dp[i][k] == 0) dp[i][k] = min;

					// 전에 더했던 비용보다 더 작으면 최소비용만 더한다.
					else if (min < dp[i][k]) {
						dp[i][k] = min;
					}
				}
			}
		}
	}

	// 마지막 배열에서 최솟값이 모든 집을 칠하는 비용의 최솟값이 된다.
	cout << *min_element(dp[n - 1], dp[n - 1] + 3);
	
}
