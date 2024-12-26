#include <bits/stdc++.h> 
#define MAX 50001
using namespace std;

int DP[MAX];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N;
	cin >> N;

	int powNum = 1;
	DP[0] = 0;
	DP[1] = 1;
	for (int i = 2; i <= N; i++) {
		//모든 제곱수를 고려,,,
		DP[i] = DP[i - 1] + 1;
		for (int j = 1; j * j <= i; j++) {
			DP[i] = min(DP[i], DP[i - j * j] + 1);
		}
	}
	cout << DP[N];
} 