#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int n, start, end, answer = 0, max_time = 0;
	vector<pair<int, int>> v;
	queue<pair<int, int>> q;
	priority_queue<int> pq;
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> start >> end;
		v.push_back({ start, start + end });
		max_time = max(max_time, start + end + 1);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) {
		q.push({ v[i].first, v[i].second });
	}
	for (int i = 0; i <= max_time; i++) {
		while (q.size() && i == q.front().first) {
			int start_time = q.front().first;
			int end_time = q.front().second;

			pq.push(-end_time);
			q.pop();
		}
		while (pq.size() && i == -pq.top()) {
			pq.pop();
		}

		int s = pq.size();

		answer = max(answer, s);
	}

	cout << answer;
}