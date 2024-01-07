#include <iostream>
#include <vector>

using namespace std;

/*
문제 해결 아이디어
도시에서 출발 전 기름 가격과 다음 도시까지의 거리를 곱하면 다음 도시까지는 최소한의 비용으로 기름을 사서 갈 수 있다. 단, 이전 도시보다 싼 기름  가격이 나오고,
현재 도시의 기름 가격보다 싼 도시까지 (거리 만큼) 기름을 사서 간다.
현재 도시의 기름값과 다음 도시의 기름값을 비교하여 더 작은 쪽의 기름 값을 택하여 출력값에 거리 * 기름값을 더해준다.

시간복잡도
배열의 작은 수를 찾으면 되기 때문에 예상되는 시간 복잡도는 O(n)이다.

서브태스크 3번때문에 58점이 나와서 문제를 다시 생각해보니
거리랑 가격이 10의 9제곱이고 도시 개수가 10의 6제곱이다.
만약 도시 개수, 거리, 가격이 모두 최대라면
나올 수 있는 문제의 최소 비용은 10의 24제곱이 된다.
int 범위를 넘어가기에 long long int로 해주었다.
*/

int main()
{
	int n;
	cin >> n;
	vector<long long int> dis; // 도시 거리 벡터
	for (int i = 0; i < n - 1; i++) {
		long long int x;
		cin >> x;
		dis.push_back(x); // 벡터 초기화
	}
	vector<long long int> city_cost; // 도시당 기름 가격 벡터
	for (int i = 0; i < n; i++) { 
		long long int x;
		cin >> x;
		city_cost.push_back(x); // 벡터 초기화
	}

	long long int cost = 0; // 총 기름 값을 저장할 변수

	long long int temp = city_cost[0]; // 처음 도시 가격부터 다음으로 가장 작은 가격의 도시까지 비교할 임시 변수
	for (int i = 0; i < n - 1; i++) { // 마지막 도시의 가격은 상관없으므로 n-1번 반복
		if (city_cost[i] < temp) { // 인덱스 i 번째 도시부터 가장 가격이 싼 도시 찾기
			temp = city_cost[i];
		}
		cost += temp * dis[i]; // 가장 가격이 싼 도시의 기름 가격 * 다음으로 싼 도시까지 거리를 cost 변수에 계속 더해줌
	}

	cout << cost << endl; // 결과 출력
}
