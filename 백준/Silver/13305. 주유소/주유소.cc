#include <bits/stdc++.h> 
using namespace std;

int N;
int W[100000], V[100000];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, cnt = 0, price, ans = 0;
	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		cin >> W[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> V[i];
	}

	price = V[0];

	for (int i = 0; i < N ; i++) {
		cnt += W[i];
		//cout << i << " " << cnt << " " << price << endl;
		if (V[i + 1] <= price) {
			ans += cnt * price;
			cnt = 0;
			price = V[i + 1];
		}
		else {
			i++;
			cnt += W[i];
		}
	}

	cout << ans;
} 