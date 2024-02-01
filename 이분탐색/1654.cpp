#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
랜선들을 내림차순 정렬한다.
최대 랜선길이를 찾기 위해 1부터 랜선최대값까지 이분탐색을 한다.
각 랜선 마다 이분탐색 mid값으로 나눈 값을 모두 더해서 만들어진 랜선의 총 개수를 구한다. 만드려는 랜선으로 각 랜선들을 나누면 랜선의 개수가 나온다.
만들어진 랜선의 총 개수가 N보다 작으면 end값을 줄이고
같거나 크면 결과값을 mid값으로 저장하고 start값을 올려 N개를 만들 수 있는 랜선의 최대 길이를 구한다.

시간 복잡도
이분탐색 O(logN) N=10^6, logN=6
랜선길이 순차탐색 O(K) K=10000
총 시간복잡도 O(KlogN) KlogN=60000
*/

int k, n;
vector<int> v;


int main()
{
	// 입력
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	int result = 0; // 출력값

	// 랜선의 최대 길이는 2^31-1 로 인트형 최댓값이고, mid값 계산중 오버플로우가 일어날 수 있다. unsigned int형은 int의 두배가 된다.
	int start = 1; // 최소 1
	int end = *max_element(v.begin(), v.end()); // 랜선 최대값

	// 만드려는 랜선의 최대 길이 이분탐색
	while (start <= end) {
		unsigned mid = (start + end) / 2;

		int count = 0;

		// 각랜선마다 만들 수 있는 랜선 개수 순차탐색
		for (int i = 0; i < k; i++) {
			count += v[i] / mid; // 랜선 개수
		}

		if (count < n) {
			end = mid - 1;
		}
		else {
			result = mid;
			start = mid + 1;
		}
	}

	// 출력
	cout << result << '\n';
}
