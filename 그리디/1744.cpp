#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 정리
n은 50보다 작은 자연수
수열의 수는 -1000부터 1000까지 범위의 정수
음수는 음수끼리 묶어서 양수로 만들어야 큰 수가 만들어 질거 같고
1은 어떤 수와도 묶을 수 없고 0은 음수랑 묶으면 된다.
가장 큰 수를 만들기 위해서는 가장 큰 수끼리 곱해야될거 같다.

문제 해결 아이디어
수열을 내림차순 정렬하여 가장 큰 양수끼리 곱하고,
오름차순 정렬하여 가장 작은 음수끼리 곱하고, 음수가 혼자 남았으면 그냥 더해준다.

시간 복잡도
O(n) 인거 같지만 n 범위가 50이라 O(1) 인거 같다..
*/

bool cmp(int& a, int& b) // 내림차순 정렬
{
	return a > b;
}

int main()
{
	int n;
	cin >> n;

	vector<int> seq; // 수열을 저장할 벡터

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		seq.push_back(x);
	}

	sort(seq.begin(), seq.end(), cmp); // 내림차순 정렬

	if (seq.size() % 2 == 1) seq.push_back(0); // 오버플로우 방지하기위해 떠오른 방법이 배열을 짝수로 만드는 거말곤 떠오르지 않았다...

	int res = 0; // 출력값 변수

	for (int i = 0; i < n; i++) {
		if (seq[i] > 1 && seq[i + 1] > 1) { // 1보다 큰 두 수 일경우 곱하고 출력값 변수에 더해준다.
			res += seq[i] * seq[i + 1];
			i++;
		}
		else if (seq[i] > 0) {
			res += seq[i];
		}
		else break;
	}

	if (seq[seq.size() - 1] == 0) seq.pop_back(); // 마지막 0이 들어갔으면 제거

	sort(seq.begin(), seq.end()); // 오름차순 정렬

	if (seq.size() % 2 == 1) seq.push_back(1); // 오버플로우 방지 양수 계산이 끝났으므로 상관없는 1을 넣어준다.

	for (int i = 0; i < seq.size(); i++) {
		if (seq[i] <= 0 && seq[i + 1] <= 0) { // 음수 수열은 0포함해서 묶어서 곱하면 양수 또는 0이 나온다.
			res += seq[i] * seq[i + 1];
			i++;
		}
		else if (seq[i] < 0) { // 홀로 남은 음수는 그냥 더한다.
			res += seq[i];
			break;
		}
		else break;
	}

	cout << res << endl;
}
