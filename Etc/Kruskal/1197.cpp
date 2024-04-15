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
int V, E;
const int MAX_V = 10010;
const int MAX_E = 100010;
vector <int> parent(MAX_V, 0);
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
int Kruskal(void) {
	int answer = 0;
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
		}
	}
	return answer;
}
////////////////////////////////////////////
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int a, b, c;
	int ans;
	///////////////////////////////////////////
	cin >> V >> E;
	for (int v = 1; v <= V; v++) parent[v] = v;
	for (int e = 1; e <= E; e++) {
		cin >> a >> b >> c;
		Edges.push(make_tuple(-c, a, b));
	}
	ans = Kruskal();
	cout << ans;
	return 0;
}