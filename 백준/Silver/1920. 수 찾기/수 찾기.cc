#include <bits/stdc++.h> 
using namespace std;
#define MAX 100001

int arr[MAX];
int N, M;

void BinarySearch(int num) {
	int st = 0, en = N - 1;

	while (st <= en) {
		int mid = (st + en) / 2;

		if (arr[mid] == num) {
			cout << 1 << '\n';
			return ;
		}
		else if (arr[mid] < num) {
			st = mid + 1;
		}
		else {
			en= mid - 1;
		}
	}
	cout << 0 << '\n';
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int x;
		cin >> x;

		BinarySearch(x);
	}
} 