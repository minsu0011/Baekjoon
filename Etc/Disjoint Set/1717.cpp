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
const int MAX_N = 1000005;
const int MAX_M = 100005;
vector <pair<int, int>> fin;
vector <int> parent(MAX_N, 0);
vector <int> check;
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
	///////////////////////////////////////////
	cin >> N >> M;
	for (int n = 1; n <= N; n++)
		parent[n] = n;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b >> c;
		if (a == 0)
			UNION(b, c);
		else if (a == 1) {
			if (FIND(b) == FIND(c))
				check.push_back(1);
			else
				check.push_back(0);
		}
	}
	for (int i = 0; i < check.size(); i++) {
		if (check[i] == 1) cout << "YES" << '\n';
		else cout << "NO" << '\n';
	}
	return 0;
}