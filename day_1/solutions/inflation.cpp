#include <bits/stdc++.h>
using namespace std;

int main() {
	vector<int> canisters;
	int n;
	cin >> n;
	for (int i = 0; i<n; i++) {
		int x;
		cin >> x;
		canisters.push_back(x);
	}

	sort(canisters.begin(), canisters.end());

	double min_ratio = 1;
	for (int i = 1; i<=n; i++) {
		double ratio = (double) (canisters[i - 1]) / i;
		if (ratio > 1.0) {
			cout << "impossible" << endl;
			return 0;
		} else if (ratio < min_ratio) {
			min_ratio = ratio;
		}
	}

	cout << min_ratio << endl;
}
