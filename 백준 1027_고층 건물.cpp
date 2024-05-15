#include <iostream>
#include <algorithm>
#include <stack>
#include <climits>
#include <cmath>

using namespace std;

int main()
{
	int n;
	double arr[51] = { 0 };
	double gradient = INT_MAX;
	int answer = 0;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;

		gradient = INT_MAX;
		for (int j = i - 1; j >= 1; j--) {
			double tmp = (arr[i] - arr[j]) / (i - j);

			if (tmp < gradient) {
				gradient = tmp;
				cnt++;
			}
		}

		gradient = INT_MIN;
		for (int j = i + 1; j <= n; j++) {
			double tmp = (arr[j] - arr[i]) / (j - i);

			if (tmp > gradient) {
				gradient = tmp;
				cnt++;
			}
		}

		answer = max(answer, cnt);
	}

	cout << answer << "\n";
}