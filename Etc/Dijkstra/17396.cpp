#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
///////////////////////////////////////////
const int MAX_N = 100005;
const int MAX_M = 300005;
const long long INF = LLONG_MAX;
int N, M;
vector <int> a(MAX_N, INF);
vector<pair<int, int>> Edges[MAX_M];
vector<long long> dist(MAX_N, INF);
priority_queue<pair<long long, long long>> pq;
///////////////////////////////////////////
void Dijkstra(int start) {
	dist[start] = 0;
	for (auto e : Edges[start])
		if (dist[e.first] == INF) pq.push({ -e.second, e.first });
	while (!pq.empty()) {
		long long now, nowdist;
		nowdist = -pq.top().first;
		now = pq.top().second;
		pq.pop();

		if (dist[now] != INF) continue;

		dist[now] = nowdist;

		for (auto e : Edges[now])
			if (dist[e.first] == INF)
				pq.push({ -(nowdist + e.second), e.first });
	}
}
////////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 0; n < N; n++) cin >> a[n];
	for (int m = 1; m <= M; m++) {
		int d, e, f;
		cin >> d >> e >> f;
		if (a[d] != 1 && a[e] != 1) {
			Edges[d].push_back({ e,f });
			Edges[e].push_back({ d,f });
		}
		else if (d == N - 1 || e == N - 1) {
			Edges[d].push_back({ e,f });
			Edges[e].push_back({ d,f });
		}
	}
	Dijkstra(0);
	if (dist[N - 1] == INF) cout << "-1";
	else cout << dist[N - 1];
	return 0;
}