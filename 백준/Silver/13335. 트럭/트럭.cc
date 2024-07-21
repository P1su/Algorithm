#include <bits/stdc++.h> 
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, w, L, sum = 0, ans = 0, arr[1001];
	cin >> n >> w >> L;

	queue<int> Q;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {

		while (1) {
			if (Q.size() == w) {
				sum -= Q.front();
				Q.pop();
			}
			if (arr[i] + sum <= L) {
				break;
			}
			Q.push(0);
			ans++;
		}

		Q.push(arr[i]);
		sum += arr[i];
		ans++;
	}
	cout << ans + w;
} 