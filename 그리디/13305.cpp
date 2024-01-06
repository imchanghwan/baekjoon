#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
문제 정리
시간의 범위는 0부터 2의 31제곱-1 이므로 범위가 2의 32제곱까지인 unsigned long int를 사용해야겠다
문제 해결 아이디어
회의가 가장 먼저 끝나고 시작 하는 회의를 연결하면 된다고 생각함. 시작 시간은 같아도 끝나는 시간이 더 빠른 회의를 우선적으로 선택
시작시간과 끝나는 시간이 겹쳐도 됨.

시간복잡도는 O(n) 이다.

문제 해결 아이디어
코드는 끝나는시간을 기준으로 오름차순 정렬해서
시작시간이 끝나는 시간보다 더 크거나 같은 시간을 비교 반복한다.
*/

// 문제 틀려서 반례를 생각 해보니 끝나는 시간이 같고 시작시간이 다를 경우에서 정렬이 입력 순서대로 되기때문에 시작시간도 같이 비교해야될거 같다.

/*
반례 테스트 케이스
2
10 10
1 10
*/

struct Meet { // 회의 시작시간과 끝나는 시간을 저장하는 구조체
	unsigned long int start;
	unsigned long int finish;
};

bool cmp(Meet &a, Meet &b) // sort함수의 구조체 정렬을 하기위한 비교함수
{
	if (a.finish != b.finish) return a.finish < b.finish;
	else return a.start < b.start;
}

int main()
{
	int n; // 10의 6제곱
	cin >> n;

	vector<Meet> I; // 회의 시작시간과 끝나는 시간을 저장할 구조체 벡터

	for (int i = 0; i < n; i++) {
		unsigned long int x, y;
		cin >> x >> y;
		I.push_back({ x, y }); // 구조체 벡터 초기화
	}

	sort(I.begin(), I.end(), cmp); // sort 함수 3번째 인자에는 bool을 리턴하는 함수를 넣고 구조체의 끝나는 시간을 비교하여 오름차순 정렬
	unsigned long int time; // 끝나는 시간을 저장할 임시 변수
	time = I[0].finish; // 오름차순 정렬된 인덱스 0번째 끝나는 시간을 저장 (가장 빨리 끝나는 회의 시간이라서)
	int count = 1; // 회의 개수를 세는 변수 (회의 시간이 하나 포함되었기에 1로 초기화)

	for (int i = 1; i < n; i++) {
		if (time <= I[i].start) { // 끝나는 시간과 시작 시간을 비교한다. 시작 시간이 끝나는 시간보다 더 크거나 같아야 돼서
			time = I[i].finish; // 끝나는 시간을 임시 변수에 저장한다.
			count++; // 회의 개수
		}
	}

	cout << count << endl;
}
