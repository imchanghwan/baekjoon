#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
탐색범위는 절단기의 최소 높이 1부터 최대 나무보다 큰 절단기 높이는 의미가 없으므로 나무 높이까지 탐색범위를 잡습니다.

각 나무들 마다 절단기 높이보다 크면 절단된 나무 길이를 더해 저장합니다.

절단된 나무 총합 길이가 M미터 나무보다 작으면 탐색범위 끝값을 줄이고,
크거나 같으면 탐색범위 시작값을 줄이고 최댓값으로 저장한다.

시간 복잡도
절단기 높이 이분탐색 O(logK) K는 나무 최대 길이 (1<=K<=10억) logK=9
각 나무 길이 순차탐색 O(N) N은 나무의 수 (1<=N<=100만)
O(NlogK) 최대 900만이다.
*/

int n, m;
vector<int> v;


int main()
{
	// 입력
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 결과값
	int result = 0;

	int start = 1;
	int end = *max_element(v.begin(), v.end());

	while (start <= end) {
		int mid = (start + end) / 2;
		// 각 나무의 최댓값은 10억고 m=1 이라면, 10^6*10^9=10^15 이므로 int형은 오버플로우가 난다. 
		long long total = 0; // 32비트 환경이면 unsinged long랑 unsigned int는 같을텐데 unsigned int는 틀렸다고 나온다.

		// 각 나무보다 작은 절단기 높이면 절단된 나무 길이를 저장한다.
		for (int i = 0; i < n; i++) {
			if (v[i] > mid) total += v[i] - mid;
		}

		// 절단된 나무의 길이의 합이 가져가려는 나무 길이보다 작으면 절단기 높이를 줄여야 된다.
		if (total < m) end = mid - 1;
		// 같거나 크면 절단기 높이를 키우고 최댓값을 저장한다.
		else {
			result = mid;
			start = mid + 1;
		}
	}
	
	// 출력
	cout << result << '\n';
}
