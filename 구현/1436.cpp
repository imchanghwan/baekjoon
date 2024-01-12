#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
문제 풀이 아이디어

가장 작은 종말의 수는 666이므로 숫자 666부터 1씩 증가시키면서 이 숫자가 종말의 수인지 체크한다.
그리고 종말의 수가 맞다면 횟수를 세어 N과 비교하여 일치하면 그 숫자가 N번째 영화 제목에 들어간 수가된다.

구현 방법은 loop를 돌려 숫자를 문자열로 바꾸어서 문자열 "666"이 포함되어 있는지 검사한다.
loop 탈출 조건은 몇번째 종말의 수인지 세어 N과 일치하면 종료된다.
그리고 1씩 증가하던 숫자를 출력하면 된다.


시간복잡도
666부터 1씩 증가하는 loop에서 다음 수 1,666까지 증가하려면 1,666-666=1,000 천번 loop를 돌면 두번째 수가 나온다. 이 경우의 수가 N과 N+1번째 사이에서 걸릴 수 있는 가장 오래 걸리는 시간이다.
왜냐하면 5,666에서 다음 종말의 수는 6,666이 아니라 6,660이기 때문이다. 6,660-5,666=994로 천보다 작게 나온다. 종말의 수가 커지면 커질 수록 이런 형태의 다음 종말의 수의 걸리는 시간은 더 줄어든다.
N의 최대값인 10,000이고 가장 오래 걸리는 시간은 10,000 * 1,000 = 10^7 천만이다.
그리고 실제로 N의 최대값 10,000일때 종말의 수는 2,666,799이다. 문자열을 찾는 시간복잡도를 생각해봤을 때 find 함수는 시간복잡도가 O(N)이다. 
최대 종말의 수를 문자열로 변환하면 문자열의 최대 길이는 7밖에 안된다.
그래서 loop를 돌려 시간이 어느정도 걸릴지 계산해보면
7*10^7 < 10^8 이므로 이 문제의 시간 제한 2초보다 작다. 시간 복잡도를 빅-오 표기법으로 하면 O(N^2) 일거 같다.
*/

int n; // n번째 영화 제목

int main()
{
	cin >> n;

	int count = 0; // loop에서 "666"이 들어가면 횟수를 세는 변수
	int result = 666; // 결과 변수 666부터 시작하면 더 빠르게 검사할 수 있음
	while (true)
	{
		if (count == n) break; // "666"이 들어가면 횟수를 세어 n이 되면 loop 종료
		string str = to_string(result); // 숫자를 문자열로 변환
		if (str.find("666") != string::npos) { // 변환한 문자열에 "666"이 있는지 검사
			count++; // true -> count를 1증가시켜 "666"이 들어간 숫자를 셈
		}
		result++; // loop를 돌때마다 1씩 증가
	}

	cout << result - 1 << endl; // 출력 loop마지막에 1씩 증가하고 종료되기 때문에 1을 빼줌
}
