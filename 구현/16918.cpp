#include <iostream>
#include <vector>

using namespace std;

/*
문제 풀이 아이디어

시간이 1초일 때는 그대로 출력
시간이 짝수일 경우 모든 칸이 폭탄으로 채워 출력
3이상의 홀수일 경우에
폭탄이 터지기 2초전의 격자판 상태를 저장하고
모든 칸이 폭탄인 격자판에서 2초전의 격자판 상태에서 터진 후의 격자판 상태를 출력

n이 3초후일 때는 3-2초의 격자판 상태를 저장
n이 5초후일 때는 5-2초의 격자판 상태
.
.
.
n-2초의 격자판 상태를 저장

폭탄이 3초후 터진후 빈칸은 모두 문자'O'인 폭탄으로된 격자판에서
(i,j)에 폭탄이 있으면
(i,j),(i-1,j),(i,j-1),(i+1,j),(i,j+1) 칸을 문자 '.' 빈칸으로 만든다. 

시간복잡도 O(N^3)
R*C*N 최대 2^3*10*6 = 800만 < 1억
1초도 안걸림
*/

int r, c, n;
vector<string> v; // 초기 폭탄 위치

/*
2초전의 폭탄이 있는 위치를 넣으면 3초후 폭탄이 터진 후 격자판 상를 반환하는 함수
v는 2초전의 폭탄 위치
*/
vector<string> boom(vector<string> &v)
{
	// 모든 칸이이 폭탄인 격자판 상태
	string str(c, 'O');
	vector<string> res(r, str);

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (v[i][j] == 'O') { // 해당 위치가 폭탄일 경우
				res[i][j] = '.'; // 폭탄이 있던 위치
				if (i - 1 >= 0) { // 폭탄이 있는 위치 y-1(위) 0이상이어야 함
					res[i - 1][j] = '.';
				}
				if (j - 1 >= 0) { // 폭탄이 있는 위치 x-1(좌) 0이상이어야 함
					res[i][j - 1] = '.';
				}
				if (i + 1 < r) { // 폭탄이 있는 위치 y+1(아래) r보다 작아 함
					res[i + 1][j] = '.';
				}
				if (j + 1 < c) { // 폭탄이 있는 위치 x+1(우) c보다 작아 함
					res[i][j + 1] = '.';
				}
			}
		}
	}
	return res;
}

int main()
{
	cin >> r >> c >> n;
	for (int i = 0; i < r; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// 모든 칸이 폭탄인 격자판 상태
	string str(c, 'O');
	vector<string> res(r, str); // 2초후 폭탄 위치이자 출력값 변수

	if (n == 1) res = v; // 1초일때는 초기 폭탄위치와 같음
	else if (n % 2 == 0) res = res; // 시간이 짝수일 때는 항상 모든칸이 폭탄
	else { // 3초이상 홀수만 폭탄이 터짐
		for (int i = 3; i <= n; i++) {
			if (i % 2 == 0) { // 현재 시간이 짝수면 n-2초의 격자판 상태를 v에 저장
				v = res;
			}
			else { // 현재 시간이 홀수라면 2초전에 저장한 위치의 폭탄이 터진 후 격자판 상태를를 res에 저장
				res = boom(v);
			}
		}
	}
	
	// 결과값 출력
	for (int i = 0; i < r; i++) {
		cout << res[i] << endl;
	}
}
