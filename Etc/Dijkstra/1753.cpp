#include<iostream>
#include<queue>
#include<climits>
using namespace std;

int V, E;
int K;
int u, v, w;
const int INF = INT_MAX;
const int MAX_V = 20005;
vector<pair<int, int>> Edges[MAX_V];
vector<int> dist(MAX_V, INF);
priority_queue<pair<int, int>> pq;


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
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> V >> E;
	cin >> K;
	for (int e = 1; e <= E; e++) {
		cin >> u >> v >> w;
		Edges[u].push_back({ v,w });
	}
	Dijkstra(K);

	for (int v = 1; v <= V; v++) {
		if (dist[v] == INF) cout << "INF\n";
		else cout << dist[v] << '\n';
	}

	return 0;
}