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
int N, M;
const int MAX_N = 1000010;
const int MAX_M = 5010;
vector <int> parent(MAX_N, 0);
vector <pair<int, int>> xy;
int cnt;
//////////////////////////////////////////
int FIND(int node) {
	if (node == parent[node]) return node;
	return parent[node] = FIND(parent[node]);
}
///////////////////////////////////////////
void UNION(int node_a, int node_b) {
	int root_a = FIND(node_a);
	int root_b = FIND(node_b);

	for (int i = root_a; i != root_b; i = FIND(i + 1)) {
		parent[i] = root_b;
		cnt++;
	}
}
////////////////////////////////////////////
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int x, y;
	int a;
	int tmp;
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 1; n <= N; n++) parent[n] = n;
	for (int m = 1; m <= M; m++) {
		cin >> x >> y;
		UNION(x, y);
	}
	cout << N - cnt;
	return 0;
}