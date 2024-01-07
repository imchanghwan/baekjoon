#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <numeric>

using namespace std;

/*
문제 정리
n은 1~1000 범위

문제 해결 아이디어
오름차순 정렬해서 set으로 만들어 중복 값을 빼준다.
1부터 추의 최대 값인 모든 추의 합까지 반복하여 set에 있는지 찾는다. (연속되지 않은 값을 찾아서 추의 합으로 만들 수 있는지 확인한다.)
추의 무게 벡터를 내림차순으로 정렬하여 연속되지 않은 값(측정할 수 없는 무게의 최솟값)에서 추의 무게를 계속 빼다보면 측정 가능한 추의 무게면 입력받은 무게에서 찾을 수 있고
없다면 그것이 측정할 수 없는 최솟값이 된다.

예를들어 중복 제거시 1,2,3,6,7,30이 되고
1부터 최대 무게값까지 반복하면 연속되지 않은 수 4,5,8,9,10,11,...,21,22 등이 나온다.
방정식을 이용하여 4를 만들기 위해서 조합해야하는 수는
4=3+1 이다. 여기서 4-3=1 으로 만들어서 4를 만들기 위해서 뺄 수 있는 가장 큰 값으로 빼고 나온 값이 추 무게에 있다면 되는 것이다.
4-3=1

5-3=2

8-3=5
5-2=3
3-1=2

9-7=2
.
.
.
20-7=12
12-6=6
6-3=3
3-2=1

21-7=14
14-6=8
8-3=5
5-2=3
3-1=2
2-1=1
21에서 사용 할 수 있는 추를 다써도 못만드는 합이므로 정답이 된다.

머릿속으로 생각하고 바로 코드로 옮기는거 까지는 됐으나 막상 글로 쓰니 설명이 미흡해졌다..

시간복잡도
내가 생각한 방식으로 풀면 O(n^2)인데
O(n^2)이면 시간 초과가 뜨지 않을까 싶다...

시간 초과가 떴다...
*/

int main()
{
	int n;
	cin >> n;

	vector<int> weight; // 추의 무게를 저장하는 벡터

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		weight.push_back(x);
	}

	sort(weight.begin(), weight.end()); // 오름차순 정렬
	int max = accumulate(weight.begin(), weight.end(), 0); // 추의 무게 합 (측정 할 수 있는 가장 큰 추의 무게)
	set<int> s(weight.begin(), weight.end()); // 추의 무게 중복 제거

	//for (set<int>::iterator iter = s.begin(); iter != s.end(); iter++) {
	//	cout << *iter << " ";
	//}
	sort(weight.begin(), weight.end(), [](int a, int b) -> bool { return a > b; }); // 람다 함수를 사용하여 내림차순 정렬

	for (int i = 1; i < max / 2 + 1; i++) { // 무게 1부터 최대 무게까지 반복 
		// 연속되지 않은 무게 찾기
		set<int>::iterator iter = s.find(i);
		if (iter == s.end()) {

			int asw = i;
			vector<int> v(weight);

			for (int j = 0; j < n; j++) {
				if (find(v.begin(), v.end(), asw) != v.end()) break;
				if (weight[j] < asw) {
					asw -= weight[j];
					v[j] = 0;
				}
			}
			if (find(v.begin(), v.end(), asw) == v.end()) {
				cout << i << endl;
				exit(0);
			}
		}
	}
}
