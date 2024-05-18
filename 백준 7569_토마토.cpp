#include <iostream>
#include <queue>

using namespace std;

int answer = 0;

int tomato[101][101][101] = { 0 };
queue<pair<int, int>> q;
queue<pair<int, int>> start;

int move1[6] = { 1, -1, 0, 0, 0, 0 };
int move2[6] = { 0, 0, 1, -1, 0, 0 };
int move3[6] = { 0, 0, 0, 0, 1, -1 };

int isFinished(int n, int m, int h)
{
	for (int z = 0; z < h; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				if (tomato[z][y][x] == -1) continue;
				if (tomato[z][y][x] > 0) {
					answer = max(answer, tomato[z][y][x]);
				}
				else {
					return false;
				}
			}
		}
	}

	return true;
}

int main()
{
	int n, m, h;

	cin >> n >> m >> h;

	for (int z = 0; z < h; z++) {
		for (int y = 0; y < m; y++) {
			for (int x = 0; x < n; x++) {
				cin >> tomato[z][y][x];
				if (tomato[z][y][x] == 1) start.push({ 10000 * z + 100 * y + x, 0 });
			}
		}
	}

	while (start.size()) {
		q.push({ start.front().first, start.front().second });
		start.pop();
	}

	if (isFinished(n, m, h)) {
		cout << 0;

		return 0;
	}

	while (q.size()) {
		int raw = q.front().first;
		int start_z = raw / 10000;
		int start_y = (raw % 10000) / 100;
		int start_x = (raw % 100);
		int day = q.front().second;

		q.pop();
		for (int i = 0; i < 6; i++) {
			int dz = start_z + move3[i];
			int dy = start_y + move2[i];
			int dx = start_x + move1[i];
			int dday = day + 1;
			
			if (dz >= h) continue;
			if (dz < 0 || dy < 0 || dx < 0 || dz >= h || dy >= m || dx >= n) continue;
			if (tomato[dz][dy][dx] > dday || tomato[dz][dy][dx] == -1) continue;
			if (tomato[dz][dy][dx] == 0) {
				tomato[dz][dy][dx] = dday;
				q.push({ dz * 10000 + dy * 100 + dx, dday });
			}
		}
	}

	int finished = isFinished(n, m, h);

	if (finished) {
		cout << answer;
	}
	else {
		cout << -1;
	}
}