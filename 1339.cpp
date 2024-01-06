#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

/*
알파벳은 최대 10개, 수의 최대 길이는 8
문제 해결 아이디어
문자열이 가장 긴 문자열의 첫번째 문자를 9로 할당후
각 문자열의 길이를 비교해서 더 큰 문자열 부터 가장 높은 숫자를 할당

시간 복잡도 O(n^2)
근데 n이 1부터 10까지고 수의 최대길이가 8이니깐.. 올수 있는 케이스가 8*10개이다. 그러면 시간복잡도가 O(1) 인가..??

정답이 틀렸다..

반례를 찾아봤더니 틀린 이류를 알았지만 해결 방법이 잘 떠오르지 않는다.
이틀 고민 해본결과
n
AB
B
B
.
.
.

의 테스트 케이스이다. 수학적으로 접근 했을때 10*A + 1*B 와 (n-1)*B를 더했을 때 가장 큰 수가 나와야 하려면
A와 B의 계수를 중 큰 수로 내림차순 정렬해서 9부터 주면된다. 이 경우에는 10*A 와 n*1*B 이다. n이 10보다 작으면 A=9, B=8이지만
n이 10보다 크거나 같으면 B=9, A=8 된다.

문제 해결 아이디어
문자열을 입력받고 각 문자마다 자릿수를 저장한다.
*/


bool cmp(int& a, int& b) // 내림 차순 정렬 비교 함수
{
	return a > b;
}
int main()
{
	int n;
	cin >> n;

	string w = "ABCDEFGHIJKLNMOPQRSTUVWXYZ";
	vector<int> digit(w.length());

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++) { // 입력 받은 문자열 중 문자마다 자릿수를 저장한다.
			digit[w.find(str[j])] += pow(10, str.length() - j - 1); // find 함수는 인덱스를 리턴하고 겹치는 문자를 찾아서 자릿수를 더 해준다.
		}
	}

	sort(digit.begin(), digit.end(), cmp); // 내림 차순 정렬

	int res = 0; // 출력값 변수
	int num = 9;



	for (int i = 0; i < digit.size(); i++) {
		if (digit[i] != 0) {
			res += digit[i] * (num--); // 자릿수가 높은 순대로 9, 8, 7.. 곱해준다.
		}
	}

	cout << res << endl;
}
