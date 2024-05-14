#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
	int tc, n, k;

	cin >> tc;

	for (int t = 1; t <= tc; t++) {
		vector<int> candies;
		int m = INT_MAX;

		cin >> n >> k;
		for (int i = 0; i < n; i++) {
			int tmp;

			cin >> tmp;
			candies.push_back(tmp);
			sort(candies.begin(), candies.end());
		}

		for (int i = 0; i <= n - k; i++) {
			int answer = candies[i + k - 1] - candies[i];
			if (answer < m) {
				m = answer;
			}
		}

		cout << "#" << t << " " << m << "\n";
	}
}