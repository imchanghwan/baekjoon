#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
1부터 나무의 최댓값까지 이분탐색으로 절단기 높이의 최댓값을 구한다.
각 나무 높이보다 작은 절단기 높이라면 절단된 나무 길이를 총합에 저장하여
이분탐색으로 절단기 높이의 최댓값을 구한다.

시간 복잡도

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
