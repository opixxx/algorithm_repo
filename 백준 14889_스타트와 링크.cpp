#include <iostream>
#include <climits>
#include <algorithm>
#include <vector>

using namespace std;

int stats[21][21] = { 0 };
int start[21][21] = { 0 };
int link[21][21] = { 0 };
int ans = INT_MAX;

void mCn(int visited[], int m, int n, int a, int b)
{
	int s = 0;
	int l = 0;
	
	if (b > n) { return; }
	if (b == n) {

		for (int i = 1; i <= m; i++) {
			for (int j = i + 1; j <= m; j++) {
				if (visited[i] && visited[j]) { s += start[i][j]; }
				else if (!visited[i] && !visited[j]) { l += link[i][j]; }
			}
		}

		ans = min(ans, abs(s - l));
	}

	for (int i = a; i <= m; i++) {
		visited[i] = 1;
		mCn(visited, m, n, i + 1, b + 1);
		visited[i] = 0;
	}
}

int main() 
{
	int n;
	int visited[21] = { 0 };

	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> stats[i][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			start[i][j] = stats[i][j] + stats[j][i];
			link[i][j] = stats[i][j] + stats[j][i];
		}
	}

	mCn(visited, n, n / 2, 1, 0);

	cout << ans;
}