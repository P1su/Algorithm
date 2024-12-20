#include <bits/stdc++.h> 
using namespace std;
#define MAX 300000

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	if (n == 0) {
		cout << 0;
		return 0;
	}
	int p = floor(n * 0.15 + 0.5);
	
	vector<int> arr;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		arr.push_back(x);
	}
	sort(arr.begin(), arr.end());

	double sum = 0;
	for (int i = p ; i < n - p; i++) {
		sum += arr[i];
	}
	int ans = floor(sum / (n - p * 2) + 0.5);
	cout << ans;
	
} 