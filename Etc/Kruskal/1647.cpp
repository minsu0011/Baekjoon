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
int answer;
int max_weight;
const int MAX_N = 100010;
const int MAX_M = 1000010;
vector <int> parent(MAX_N, 0);
priority_queue <tuple<int, int, int>> Edges;
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
			max_weight = max(max_weight, weight);
			answer += weight;
		}
	}
}
////////////////////////////////////////////
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	int sm = 0;
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 1; n <= N; n++) parent[n] = n;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		Edges.push(make_tuple(-c, a, b));
	}
	Kruskal();
	cout << answer - max_weight;
	return 0;
}