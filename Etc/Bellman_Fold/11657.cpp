#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<climits>
using namespace std;

int N, M;
using ll = long long;
const ll INF = LLONG_MAX;

class Edge {
public:
	int from, to, weight;

	Edge(void) {
		from = 0;
		to = 0;
		weight = 0;
	}
	Edge(int u, int v, int w) {
		from = u;
		to = v;
		weight = w;
	}
	Edge(const Edge& edge) {
		from = edge.from;
		to = edge.to;
		weight = edge.weight;
	}
};

vector<Edge> Edges;
vector<ll> ShortPath;

bool Bellman_Fold(void) {
	ShortPath[1] = 0;
	for (int n = 1; n <= N - 1; n++) {
		for (int m = 0; m < M; m++) {
			auto e = Edges[m];
			if (ShortPath[e.from] == INF) continue;
			else if (ShortPath[e.to] > ShortPath[e.from] + e.weight)
				ShortPath[e.to] = ShortPath[e.from] + e.weight;
		}
	}
	bool ret = true;
	for (int m = 0; m < M; m++) {
		auto e = Edges[m];
		if (ShortPath[e.from] == INF) continue;
		else if (ShortPath[e.from] == -INF)
			ShortPath[e.to] = -INF;
		else if (ShortPath[e.to] > ShortPath[e.from] + e.weight) {
			ShortPath[e.to] = -INF;
			ret = false;
		}
	}
	return ret;
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
	cin >> N >> M;
	ShortPath.resize(N + 1, INF);
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		Edges.push_back(Edge(a, b, c));
	}
	if (Bellman_Fold()) {
		for (int n = 2; n <= N; n++) {
			if (ShortPath[n] == INF)
				cout << "-1\n";
			else
				cout << ShortPath[n] << '\n';
		}
	}
	else cout << "-1\n";
	return 0;
}
