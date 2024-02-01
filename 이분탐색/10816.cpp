#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
순차 탐색시 시간복잡도가 오래 걸리므로 이분 탐색으로 푼다.
상근이가 가지고 있는 카드를 정렬한 배열을 이분탐색을 한다.
이분 탐색시 배열에서 카드를 제거하고 카드 개수를 세어 출력한다.
=> 시간초과 : 카드를 제거하고 다시 반복하게 되어 오래 걸리는거 같다

사실 이전에 풀어본 문제지만 배웠던 내용으로 풀어보려는데 계속 시간초과가 걸렸다.
lower_bound upper_bound 함수를 구현해봤다.
이분탐색을 최대한 활용하면 중복되는 수가 있는 정렬된 배열을
찾으려는 수가 처음 나오는 인덱스와 마지막으로 초과하는 인덱스를 빼서 카드의 개수를 구한다.

시간 복잡도
순차 탐색으로 풀이시 O(N*M) 25*10^8 약 25억 1초가 넘는다
이분 탐색시 O(M*logN) 5*10^4 * 4*log5 가 된다.
*/


int N, M;
vector<int> v; 

// 정렬된 배열에서 이분탐색으로 target이 처음 나오는 인덱스를 리턴하는 함수
int lower_bound(vector<int> &v, int target)
{
	int start = 0;
	int end = v.size();
	while (start < end) {
		int mid = (start + end) / 2;
		if (v[mid] < target) start = mid + 1;
		else  end = mid;
	}

	return end;
}

// 정렬된 배열에서 이분탐색으로 마지막 target을 초과하는 인덱스를 리턴하는 함수
int upper_bound(vector<int>& v, int target)
{
	int start = 0;
	int end = v.size();
	while (start < end) {
		int mid = (start + end) / 2;
		if (v[mid] <= target) start = mid + 1;
		else end = mid;
	}

	return end;
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	// 오름차순 정렬
	sort(v.begin(), v.end());

	cin >> M;
	for (int i = 0; i < M; i++) {
		int card;
		cin >> card;

		// 출력
		cout << upper_bound(v, card) - lower_bound(v, card) << ' ';
	}
}
