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
const int MAX_N = 205;
const int MAX_M = 1005;
vector <int> parent(MAX_N, 0);
vector <int> visit;
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
int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int fincnt = 0;
	int a, b, c;
	int t;
	int ret = 1;
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 1; n <= N; n++) parent[n] = n;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> t;
			if (t == 1)
				UNION(i, j);
		}
	}
	for (int m = 1; m <= M; m++) {
		cin >> t;
		visit.push_back(FIND(t));
	}
	for (int m = 0; m < M; m++) {
		t = visit[0];
		if (t != visit[m]) ret = 0;
	}
	if (ret) cout << "YES";
	else cout << "NO";
	return 0;
}