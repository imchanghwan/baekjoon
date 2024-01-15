#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 풀이 아이디어 

높이가 큰 순으로 정렬

n*m에서 최소 높이부터 최대높이까지 h 반복
높이가 h보다 크면 블럭 제거, 인벤토리 블럭 수 증가, 소요시간=2초 * (높이 - h)
높이가 h보다 작으면 블럭 설치, 인벤토리 블럭 수 감소, 소요시간=1초 * (h - 높이)
인벤토리 블럭 수 가 적으면 종료

시간 복잡도
n*m 최대는 500*500 = 25만
정렬함수 sort는 NlogN
최소 높이부터 최대높이까지 다 있으면 256 * 500 * 500 = 6.4*10^6 < 10^8 이다. 
N+NlogN는 O(NlogN)이다.
*/

int n, m, b; // i,j 좌표, 인벤토리 블럭 수
vector<int> v; // 땅 높이

int main()
{
	cin >> n >> m >> b;

	int count = 0;
	for (int i = 0; i < n * m; i++) {
		int x;
		cin >> x;
		v.push_back(x);
	}
	vector<pair<int,int>> res; // 소요 시간, 땅 높이

	// 내림차순 정렬해 블럭 높이가 큰 순부터
	sort(v.begin(), v.end(), greater<int>());

	int max = v[0];
	int min = v[n * m - 1];

	for (int h = min; h <= max; h++) {
		int inventory = b;
		int sec = 0;
		for (int i = 0; i < n * m; i++) {
			// 인벤토리 블럭을 모두 사용하면 종료
			if (inventory < 0) {
				break;
			}
			// 높은 블럭부터 부셔서 인벤토리에 블럭을 얻는다.
			if (v[i] > h) {
				sec += 2 * (v[i] - h);
				inventory += v[i] - h;
			}
			// 쌓아야될 높이까지 낮으면 블럭을 쌓는다.
			else if (v[i] < h) {
				sec += h - v[i];
				inventory -= h - v[i];
			}
		}
		if (inventory >= 0)렬 
	sort(res.begin(), res.end(), [](pair<int, int>a, pair<int, int>b) { return a.first == b.first ? a.second > b.second : a.first < b.first; });

	cout << res[0].first << " " << res[0].second << endl;
}
