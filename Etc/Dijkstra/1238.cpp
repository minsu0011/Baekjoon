#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int N, M, X;
const int INF = INT_MAX;
const int MAX_N = 1005;
vector<pair<int, int>> Edges[MAX_N];
vector<int> dist(MAX_N, INF);
priority_queue<pair<int, int>> pq;
int maxdist;
int d[1005];

void Dijkstra(int start) {
	dist[start] = 0;
	for (auto e : Edges[start])
		if (dist[e.first] == INF) pq.push({ -e.second, e.first });
	while (!pq.empty()) {
		int now, nowdist;
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

int main() {
	//파일입출력
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//입출력가속
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	int i = 1;
	cin >> N >> M >> X;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		Edges[a].push_back({ b,c });
	}
	Dijkstra(X);
	for (int n = 1; n <= N; n++) {
		d[n] = dist[n];
		dist[n] = INF;
	}

	for (int n = 1; n <= N; n++) {
		Dijkstra(n);
		maxdist = max(maxdist, dist[X] + d[n]);
		for (int n = 1; n <= N; n++)
			dist[n] = INF;
	}
	cout << maxdist;
	return 0;
}