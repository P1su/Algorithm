#include <bits/stdc++.h> 
using namespace std;

int N, K;
int A[5], R[4][5], M[4][5], ans = 0;

void BackTracking(int day, int flavor) {
	
	//K일이면 최대값 비교후 갱신
	if (day == K) {
		ans = max(ans, flavor);
		return;
	}

	//완전탐색+백트래킹
	for (int i = 0; i < N; i++) {
		//랑이부터
		//i번째 캔이 있다면 랑이 먼저 사용, 없다면 다음 날로
		if (A[i] > 0) {
			A[i] --;
		}
		else continue;

		for (int j = 0; j < N; j++) {
			//i번째 캔이 있다면 메리 사용
			if (A[j] > 0) {
				A[j] --;

				//만족도 구한 후 다음 날로 넘어간다 
				BackTracking(day + 1, flavor + R[day][i] + M[day][j]);
				
			}
			else continue;

			//백트래킹 끝난 후 돌아오면 다시 캔의 수를 복원
			A[j]++;

		}
		//마찬가지로 캔 복원
		A[i] ++;
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> R[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		for (int j = 0; j < N; j++) {
			cin >> M[i][j];
		}
	}

	BackTracking(0, 0);
	cout << ans;
} 