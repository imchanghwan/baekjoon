#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어
8시간 고민하다가 해설을 봤다..
집의 좌표를 오름차순 정렬
탐색범위를 인접한 공유기 거리로 하고
설치된 공유기 개수를 세어 탐색범위를 좁혀야겠다고 생각했는데
공유기 개수를 어떤 조건으로 세어야 되는지 도저히 모르겠다.

해설을 봐도 인접한 공유기 거리가 mid값보다 크거나 같아야하는지 이부분만 모르겠다.
시간 복잡도
이분탐색 O(logX) X는 집의 좌표, 최대일경우 X=10억 logX=9
집좌표 순차탐색 O(N) N은 집의 개수, 최대일경우 N=20만
O(NlogX) 최대 9*20만 = 180만
*/

int n, c;
vector<int> v;

int main()
{
	// 입력
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	sort(v.begin(), v.end());

	// 결과값
	int result = 0;

	// 탐색범위
	int start = 1; // 공유기 최소 거리
	int end = v[n - 1] - v[0]; // 공유기 최대 거리

	while (start <= end) {
		int mid = (start + end) / 2;

		int count = 1; // 공유기 개수
		int temp = v[0]; // 마지막으로 설치한 공유기 위치
		for (int i = 1; i < n; i++) {
			if (v[i] - temp >= mid) {
				count++;
				temp = v[i];
			}
		}
		if (count < c) end = mid - 1;
		else {
			start = mid + 1;
			result = mid;
		}
	}             
	// 출력
	cout << result << '\n';
}
