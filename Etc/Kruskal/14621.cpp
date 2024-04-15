#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<climits>
#include<queue>
#include<string>
#include<cstring>
#include<algorithm>
#include<tuple>
using namespace std;
//////////////////////////////////////////
int N, M;
const int MAX_N = 1010;
const int MAX_M = 10010;
int answer;
int cnt;
vector <int> parent(MAX_N, 0);
priority_queue <tuple<int, int, int>> Edges;
vector <int> mw(MAX_N, 0);
//////////////////////////////////////////
int FIND(int node) {
	if (node == parent[node]) return node;
	return parent[node] = FIND(parent[node]);
}
///////////////////////////////////////////
void UNION(int node_a, int node_b) {
	int root_a = FIND(node_a);
	int root_b = FIND(node_b);

	parent[root_b] = root_a;
}
////////////////////////////////////////////
void Kruskal(void) {
	int weight;
	int a, b;
	while (!Edges.empty()) {
		a = get<1>(Edges.top());
		b = get<2>(Edges.top());
		weight = -get<0>(Edges.top());
		Edges.pop();
		if (FIND(a) != FIND(b)) {
			UNION(a, b);
			answer += weight;
			cnt++;
		}
	}
}
////////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	char t;
	int a, b, c;
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 1; n <= N; n++) parent[n] = n;
	for (int n = 1; n <= N; n++) {
		cin >> t;
		if (t == 'M') mw[n] = 1;
		else mw[n] = 0;
	}
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		if (mw[a] + mw[b] == 1)
			Edges.push(make_tuple(-c, a, b));
	}
	Kruskal();
	if (cnt == N - 1)cout << answer;
	else cout << "-1";
	return 0;
}